// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#ifndef ROAR_LINQ_SELECT_HPP
#define ROAR_LINQ_SELECT_HPP

#include <type_traits>

namespace roar {
  namespace linq {
    template <typename Collection, typename Selector>
    class linq_select {
      typedef typename Collection::cursor inner_cursor;
    public:
      struct cursor {
        typedef typename std::result_of<Selector(typename inner_cursor::element_type)>::type reference_type;
        typedef typename std::remove_reference<reference_type>::type element_type;
        typedef typename inner_cursor::cursor_category cursor_category;
        typedef typename inner_cursor::difference_type difference_type;

        cursor() {}
        cursor(const inner_cursor& cur, Selector s) : cursor_(cur), selector_(std::move(s)) {}

        bool empty() const {
          return cursor_.empty();
        }

        void increase() {
          cursor_.increase();
        }

        void decrease() {
          cursor_.decrease();
        }

        void forget() {
          cursor_.forget();
        }

        reference_type get() const {
          return selector_(cursor_.get());
        }

      private:
        inner_cursor cursor_;
        Selector selector_;
      };

      linq_select(const Collection& c, Selector s) : collection_(c), selector_(std::move(s)) {}

      cursor get_cursor() const {
        return cursor(collection_.get_cursor(), selector_);
      }

    private:
      Collection collection_;
      Selector selector_;
    };
  }  // namespace linq
}  // namespace roar

#endif  // ROAR_LINQ_SELECT_HPP
