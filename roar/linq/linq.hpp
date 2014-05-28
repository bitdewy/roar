// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#ifndef ROAR_LINQ_LINQ_HPP
#define ROAR_LINQ_LINQ_HPP

#include <algorithm>

#include "boost/optional.hpp"
#include "cursor.hpp"
#include "iterator.hpp"
#include "select.hpp"

namespace roar {
  namespace linq {

    template <typename Collection>
    class linq_query {
      typedef typename Collection::cursor::element_type element_type;
      typedef typename Collection::cursor::reference_type reference_type;
    public:
      typedef linq_iterator<typename Collection::cursor> iterator;
      // no explicit, support implicit cast
      template<typename U, typename std::enable_if<std::is_convertible<U, Collection>::value, int>::type = 0>
      linq_query(U&& c) : collection_(std::forward<U>(c)) {}

      iterator begin() const {
        return iterator(collection_.get_cursor());
      }

      iterator end() const {
        return iterator();
      }

      size_t count() const {
        return 0;
      }

      template<typename Pred>
      size_t count(Pred p) const {
        return 0;
      }

      bool any() const {
        return false;
      }

      template<typename Pred>
      bool any(Pred p) const {
        return false;
      }

      template<typename Pred>
      bool all(Pred p) const {
        return false;
      }

      bool empty() const {
        return !any();
      }

      bool contains(const element_type& value) const {
        return std::find(begin(), end(), value) != end();
      }

      template <class Selector>
      linq_query<linq_select<Collection, Selector>> select(Selector s) const {
        return linq_select<Collection, Selector>(collection_, std::move(s));
      }

    private:
      Collection collection_;
    };

    //non member function
    template <typename T>
    const linq_query<T>& from(const linq_query<T>& c) {
      return c;
    }
    template <typename Container>
    linq_query<iter_cursor<typename Container::iterator>> from(Container& c) {
      return from(std::begin(c), std::end(c));
    }

    template <typename Iter>
    linq_query<iter_cursor<Iter>> from(const Iter& begin, const Iter& end) {
      return iter_cursor<Iter>(begin, end);
    }
  }  // namespace linq
}  // namespace roar

#endif  // ROAR_LINQ_LINQ_HPP
