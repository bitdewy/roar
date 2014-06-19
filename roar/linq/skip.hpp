// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#ifndef ROAR_LINQ_SKIP_HPP
#define ROAR_LINQ_SKIP_HPP


namespace roar {
  namespace linq {
    template <typename Collection>
    class linq_skip {
    public:
      typedef typename Collection::cursor cursor;

      linq_skip(const Collection& c, size_t n) : collection_(c), n_(n) {}

      cursor get_cursor() const {
        auto cur = collection_.get_cursor();
        auto n = n_;
        while (n-- && !cur.empty()) {
          cur.increase();
        }
        cur.forget();
        return std::move(cur);
      }

    private:
      Collection collection_;
      size_t n_;
    };
  }  // namespace linq
}  // namespace roar

#endif  // ROAR_LINQ_SELECT_HPP
