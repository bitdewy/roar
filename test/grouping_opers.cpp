// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include <list>
#include <vector>

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-to-DataSets-Grouping-c62703ea

TEST_CLASS(GroupingOperators) {
public:
  TEST_METHOD(groupBySimple1) {
    // This sample uses group by to partition a list of numbers by their remainder when divided by 5.
    //public void Linq40()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

    //  var numberGroups =
    //    from n in numbers
    //    group n by n % 5 into g
    //    select new{ Remainder = g.Key, Numbers = g };

    //  foreach(var g in numberGroups)
    //  {
    //    Console.WriteLine("Numbers with a remainder of {0} when divided by 5:", g.Remainder);
    //    foreach(var n in g.Numbers)
    //    {
    //      Console.WriteLine(n);
    //    }
    //  }
    //}

    std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    auto numnbers_groups = roar::linq::from(numbers).group_by([](int i) { return i % 5; });
    
    std::vector<std::vector<int>> expect{ { 5, 0 }, { 4, 9 }, { 1, 6 }, { 3, 8 }, { 7, 2 } };
    Assert::IsTrue(std::equal(std::begin(numnbers_groups), std::end(numnbers_groups), std::begin(expect)));
  }

  TEST_METHOD(groupBySimple2) {
    // This sample uses group by to partition a list of words by their first letter.
    //public void Linq41()
    //{
    //  string[] words = { "blueberry", "chimpanzee", "abacus", "banana", "apple", "cheese" };

    //  var wordGroups =
    //    from w in words
    //    group w by w[0] into g
    //    select new{ FirstLetter = g.Key, Words = g };

    //  foreach(var g in wordGroups)
    //  {
    //    Console.WriteLine("Words that start with the letter '{0}':", g.FirstLetter);
    //    foreach(var w in g.Words)
    //    {
    //      Console.WriteLine(w);
    //    }
    //  }
    //}
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
    std::list<anonymous> expect;
    std::list<std::string> start_with_b{ "blueberry", "banana" };
    expect.push_back({ 'b', start_with_b });
    std::list<std::string> start_with_c{ "chimpanzee", "cheese" };
    expect.push_back({ 'c', start_with_c });
    std::list<std::string> start_with_a{ "abacus", "apple" };
    expect.push_back({ 'a', start_with_a });

    Assert::IsTrue(std::equal(std::begin(word_groups), std::end(word_groups), std::begin(expect)));
  }

  TEST_METHOD(groupBySimple3) {
    // This sample uses group by to partition a list of products by category.
    //public void Linq42()
    //{
    //  List<Product> products = GetProductList();

    //  var orderGroups =
    //    from p in products
    //    group p by p.Category into g
    //    select new{ Category = g.Key, Products = g };

    //  ObjectDumper.Write(orderGroups, 1);
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

    std::list<product> cellphone{
      { "iphone", "cellphone", 599 },
      { "nexus", "cellphone", 499 },
      { "galaxy", "cellphone", 499 }
    };

    std::list<product> pad{
      { "ipad", "pad", 299 },
      { "nexus7", "pad", 399 },
      { "galaxy", "pad", 499 }
    };

    std::list<anonymous> expect{
      { "cellphone", cellphone },
      { "pad", pad }
    };

    Assert::IsTrue(std::equal(std::begin(order_groups), std::end(order_groups), std::begin(expect)));
  }

  TEST_METHOD(groupByNested) {
    // This sample uses group by to partition a list of each customer's orders, first by year, and then by month.
    //public void Linq43()
    //{
    //  List<Customer> customers = GetCustomerList();

    //  var customerOrderGroups =
    //    from c in customers
    //    select
    //    new
    //  {
    //    c.CompanyName,
    //    YearGroups =
    //    from o in c.Orders
    //    group o by o.OrderDate.Year into yg
    //    select
    //    new
    //    {
    //    Year = yg.Key,
    //    MonthGroups =
    //    from o in yg
    //    group o by o.OrderDate.Month into mg
    //    select new{ Month = mg.Key, Orders = mg }
    //  }
    //  };

    //  ObjectDumper.Write(customerOrderGroups, 3);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(groupByComparer) {
    // This sample uses GroupBy to partition trimmed elements of an array using a custom comparer that matches words that are anagrams of each other.

    //public void Linq44()
    //{
    //  string[] anagrams = { "from   ", " salt", " earn ", "  last   ", " near ", " form  " };

    //  var orderGroups = anagrams.GroupBy(w = > w.Trim(), new AnagramEqualityComparer());

    //  ObjectDumper.Write(orderGroups, 1);
    //}

    //public class AnagramEqualityComparer : IEqualityComparer<string>
    //{
    //  public bool Equals(string x, string y)
    //  {
    //    return getCanonicalString(x) == getCanonicalString(y);
    //  }

    //  public int GetHashCode(string obj)
    //  {
    //    return getCanonicalString(obj).GetHashCode();
    //  }

    //  private string getCanonicalString(string word)
    //  {
    //    char[] wordChars = word.ToCharArray();
    //    Array.Sort<char>(wordChars);
    //    return new string(wordChars);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(groupByComparerMapped) {
    // This sample uses GroupBy to partition trimmed elements of an array using a custom comparer that matches words that are anagrams of each other, and then converts the results to uppercase.
    //public void Linq45()
    //{
    //  string[] anagrams = { "from   ", " salt", " earn ", "  last   ", " near ", " form  " };

    //  var orderGroups = anagrams.GroupBy(
    //    w = > w.Trim(),
    //    a = > a.ToUpper(),
    //    new AnagramEqualityComparer()
    //    );

    //  ObjectDumper.Write(orderGroups, 1);
    //}

    //public class AnagramEqualityComparer : IEqualityComparer<string>
    //{
    //  public bool Equals(string x, string y)
    //  {
    //    return getCanonicalString(x) == getCanonicalString(y);
    //  }

    //  public int GetHashCode(string obj)
    //  {
    //    return getCanonicalString(obj).GetHashCode();
    //  }

    //  private string getCanonicalString(string word)
    //  {
    //    char[] wordChars = word.ToCharArray();
    //    Array.Sort<char>(wordChars);
    //    return new string(wordChars);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
