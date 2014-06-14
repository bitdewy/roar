// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#ifndef ROAR_LINQ_GROUPBY_HPP
#define ROAR_LINQ_GROUPBY_HPP

#include <list>
#include <map>
#include <memory>

namespace roar {
  namespace linq {
    template <typename Collection, typename KeyFn>
    class linq_groupby {
      typedef typename Collection::cursor inner_cursor;
      typedef typename std::result_of<KeyFn(typename inner_cursor::element_type)>::type key_type;
      typedef std::list<typename inner_cursor::element_type> element_list;

      struct group_type {
        typedef typename element_list::iterator iterator;
        iterator start;
        iterator fin;
        key_type key;

        iterator begin() const { return start; }
        iterator end() const { return fin; }

        template <typename Container>
        bool operator==(const Container& other) {
          return std::equal(start, fin, std::begin(other));
        }
      };

    public:
      struct cursor {
        typedef typename group_type reference_type;
        typedef typename std::remove_reference<reference_type>::type element_type;
        typedef typename inner_cursor::cursor_category cursor_category;

        cursor(inner_cursor cursor, KeyFn fn) {
          impl_.reset(new impl(cursor, fn));
          current_ = impl_->begin();
          end_ = impl_->end();
        }

        bool empty() const {
          return current_ == end_;
        }

        void increase() {
          ++current_;
        }

        void decrease() {
          --current_;
        }

        reference_type get() const {
          return *current_;
        }

      private:
        struct impl {
        public:
          impl(inner_cursor cursor, KeyFn fn) {
            while (!cursor.empty()) {
              insert(cursor.get(), fn);
              cursor.increase();
            }
          }

          typename std::list<group_type>::iterator begin() {
            return groups_.begin();
          }

          typename std::list<group_type>::iterator end() {
            return groups_.end();
          }

        private:
          void insert(const typename inner_cursor::element_type& e, KeyFn fn) {
            key_type key = fn(e);
            auto index = index_.find(key);
            if (index != index_.end()) {
              elements_.insert(index->second->end(), e);
            }
            else {
              elements_.push_back(e);
              if (!groups_.empty()) {
                --groups_.back().fin;
              }
              auto fin = elements_.end();
              auto start = fin;
              groups_.push_back({ --start, fin, key });
              index_.insert(std::make_pair(key, &groups_.back()));
            }
          }

          std::list<group_type> groups_;
          std::map<key_type, group_type*> index_;
          element_list elements_;
        };

        
        std::shared_ptr<impl> impl_;
        typename std::list<group_type>::iterator current_;
        typename std::list<group_type>::iterator end_;
      };

      linq_groupby(const Collection& c, KeyFn fn)
        : collection_(c), key_fn_(std::move(fn)) {}

      cursor get_cursor() const {
        return cursor(collection_.get_cursor(), key_fn_);
      }

    private:
      Collection collection_;
      KeyFn key_fn_;
    };
  }  // namespace linq
}  // namespace roar

#endif  // ROAR_LINQ_GROUPBY_HPP
