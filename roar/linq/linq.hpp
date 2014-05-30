// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#ifndef ROAR_LINQ_LINQ_HPP
#define ROAR_LINQ_LINQ_HPP

#include <algorithm>
#include <numeric>

#include "boost/optional.hpp"
#include "cursor.hpp"
#include "iterator.hpp"
#include "select.hpp"
#include "where.hpp"

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

      element_type sum() {
        return std::accumulate(begin(), end(), element_type());
      }

      element_type min() {
        return *std::min_element(begin(), end());
      }

      template <typename Selector>
      typename std::result_of<Selector(element_type)>::type min(Selector s) {
        auto r = select(std::move(s));
        return *std::min_element(std::begin(r), std::end(r));
      }

      element_type max() {
        return *std::max_element(begin(), end());
      }

      template <typename Selector>
      typename std::result_of<Selector(element_type)>::type max(Selector s) {
        auto r = select(std::move(s));
        return *std::max_element(std::begin(r), std::end(r));
      }

      typename std::iterator_traits<iterator>::difference_type count() const {
        return std::distance(begin(), end());
      }

      template<typename Pred>
      typename std::iterator_traits<iterator>::difference_type count(Pred p) const {
        return std::count_if(begin(), end(), p);
      }

      double average() const {
        assert(begin() != end());
        return std::accumulate(begin(), end(), .0) / count();
      }

      template <typename Selector>
      double average(Selector s) {
        auto r = select(std::move(s));
        assert(std::begin(r) != std::end(r));
        return std::accumulate(std::begin(r), std::end(r), .0) / r.count();
      }

      template <typename Functor>
      typename std::result_of<Functor(element_type, element_type)>::type aggregate(Functor f) {
        assert(begin() != end());
        return std::accumulate(++begin(), end(), *begin(), f);
      }

      bool any() const {
        return any([](element_type e) { return true; });
      }

      template<typename Pred>
      bool any(Pred p) const {
        return std::any_of(begin(), end(), p);
      }

      template<typename Pred>
      bool all(Pred p) const {
        return std::all_of(begin(), end(), p);
      }

      bool empty() const {
        return !any();
      }

      bool contains(const element_type& value) const {
        return std::find(begin(), end(), value) != end();
      }

      template<typename Container>
      bool sequence_equal(const Container& other) {
        return std::equal(begin(), end(), std::begin(other));
      }

      template <typename Selector>
      linq_query<linq_select<Collection, Selector>> select(Selector s) const {
        return linq_select<Collection, Selector>(collection_, std::move(s));
      }

      template <typename Predicate>
      linq_query<linq_where<Collection, Predicate>> where(Predicate p) const {
        return linq_where<Collection, Predicate>(collection_, std::move(p));
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
