// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include <array>
#include <list>
#include <set>
#include <vector>

#include "boost/algorithm/string.hpp"
#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-to-DataSets-09787825

TEST_CLASS(ProjectionOperators) {
public:
  TEST_METHOD(selectSimple1) {
    // This sample uses select to produce a sequence of ints one higher than those in an existing array of ints.
    //public void Linq6()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

    //  var numsPlusOne =
    //    from n in numbers
    //    select n + 1;

    //  Console.WriteLine("Numbers + 1:");
    //  foreach(var i in numsPlusOne)
    //  {
    //    Console.WriteLine(i);
    //  }
    //}
    {  // test container std array
      std::array<int, 10> a{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
      auto nums_plus_one = roar::linq::from(a)
        .select([](int i) { return i + 1; });
      Assert::IsTrue(std::equal(
        std::begin(a),
        std::end(a),
        std::begin(nums_plus_one),
        [](int x, int y) {
          return x + 1 == y;
        }
      ));
    }

    {  // test container std list
    std::list<int> l{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    auto nums_plus_one = roar::linq::from(l)
      .select([](int i) { return i + 1; });
    Assert::IsTrue(std::equal(
      std::begin(l),
      std::end(l),
      std::begin(nums_plus_one),
      [](int x, int y) {
        return x + 1 == y;
      }
    ));
  }

    {  // test container std set
      std::set<int> s{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
      auto nums_plus_one = roar::linq::from(s)
        .select([](int i) { return i + 1; });
      Assert::IsTrue(std::equal(
        std::begin(s),
        std::end(s),
        std::begin(nums_plus_one),
        [](int x, int y) {
          return x + 1 == y;
        }
      ));
    }

    {  // test container std vector
      std::vector<int> v{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
      auto nums_plus_one = roar::linq::from(v)
        .select([](int i) { return i + 1; });
      Assert::IsTrue(std::equal(
        std::begin(v),
        std::end(v),
        std::begin(nums_plus_one),
        [](int x, int y) {
          return x + 1 == y;
        }
      ));
    }
  }

  TEST_METHOD(selectSimple2) {
    // This sample uses select to return a sequence of just the names of a list of products.
    //public void Linq7()
    //{
    //  List<Product> products = GetProductList();

    //  var productNames =
    //    from p in products
    //    select p.ProductName;

    //  Console.WriteLine("Product Names:");
    //  foreach(var productName in productNames)
    //  {
    //    Console.WriteLine(productName);
    //  }
    //}
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
  }

  TEST_METHOD(selectTransformation) {
    // This sample uses select to produce a sequence of strings representing the text version of a sequence of ints.
    //public void Linq8()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  string[] strings = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    //  var textNums =
    //    from n in numbers
    //    select strings[n];

    //  Console.WriteLine("Number strings:");
    //  foreach(var s in textNums)
    //  {
    //    Console.WriteLine(s);
    //  }
    //}
    std::vector<int> v{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    std::vector<std::string> strings{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    auto text_nums = roar::linq::from(v).select([&strings](int i) { return strings[i]; });
    Assert::IsTrue(std::equal(
      std::begin(v),
      std::end(v),
      std::begin(text_nums),
      [&strings](int i, const std::string& name) {
        return strings[i] == name;
      }
    ));
  }

  TEST_METHOD(selectAnonymousTypes1) {
    // This sample uses select to produce a sequence of the uppercase and lowercase versions of each word in the original array.
    //public void Linq9()
    //{
    //  string[] words = { "aPPLE", "BlUeBeRrY", "cHeRry" };

    //  var upperLowerWords =
    //    from w in words
    //    select new{ Upper = w.ToUpper(), Lower = w.ToLower() };

    //  foreach(var ul in upperLowerWords)
    //  {
    //    Console.WriteLine("Uppercase: {0}, Lowercase: {1}", ul.Upper, ul.Lower);
    //  }
    //}
    std::vector<std::string> v{ "aPPLE", "BlUeBeRrY", "cHeRry" };
    using anonymous = struct { std::string upper; std::string lower; };
    auto upper_lower_words = roar::linq::from(v)
      .select([](const std::string& s) -> anonymous {
        auto upper = boost::to_upper_copy(s);
        auto lower = boost::to_lower_copy(s);
        return { upper, lower };
    });
    Assert::IsTrue(std::equal(
      std::begin(v),
      std::end(v),
      std::begin(upper_lower_words),
      [](const std::string& s, const anonymous& words) {
        return boost::to_upper_copy(s) == words.upper &&
          boost::to_lower_copy(s) == words.lower;
      }
    ));
  }

  TEST_METHOD(selectAnonymousTypes2) {
    // This sample uses select to produce a sequence containing text representations of digits and whether their length is even or odd.
    //public void Linq10()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  string[] strings = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    //  var digitOddEvens =
    //    from n in numbers
    //    select new{ Digit = strings[n], Even = (n % 2 == 0) };

    //  foreach(var d in digitOddEvens)
    //  {
    //    Console.WriteLine("The digit {0} is {1}.", d.Digit, d.Even ? "even" : "odd");
    //  }
    //}
    std::vector<int> v{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    std::vector<std::string> strings{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    using anonymous = struct { std::string digit; bool even; };
    auto digit_odd_evens = roar::linq::from(v)
      .select([&strings](int i) -> anonymous {
      return { strings[i], (i % 2 == 0) }; }
    );
    Assert::IsTrue(std::equal(
      std::begin(v),
      std::end(v),
      std::begin(digit_odd_evens),
      [&strings](int i, const anonymous& number) {
        return strings[i] == number.digit && (i % 2 == 0) == number.even;
      }
    ));
  }

  TEST_METHOD(selectAnonymousTypes3) {
    // This sample uses select to produce a sequence containing some properties of Products, including UnitPrice which is renamed to Price in the resulting type.
    //public void Linq11()
    //{
    //  List<Product> products = GetProductList();

    //  var productInfos =
    //    from p in products
    //    select new{ p.ProductName, p.Category, Price = p.UnitPrice };

    //  Console.WriteLine("Product Info:");
    //  foreach(var productInfo in productInfos)
    //  {
    //    Console.WriteLine("{0} is in the category {1} and costs {2} per unit.", productInfo.ProductName, productInfo.Category, productInfo.Price);
    //  }
    //}
    struct product {
      std::string product_name;
      std::string category;
      std::size_t unit_price;
    };
    std::list<product> products{ { "iphone", "cellphone", 599 }, { "nexus", "cellphone", 499 }, { "galaxy", "cellphone", 499 } };

    using anonymous = struct { std::string name; std::string category; std::size_t price; };
    auto r = roar::linq::from(products)
      .select([](const product& p) -> anonymous { return{ p.product_name, p.category, p.unit_price }; });
    Assert::IsTrue(std::equal(
      std::begin(products),
      std::end(products),
      std::begin(r),
      [](const product& p, const anonymous& a) {
        return p.product_name == a.name && p.category == a.category && p.unit_price == a.price;
      }
    ));
  }

  TEST_METHOD(selectIndexed) {
    // This sample uses an indexed Select clause to determine if the value of ints in an array match their position in the array.
    //public void Linq12()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

    //  var numsInPlace = numbers.Select((num, index) = > new { Num = num, InPlace = (num == index) });

    //  Console.WriteLine("Number: In-place?");
    //  foreach(var n in numsInPlace)
    //  {
    //    Console.WriteLine("{0}: {1}", n.Num, n.InPlace);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(selectFiltered) {
    // This sample combines select and where to make a simple query that returns the text form of each digit less than 5.
    //public void Linq13()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  string[] digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    //  var lowNums =
    //    from n in numbers
    //  where n < 5
    //    select digits[n];

    //  Console.WriteLine("Numbers < 5:");
    //  foreach(var num in lowNums)
    //  {
    //    Console.WriteLine(num);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(selectManyCompoundFrom1) {
    // This sample uses a compound from clause to make a query that returns all pairs of numbers from both arrays such that the number from numbersA is less than the number from numbersB.
    //public void Linq14()
    //{
    //  int[] numbersA = { 0, 2, 4, 5, 6, 8, 9 };
    //  int[] numbersB = { 1, 3, 5, 7, 8 };

    //  var pairs =
    //    from a in numbersA
    //    from b in numbersB
    //    where a < b
    //  select new{ a, b };

    //  Console.WriteLine("Pairs where a < b:");
    //  foreach(var pair in pairs)
    //  {
    //    Console.WriteLine("{0} is less than {1}", pair.a, pair.b);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(selectManyCompoundFrom2) {
    // This sample uses a compound from clause to select all orders where the order total is less than 500.00.
    //public void Linq15()
    //{
    //  List<Customer> customers = GetCustomerList();

    //  var orders =
    //    from c in customers
    //    from o in c.Orders
    //  where o.Total < 500.00M
    //    select new{ c.CustomerID, o.OrderID, o.Total };

    //  ObjectDumper.Write(orders);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(selectManyCompoundFrom3) {
    // This sample uses a compound from clause to select all orders where the order was made in 1998 or later.
    //public void Linq16()
    //{
    //  List<Customer> customers = GetCustomerList();

    //  var orders =
    //    from c in customers
    //    from o in c.Orders
    //    where o.OrderDate >= new DateTime(1998, 1, 1)
    //    select new{ c.CustomerID, o.OrderID, o.OrderDate };

    //  ObjectDumper.Write(orders);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(selectManyFromAssignment) {
    // This sample uses a compound from clause to select all orders where the order total is greater than 2000.00 and uses from assignment to avoid requesting the total twice.
    //public void Linq17()
    //{
    //  List<Customer> customers = GetCustomerList();

    //  var orders =
    //    from c in customers
    //    from o in c.Orders
    //    where o.Total >= 2000.0M
    //    select new{ c.CustomerID, o.OrderID, o.Total };

    //  ObjectDumper.Write(orders);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(selectManyMultipleFrom) {
    // This sample uses multiple from clauses so that filtering on customers can be done before selecting their orders. This makes the query more efficient by not selecting and then discarding orders for customers outside of Washington.
    //public void Linq18()
    //{
    //  List<Customer> customers = GetCustomerList();

    //  DateTime cutoffDate = new DateTime(1997, 1, 1);

    //  var orders =
    //    from c in customers
    //    where c.Region == "WA"
    //    from o in c.Orders
    //    where o.OrderDate >= cutoffDate
    //  select new{ c.CustomerID, o.OrderID };

    //  ObjectDumper.Write(orders);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(selectManyIndexed) {
    // This sample uses an indexed SelectMany clause to select all orders, while referring to customers by the order in which they are returned from the query.
    //public void Linq19()
    //{
    //  List<Customer> customers = GetCustomerList();

    //  var customerOrders =
    //    customers.SelectMany(
    //    (cust, custIndex) = >
    //    cust.Orders.Select(o = > "Customer #" + (custIndex + 1) +
    //    " has an order with OrderID " + o.OrderID));

    //  ObjectDumper.Write(customerOrders);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
