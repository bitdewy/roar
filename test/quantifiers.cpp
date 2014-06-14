// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include <vector>

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-Quantifiers-f00e7e3e

TEST_CLASS(Quantifiers) {
public:
  TEST_METHOD(anySimple) {
    // This sample uses Any to determine if any of the words in the array contain the substring 'ei'.
    //public void Linq67()
    //{
    //  string[] words = { "believe", "relief", "receipt", "field" };
    //  bool iAfterE = words.Any(w = > w.Contains("ei"));
    //  Console.WriteLine("There is a word that contains in the list that contains 'ei': {0}", iAfterE);
    //}
    std::vector<std::string> words{ "believe", "relief", "receipt", "field" };
    bool i_after_e = roar::linq::from(words)
      .any([](const std::string& s) {
        return s.find("ie") != std::string::npos;
      });
    Assert::IsTrue(i_after_e);
  }

  TEST_METHOD(anyGrouped) {
    // This sample uses Any to return a grouped a list of products only for categories that have at least one product that is out of stock.
    //public void Linq69()
    //{
    //  List<Product> products = GetProductList();
    //  var productGroups =
    //    from p in products
    //    group p by p.Category into g
    //  where g.Any(p = > p.UnitsInStock == 0)
    //    select new{ Category = g.Key, Products = g };

    //  ObjectDumper.Write(productGroups, 1);
    //}

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
    std::list<std::list<product>> expect{
      {
        { "ipad", "pad", 299 },
        { "nexus7", "pad", 399 },
        { "galaxy", "pad", 499 }
      }
    };
    Assert::IsTrue(std::equal(std::begin(group), std::end(group), std::begin(expect)));
  }

  TEST_METHOD(allSimple) {
    // This sample uses All to determine whether an array contains only odd numbers.
    //public void Linq70()
    //{
    //  int[] numbers = { 1, 11, 3, 19, 41, 65, 19 };
    //  bool onlyOdd = numbers.All(n = > n % 2 == 1);
    //  Console.WriteLine("The list contains only odd numbers: {0}", onlyOdd);
    //}
    std::vector<int> numbers{ 1, 11, 3, 19, 41, 65, 19 };
    bool only_odd = roar::linq::from(numbers).all([](int i) { return i % 2 == 1; });
    Assert::IsTrue(only_odd);
  }

  TEST_METHOD(allGrouped) {
    // This sample uses All to return a grouped a list of products only for categories that have all of their products in stock.
    //public void Linq72()
    //{
    //  List<Product> products = GetProductList();
    //  var productGroups =
    //    from p in products
    //    group p by p.Category into g
    //  where g.All(p = > p.UnitsInStock > 0)
    //    select new{ Category = g.Key, Products = g };
    //  ObjectDumper.Write(productGroups, 1);
    //}
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
    std::list<std::list<product>> expect{ {
      { "iphone", "cellphone", 599 },
      { "nexus", "cellphone", 499 },
      { "galaxy", "cellphone", 499 }
    } };
    Assert::IsTrue(std::equal(std::begin(group), std::end(group), std::begin(expect)));
  }

};

}  // namespace test
