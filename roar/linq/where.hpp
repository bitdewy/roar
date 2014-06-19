// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#ifndef ROAR_LINQ_WHERE_HPP
#define ROAR_LINQ_WHERE_HPP

#include <type_traits>

namespace roar {
  namespace linq {
    template <typename Collection, typename Predicate>
    class linq_where {
      typedef typename Collection::cursor inner_cursor;
    public:
      struct cursor {
        typedef typename inner_cursor::element_type element_type;
        typedef typename inner_cursor::reference_type reference_type;
        typedef typename inner_cursor::cursor_category cursor_category;
        typedef typename inner_cursor::difference_type difference_type;

        cursor() {}
        cursor(const inner_cursor& cur, Predicate p)
          : cursor_(cur), pred_(std::move(p)) {
          if (!cursor_.empty() && !pred_(cursor_.get())) {
            increase();
          }
        }

        bool empty() const {
          return cursor_.empty();
        }

        void increase() {
          while (true) {
            cursor_.increase();
            if (empty() || pred_(cursor_.get())) {
              break;
            }
          }
        }

        void decrease() {
          while (true) {
            cursor_.decrease();
            if (empty() || pred_(cursor_.get())) {
              break;
            }
          }
        }

        void forget() {
          cursor_.forget();
        }

        reference_type get() const {
          return cursor_.get();
        }

      private:
        inner_cursor cursor_;
        Predicate pred_;
      };

      linq_where(const Collection& c, Predicate pred)
        : collection_(c), pred_(std::move(pred)) {}

      cursor get_cursor() const {
        return cursor(collection_.get_cursor(), pred_);
      }

    private:
      Collection collection_;
      Predicate pred_;
    };
  }  // namespace linq
}  // namespace roar

#endif  // ROAR_LINQ_WHERE_HPP
