// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#ifndef ROAR_LINQ_CURSOR_HPP
#define ROAR_LINQ_CURSOR_HPP

#include <cassert>
#include <iterator>

namespace roar {
  namespace linq {
    template <typename Iterator>
    class iter_cursor {
    public:
      typedef iter_cursor cursor;
      typedef typename std::iterator_traits<Iterator>::value_type element_type;
      typedef typename std::iterator_traits<Iterator>::reference reference_type;
      typedef typename std::iterator_traits<Iterator>::iterator_category cursor_category;

      iter_cursor(const Iterator& start, const Iterator& end)
        : start_(start), end_(end), current_(start) {}

      bool empty() const {
        return current_ == end_;
      }
      reference_type get() const {
        return *current_;
      }

      void increase() {
        assert(("out of range", current_ != end_));
        ++current_;
      }

      void decrease() {
        assert(("out of range", current_ != start_));
        --current_;
      }

      cursor get_cursor() const {
        return *this;
      }

    private:
      Iterator start_;
      Iterator end_;
      Iterator current_;
    };
  }  // namespace linq
}  // namespace roar

#endif  // ROAR_LINQ_CURSOR_HPP
