# roar

A C++11/14 LINQ Implemention

## Introduction

A C++11/14 LINQ Implemention for fun!
 
## Build Environment 

[Visual Studio 2013](http://www.visualstudio.com/) with [Visual C++ Compiler November 2013 CTP](http://aka.ms/Icp591)

## Dependencies 

[Boost.Optional](http://www.boost.org/doc/libs/1_55_0/libs/optional/doc/html/index.html)

[Microsoft::VisualStudio::CppUnitTestFramework](http://msdn.microsoft.com/en-us/library/hh598953.aspx)

## Examples

All examples are based on [101 LINQ Samples](http://code.msdn.microsoft.com/101-LINQ-Samples-3fb9811b/viewsamplepack)

### any

This sample uses Any to determine if any of the words in the array contain the substring 'ei'.

```cpp
std::vector<std::string> words{ "believe", "relief", "receipt", "field" };
bool i_after_e = roar::linq::from(words)
  .any([](const std::string& s) {
    return s.find("ie") != std::string::npos;
  });
```

This sample uses Any to return a grouped a list of products only for categories that have at least one product that is out of stock.

```cpp
struct product {
  std::string product_name;
  std::string category;
  std::size_t unit_price;
  bool operator==(const product& other) const {
    return product_name == other.product_name &&
      category == other.category &&
      unit_price == other.unit_price;
  }
};
std::list<product> products{
  { "iphone", "cellphone", 599 },
  { "nexus", "cellphone", 499 },
  { "galaxy", "cellphone", 499 },
  { "ipad", "pad", 299 },
  { "nexus7", "pad", 399 },
  { "galaxy", "pad", 499 }
};
auto group = roar::linq::from(products)
  .group_by([](const auto& p) { return p.category; })
  .where([](const auto& g) {
  return roar::linq::from(g).any([](const auto& i) {
    return i.unit_price < 399;
  });
});
```

### all

This sample uses All to determine whether an array contains only odd numbers.

```cpp
std::vector<int> numbers{ 1, 11, 3, 19, 41, 65, 19 };
bool only_odd = roar::linq::from(numbers).all([](int i) { return i % 2 == 1; });
```

This sample uses All to return a grouped a list of products only for categories that have all of their products in stock.

```cpp
struct product {
  std::string product_name;
  std::string category;
  std::size_t unit_price;
  bool operator==(const product& other) const {
    return product_name == other.product_name &&
      category == other.category &&
      unit_price == other.unit_price;
  }
};
std::list<product> products{
  { "iphone", "cellphone", 599 },
  { "nexus", "cellphone", 499 },
  { "galaxy", "cellphone", 499 },
  { "ipad", "pad", 299 },
  { "nexus7", "pad", 399 },
  { "galaxy", "pad", 499 }
};
auto group = roar::linq::from(products)
  .group_by([](const auto& p) { return p.category; })
  .where([](const auto& g) { 
    return roar::linq::from(g).all([](const auto& i) {
      return i.unit_price > 399;
    });
  });
```

### average

This sample uses Average to get the average of all numbers in an array.

```cpp
std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
auto average = roar::linq::from(numbers).average();
```

This sample uses Average to get the average length of the words in the array.

```cpp
std::vector<std::string> words{ "cherry", "apple", "blueberry" };
auto r = roar::linq::from(words).average([](const std::string& s) { return s.size(); });
```

This sample uses Average to get the average price of each category's products.

```cpp
struct product {
  std::string product_name;
  std::string category;
  std::size_t unit_price;
  bool operator==(const product& other) const {
    return product_name == other.product_name &&
      category == other.category &&
      unit_price == other.unit_price;
  }
};
std::list<product> products{
  { "iphone", "cellphone", 599 },
  { "nexus", "cellphone", 499 },
  { "galaxy", "cellphone", 699 },
  { "ipad", "pad", 299 },
  { "nexus7", "pad", 399 },
  { "galaxy", "pad", 499 }
};

using anonymous = struct dummy {
  std::string category;
  double average_price;
  bool operator==(const dummy& other) {
    return category == other.category && abs(average_price - other.average_price) < .00001;
  }
};

auto grouped = roar::linq::from(products)
  .group_by([](const auto& p) { return p.category; })
  .select([](const auto& g) -> anonymous {
    return { g.key, roar::linq::from(g).average([](const auto& i) { return i.unit_price; }) };
});
```

### aggregate

This sample uses Aggregate to create a running product on the array that calculates the total product of all elements.

``` cpp
std::vector<double> doubles{ 1.7, 2.3, 1.9, 4.1, 2.9 };
auto product = roar::linq::from(doubles)
  .aggregate([](double running, double next) { return running * next; });
```

### count

This sample uses Count to get the number of unique factors of 300.

```cpp
std::vector<int> factors_of_300{ 2, 2, 3, 5, 5 };
auto count = roar::linq::from(factors_of_300).count();
```

This sample uses Count to get the number of odd ints in the array.

```cpp
std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
auto r = roar::linq::from(numbers).count([](int i) { return i % 2 == 1; });
```

This sample uses Count to return a list of categories and how many products each has.

```cpp
struct product {
  std::string product_name;
  std::string category;
  std::size_t unit_price;
  bool operator==(const product& other) const {
    return product_name == other.product_name &&
      category == other.category &&
      unit_price == other.unit_price;
  }
};
std::list<product> products {
  { "iphone", "cellphone", 599 },
  { "nexus", "cellphone", 499 },
  { "galaxy", "cellphone", 499 },
  { "ipad", "pad", 299 },
  { "nexus7", "pad", 399 },
  { "galaxy", "pad", 499 }
};
using anonymous = struct dummy {
  std::string category;
  size_t count;
  bool operator==(const dummy& other) {
    return category == other.category && count == other.count;
  }
};
auto group = roar::linq::from(products)
  .group_by([](const auto& p) { return p.category; })
  .select([](const auto& g) -> anonymous {
    return { g.key, roar::linq::from(g).count() };
  });
```

### first

This sample uses First to return the first matching element as a Product, instead of as a sequence containing a Product.

```cpp
struct product {
  std::string name;
  std::size_t type;
};
std::list<product> l{
  { "nexus", 5 },
  { "iphone", 5 },
  { "galaxy", 5 },
  { "galaxy", 4 },
  { "iphone", 4 },
  { "nexus", 4 }
};
auto p = roar::linq::from(l)
  .where([](const product& p) { return p.type == 4; }).first();
```

This sample uses First to find the first element in the array that starts with 'o'.

```cpp
std::vector<std::string> strings{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
auto starts_with_o = roar::linq::from(strings)
  .first([](const std::string& s) { return s[0] == 'o'; });
```

This sample uses FirstOrDefault to try to return the first element of the sequence, unless there are no elements, in which case the default value for that type is returned.

```cpp
std::vector<int> numbers{};
int first_or_default = roar::linq::from(numbers).first_or_default();
```

### group_by

This sample uses group by to partition a list of numbers by their remainder when divided by 5.

```cpp
std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
auto numnbers_groups = roar::linq::from(numbers).group_by([](int i) { return i % 5; });
```

This sample uses group by to partition a list of words by their first letter.

```cpp
std::vector<std::string> words{ "blueberry", "chimpanzee", "abacus", "banana", "apple", "cheese" };
using anonymous = struct dummy {
  char key;
  std::list<std::string> words;
  bool operator==(const dummy& other) {
    return key == other.key && words == other.words;
  }
};
auto word_groups = roar::linq::from(words)
  .group_by([](const std::string& s) { return s[0]; })
  .select([](const auto& g) -> anonymous {
    std::list<std::string> words;
    std::for_each(std::begin(g), std::end(g), [&words](const auto& w) {
      words.push_back(w);
    });
    return { g.key, words };
  });
```

This sample uses group by to partition a list of products by category.

```cpp
struct product {
  std::string product_name;
  std::string category;
  std::size_t unit_price;
  bool operator==(const product& other) const {
    return product_name == other.product_name &&
      category == other.category &&
      unit_price == other.unit_price;
  }
};
std::list<product> products{
  { "iphone", "cellphone", 599 },
  { "nexus", "cellphone", 499 },
  { "galaxy", "cellphone", 499 },
  { "ipad", "pad", 299 },
  { "nexus7", "pad", 399 },
  { "galaxy", "pad", 499 }
};

using anonymous = struct dummy {
  std::string category;
  std::list<product> products;
  bool operator==(const dummy& other) {
    return category == other.category && products == other.products;
  }
};
std::list<product> grouped;
auto order_groups = roar::linq::from(products)
  .group_by([](const auto& p) { return p.category; })
  .select([&grouped](const auto& g) -> anonymous {
    grouped.clear();
    std::for_each(std::begin(g), std::end(g), [&grouped](const auto& p) {
      grouped.push_back(p);
    });
    return { g.key, grouped };
});
```

### max

This sample uses Max to get the highest number in an array.

```cpp
std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
auto r = roar::linq::from(numbers).max();
```

This sample uses Max to get the length of the longest word in an array.

```cpp
std::vector<std::string> words{ "cherry", "apple", "blueberry" };
auto shortest = roar::linq::from(words).max([](const std::string& w) { return w.size(); });
```

### min

This sample uses Min to get the lowest number in an array.

```cpp
std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
auto r = roar::linq::from(numbers).min();
```

This sample uses Min to get the length of the shortest word in an array.

```cpp
std::vector<std::string> words{ "cherry", "apple", "blueberry" };
auto shortest = roar::linq::from(words).min([](const std::string& w) { return w.size(); });
```

### select

This sample uses select to return a sequence of just the names of a list of products.

```cpp
struct product {
  std::string name;
  std::size_t type;
};
std::list<product> l{ { "nexus", 5 }, { "iphone", 5 }, { "galaxy", 5 } };
auto names = roar::linq::from(l).select([](const product& p) { return p.name; });
Assert::IsTrue(std::equal(
  std::begin(l),
  std::end(l),
  std::begin(names),
  [](const product& p, const std::string& name) {
    return p.name == name;
  }
));
```

This sample combines select and where to make a simple query that returns the text form of each digit less than 5.

```cpp
std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
std::vector<std::string> digits{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
auto r = roar::linq::from(numbers).where([](int i){ return i < 5; }).select([&digits](int i) { return digits[i]; });
```

This sample uses select to produce a sequence of strings representing the text version of a sequence of ints.

```cpp
std::vector<int> v{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
std::vector<std::string> strings{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
auto text_nums = roar::linq::from(v).select([&strings](int i) { return strings[i]; });
```

This sample uses select to produce a sequence of the uppercase and lowercase versions of each word in the original array.

```cpp
std::vector<std::string> v{ "aPPLE", "BlUeBeRrY", "cHeRry" };
using anonymous = struct { std::string upper; std::string lower; };
auto upper_lower_words = roar::linq::from(v)
  .select([](const std::string& s) -> anonymous {
    auto upper = boost::to_upper_copy(s);
    auto lower = boost::to_lower_copy(s);
    return { upper, lower };
});
```

This sample uses select to produce a sequence containing text representations of digits and whether their length is even or odd.

```cpp
std::vector<int> v{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
std::vector<std::string> strings{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
using anonymous = struct { std::string digit; bool even; };
auto digit_odd_evens = roar::linq::from(v)
  .select([&strings](int i) -> anonymous {
  return { strings[i], (i % 2 == 0) }; }
);
```

This sample uses select to produce a sequence containing some properties of Products, including UnitPrice which is renamed to Price in the resulting type.

```cpp
struct product {
  std::string product_name;
  std::string category;
  std::size_t unit_price;
};
std::list<product> products{
  { "iphone", "cellphone", 599 },
  { "nexus", "cellphone", 499 },
  { "galaxy", "cellphone", 499 }
};

using anonymous = struct { std::string name; std::string category; std::size_t price; };
auto r = roar::linq::from(products)
  .select([](const product& p) -> anonymous {
  	return{ p.product_name, p.category, p.unit_price };
  });
```


### skip

This sample uses Skip to get all but the first 4 elements of the array.

```cpp
std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
auto r = roar::linq::from(numbers).skip(4);
```

### sum

This sample uses Sum to get the total of the numbers in an array.

```cpp
std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
auto r = roar::linq::from(numbers).sum();
```

This sample uses Sum to get the total number of characters of all words in the array.

```cpp
std::vector<std::string> words{ "cherry", "apple", "blueberry" };
auto r = roar::linq::from(words).sum([](const std::string& word) { return word.size(); });
```

### sequence_equal

This sample uses EqualAll to see if two sequences match on all elements in the same order

```cpp
std::vector<std::string> words1{ "cherry", "apple", "blueberry" };
std::vector<std::string> words2{ "cherry", "apple", "blueberry" };
auto t = roar::linq::from(words1).sequence_equal(words2);

std::vector<std::string> words3{ "apple", "blueberry", "cherry" };
auto f = roar::linq::from(words1).sequence_equal(words3);
```

### where

This sample uses where to find all elements of an array less than 5.

```cpp
std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
auto r = roar::linq::from(numbers).where([](int i) { return i < 5; });
```

This sample uses where to find all products that are out of stock.

```cpp
struct product {
  std::string product_name;
  std::string category;
  std::size_t unit_price;
  std::size_t units_in_stock;
  bool operator==(const product& other) {
    return product_name == other.product_name &&
      category == other.category &&
      unit_price == other.unit_price &&
      units_in_stock == other.units_in_stock;
  }
};
std::list<product> products{
  { "iphone", "cellphone", 599, 0 },
  { "nexus", "cellphone", 499, 500 },
  { "galaxy", "cellphone", 499, 800 }
};
auto r = roar::linq::from(products)
  .where([](const product& p) {
  return p.units_in_stock == 0;
});
```

This sample uses where to find all products that are in stock and cost more than 400 per unit.

```cpp
struct product {
  std::string product_name;
  std::string category;
  std::size_t unit_price;
  std::size_t units_in_stock;
  bool operator==(const product& other) {
    return product_name == other.product_name &&
      category == other.category &&
      unit_price == other.unit_price &&
      units_in_stock == other.units_in_stock;
  }
};
std::list<product> products{
  { "iphone", "cellphone", 599, 0 },
  { "nexus", "cellphone", 499, 500 },
  { "galaxy", "cellphone", 399, 800 }
};
auto r = roar::linq::from(products)
  .where([](const product& p) {
  return p.units_in_stock > 0 && p.unit_price > 400;
});
```

## License

Copyright (c) 2014 bitdewy@gmail.com

roar is licensed under the MIT Open Source license. For more information, see the [LICENSE](LICENSE) file in this repository.
