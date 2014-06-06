// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#ifndef ROAR_LINQ_GROUPBY_HPP
#define ROAR_LINQ_GROUPBY_HPP

#include <list>
#include <map>

namespace roar {
  namespace linq {
    template <typename Collection, typename KeyFn>
    class linq_groupby {
      typedef typename Collection::cursor inner_cursor;
      typedef typename std::result_of<KeyFn(typename inner_cursor::element_type)>::type key_type;
      typedef std::list<typename inner_cursor::element_type> group_type;

    public:
      struct cursor {
      private:
        inner_cursor cursor_;
        std::map<key_type, group_type> groups_;
      };
    private:
      Collection collection_;
      KeyFn key_fn_;
    };
  }  // namespace linq
}  // namespace roar

#endif  // ROAR_LINQ_GROUPBY_HPP
