// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include <vector>

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-Aggregate-Operators-c51b3869

TEST_CLASS(AggregateOperators) {
public:
  TEST_METHOD(countSimple) {
    // This sample uses Count to get the number of unique factors of 300.
    //public void Linq73()
    //{
    //  int[] factorsOf300 = { 2, 2, 3, 5, 5 };
    //  int uniqueFactors = factorsOf300.Distinct().Count();
    //  Console.WriteLine("There are {0} unique factors of 300.", uniqueFactors);
    //}
    // TODO(bitdewy): distinct
    std::vector<int> factors_of_300{ 2, 2, 3, 5, 5 };
    auto count = roar::linq::from(factors_of_300).count();
    Assert::IsTrue(count == 5);
  }

  TEST_METHOD(countConditional) {
    // This sample uses Count to get the number of odd ints in the array.
    //public void Linq74()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  int oddNumbers = numbers.Count(n = > n % 2 == 1);
    //  Console.WriteLine("There are {0} odd numbers in the list.", oddNumbers);
    //}
    std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    auto r = roar::linq::from(numbers).count([](int i) { return i % 2 == 1; });
    Assert::IsTrue(r == 5);
  }

  TEST_METHOD(countNested) {
    // This sample uses All to determine whether an array contains only odd numbers.
    //public void Linq76()
    //{
    //  List<Customer> customers = GetCustomerList();

    //  var orderCounts =
    //    from c in customers
    //    select new{ c.CustomerID, OrderCount = c.Orders.Count() };

    //  ObjectDumper.Write(orderCounts);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(countGrouped) {
    // This sample uses Count to return a list of categories and how many products each has.
    //public void Linq77()
    //{
    //  List<Product> products = GetProductList();

    //  var categoryCounts =
    //    from p in products
    //    group p by p.Category into g
    //    select new{ Category = g.Key, ProductCount = g.Count() };

    //  ObjectDumper.Write(categoryCounts
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(sumSimple) {
    // This sample uses Sum to get the total of the numbers in an array.
    //public void Linq78()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

    //  double numSum = numbers.Sum();

    //  Console.WriteLine("The sum of the numbers is {0}.", numSum);
    //}
    std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    auto r = roar::linq::from(numbers).sum();
    Assert::IsTrue(r == 45);
  }

  TEST_METHOD(sumProjection) {
    // This sample uses Sum to get the total number of characters of all words in the array.
    //public void Linq79()
    //{
    //  string[] words = { "cherry", "apple", "blueberry" };

    //  double totalChars = words.Sum(w = > w.Length);

    //  Console.WriteLine("There are a total of {0} characters in these words.", totalChars);
    //}
    std::vector<std::string> words{ "cherry", "apple", "blueberry" };
    auto r = roar::linq::from(words).sum([](const std::string& word) { return word.size(); });
    Assert::IsTrue(r == 20);
  }

  TEST_METHOD(sumGrouped) {
    // This sample uses Sum to get the total units in stock for each product category.
    //public void Linq80()
    //{
    //  List<Product> products = GetProductList();

    //  var categories =
    //    from p in products
    //    group p by p.Category into g
    //    select new{ Category = g.Key, TotalUnitsInStock = g.Sum(p = > p.UnitsInStock) };

    //  ObjectDumper.Write(categories);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(minSimple) {
    // This sample uses Min to get the lowest number in an array.
    //public void Linq81()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

    //  int minNum = numbers.Min();

    //  Console.WriteLine("The minimum number is {0}.", minNum);
    //}
    std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    auto r = roar::linq::from(numbers).min();
    Assert::IsTrue(r == 0);
  }

  TEST_METHOD(minProjection) {
    // This sample uses Min to get the length of the shortest word in an array.
    //public void Linq82()
    //{
    //  string[] words = { "cherry", "apple", "blueberry" };

    //  int shortestWord = words.Min(w = > w.Length);

    //  Console.WriteLine("The shortest word is {0} characters long.", shortestWord);
    //}
    std::vector<std::string> words{ "cherry", "apple", "blueberry" };
    auto shortest = roar::linq::from(words).min([](const std::string& w) { return w.size(); });
    Assert::IsTrue(shortest == 5);
  }

  TEST_METHOD(minGrouped) {
    // This sample uses Min to get the cheapest price among each category's products.
    //public void Linq83()
    //{
    //  List<Product> products = GetProductList();

    //  var categories =
    //    from p in products
    //    group p by p.Category into g
    //    select new{ Category = g.Key, CheapestPrice = g.Min(p = > p.UnitPrice) };

    //  ObjectDumper.Write(categories);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(minElements) {
    // This sample uses Min to get the products with the cheapest price in each category.
    //public void Linq84()
    //{
    //  List<Product> products = GetProductList();

    //  var categories =
    //    from p in products
    //    group p by p.Category into g
    //    let minPrice = g.Min(p = > p.UnitPrice)
    //    select new{ Category = g.Key, CheapestProducts = g.Where(p = > p.UnitPrice == minPrice) };

    //  ObjectDumper.Write(categories, 1);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(maxSimple) {
    // This sample uses Max to get the highest number in an array.
    //public void Linq85()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

    //  int maxNum = numbers.Max();

    //  Console.WriteLine("The maximum number is {0}.", maxNum);
    //}
    std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    auto r = roar::linq::from(numbers).max();
    Assert::IsTrue(r == 9);
  }

  TEST_METHOD(maxProjection) {
    // This sample uses Max to get the length of the longest word in an array.
    //public void Linq86()
    //{
    //  string[] words = { "cherry", "apple", "blueberry" };

    //  int longestLength = words.Max(w = > w.Length);

    //  Console.WriteLine("The longest word is {0} characters long.", longestLength);
    //}
    std::vector<std::string> words{ "cherry", "apple", "blueberry" };
    auto shortest = roar::linq::from(words).max([](const std::string& w) { return w.size(); });
    Assert::IsTrue(shortest == 9);
  }

  TEST_METHOD(maxGrouped) {
    // This sample uses Max to get the most expensive price among each category's products.
    //public void Linq87()
    //{
    //  List<Product> products = GetProductList();

    //  var categories =
    //    from p in products
    //    group p by p.Category into g
    //    select new{ Category = g.Key, MostExpensivePrice = g.Max(p = > p.UnitPrice) };

    //  ObjectDumper.Write(categories);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(maxElements) {
    // This sample uses Max to get the products with the most expensive price in each category.
    //public void Linq88()
    //{
    //  List<Product> products = GetProductList();

    //  var categories =
    //    from p in products
    //    group p by p.Category into g
    //    let maxPrice = g.Max(p = > p.UnitPrice)
    //    select new{ Category = g.Key, MostExpensiveProducts = g.Where(p = > p.UnitPrice == maxPrice) };

    //  ObjectDumper.Write(categories, 1);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(averageSimple) {
    // This sample uses Average to get the average of all numbers in an array.
    //public void Linq89()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

    //  double averageNum = numbers.Average();

    //  Console.WriteLine("The average number is {0}.", averageNum);
    //}
    std::vector<int> numbers{ 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    auto average = roar::linq::from(numbers).average();
    Assert::IsTrue(abs(average - 4.5) < 1e-5);
  }

  TEST_METHOD(averageProjection) {
    // This sample uses Average to get the average length of the words in the array.
    //public void Linq90()
    //{
    //  string[] words = { "cherry", "apple", "blueberry" };

    //  double averageLength = words.Average(w = > w.Length);

    //  Console.WriteLine("The average word length is {0} characters.", averageLength);
    //}
    std::vector<std::string> words{ "cherry", "apple", "blueberry" };
    auto r = roar::linq::from(words).average([](const std::string& s) { return s.size(); });
    Assert::IsTrue(abs(r - 6.66666) < 1e-5);
  }

  TEST_METHOD(averageGrouped) {
    // This sample uses Average to get the average price of each category's products.
    //public void Linq91()
    //{
    //  List<Product> products = GetProductList();

    //  var categories =
    //    from p in products
    //    group p by p.Category into g
    //    select new{ Category = g.Key, AveragePrice = g.Average(p = > p.UnitPrice) };

    //  ObjectDumper.Write(categories);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(aggregateSimple) {
    // This sample uses Aggregate to create a running product on the array that calculates the total product of all elements.
    //public void Linq92()
    //{
    //  double[] doubles = { 1.7, 2.3, 1.9, 4.1, 2.9 };

    //  double product = doubles.Aggregate((runningProduct, nextFactor) = > runningProduct * nextFactor);

    //  Console.WriteLine("Total product of all numbers: {0}", product);
    //}
    std::vector<double> doubles{ 1.7, 2.3, 1.9, 4.1, 2.9 };
    auto product = roar::linq::from(doubles)
      .aggregate([](double running, double next) { return running * next; });
    Logger::WriteMessage(std::to_wstring(product).c_str());
    Assert::IsTrue(abs(product - 88.33081) < 1e-5);
  }

  TEST_METHOD(aggregateSeed) {
    // This sample uses Aggregate to create a running account balance that subtracts each withdrawal from the initial balance of 100, as long as the balance never drops below 0.
    //public void Linq93()
    //{
    //  double startBalance = 100.0;

    //  int[] attemptedWithdrawals = { 20, 10, 40, 50, 10, 70, 30 };

    //  double endBalance =
    //    attemptedWithdrawals.Aggregate(startBalance,
    //    (balance, nextWithdrawal) = >
    //    ((nextWithdrawal <= balance) ? (balance - nextWithdrawal) : balance));

    //  Console.WriteLine("Ending balance: {0}", endBalance);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
