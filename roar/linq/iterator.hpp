// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#ifndef ROAR_LINQ_ITERATOR_HPP
#define ROAR_LINQ_ITERATOR_HPP

#include <iterator>

namespace roar {
  namespace linq {
    class default_iterator_operators {};

    template <typename Iter>
    typename std::enable_if<std::is_convertible<Iter, default_iterator_operators>::value, Iter>::type
    operator+(const Iter& it, typename std::iterator_traits<Iter>::distance_type n) {
      return it += n;
    }

    template <typename Iter>
    typename std::enable_if<std::is_convertible<Iter, default_iterator_operators>::value, Iter>::type
    operator-(const Iter& it, typename std::iterator_traits<Iter>::distance_type n) {
      return it -= n;
    }

    template <typename Iter>
    typename std::enable_if<std::is_convertible<Iter, default_iterator_operators>::value, Iter>::type
    operator-=(const Iter& it, typename std::iterator_traits<Iter>::distance_type n) {
      return it += (-n);
    }

    template <typename Iter>
    typename std::enable_if<std::is_convertible<Iter, default_iterator_operators>::value, bool>::type
    operator!=(const Iter& it, const Iter& it2) {
      return !(it == it2);
    }

    template <typename Iter>
    typename std::enable_if<std::is_convertible<Iter, default_iterator_operators>::value, bool>::type
    operator>(const Iter& it, const Iter& it2) {
      return it2 < it;
    }

    template <typename Iter>
    typename std::enable_if<std::is_convertible<Iter, default_iterator_operators>::value, bool>::type
    operator<=(const Iter& it, const Iter& it2) {
      return !(it2 < it);
    }

    template <typename Iter>
    typename std::enable_if<std::is_convertible<Iter, default_iterator_operators>::value, bool>::type
    operator>=(const Iter& it, const Iter& it2) {
      return !(it < it2);
    }

    template <typename Cursor>
    class linq_iterator {
    public:
      typedef typename std::forward_iterator_tag iterator_category;
      typedef typename Cursor::element_type value_type;
      typedef typename Cursor::reference_type reference;
      typedef ptrdiff_t difference_type;
      typedef typename std::add_pointer<typename Cursor::element_type>::type pointer;

      linq_iterator() {}

      template<typename U, typename std::enable_if<std::is_convertible<U, Cursor>::value, int>::type = 0>
      linq_iterator(U&& c) : cursor_(std::forward<U>(c)) {}

      operator roar::linq::default_iterator_operators() const {
        return roar::linq::default_iterator_operators();
      }

      reference operator*() const {
        return cursor_->get();
      }

      pointer operator->() const {
        auto& v = **this;
        return &v;
      }

      bool operator==(const linq_iterator& other) const {
        return !cursor_ && !other.cursor_;
      }

      linq_iterator& operator++() {
        cursor_->increase();
        if (cursor_->empty()) {
          cursor_.reset();
        }
        return *this;
      }

    private:
      boost::optional<Cursor> cursor_;
    };
  }  // namespace linq
}  // namespace roar

#endif // ROAR_LINQ_ITERATOR_HPP
