// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include <vector>

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-Miscellaneous-6b72bb2a

TEST_CLASS(MiscellaneousOperators) {
public:
  TEST_METHOD(concat1) {
    // This sample uses Concat to create one sequence that contains each array's values, one after the other.
    //public void Linq94()
    //{
    //  int[] numbersA = { 0, 2, 4, 5, 6, 8, 9 };
    //  int[] numbersB = { 1, 3, 5, 7, 8 };

    //  var allNumbers = numbersA.Concat(numbersB);

    //  Console.WriteLine("All numbers from both arrays:");
    //  foreach(var n in allNumbers)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(concat2) {
    // This sample uses Concat to create one sequence that contains the names of all customers and products, including any duplicates.
    //public void Linq95()
    //{
    //  List<Customer> customers = GetCustomerList();
    //  List<Product> products = GetProductList();

    //  var customerNames =
    //    from c in customers
    //    select c.CompanyName;
    //  var productNames =
    //    from p in products
    //    select p.ProductName;

    //  var allNames = customerNames.Concat(productNames);

    //  Console.WriteLine("Customer and product names:");
    //  foreach(var n in allNames)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(equalAll1) {
    // This sample uses EqualAll to see if two sequences match on all elements in the same order.
    //public void Linq96()
    //{
    //  var wordsA = new string[] { "cherry", "apple", "blueberry" };
    //  var wordsB = new string[] { "cherry", "apple", "blueberry" };

    //  bool match = wordsA.SequenceEqual(wordsB);

    //  Console.WriteLine("The sequences match: {0}", match);
    //}
    std::vector<std::string> words1{ "cherry", "apple", "blueberry" };
    std::vector<std::string> words2{ "cherry", "apple", "blueberry" };
    auto r = roar::linq::from(words1).sequence_equal(words2);
    Assert::IsTrue(r);
  }

  TEST_METHOD(equalAll2) {
    // This sample uses EqualAll to see if two sequences match on all elements in the same order.
    //public void Linq97()
    //{
    //  var wordsA = new string[] { "cherry", "apple", "blueberry" };
    //  var wordsB = new string[] { "apple", "blueberry", "cherry" };

    //  bool match = wordsA.SequenceEqual(wordsB);

    //  Console.WriteLine("The sequences match: {0}", match);
    //}
    std::vector<std::string> words1{ "cherry", "apple", "blueberry" };
    std::vector<std::string> words2{ "apple", "blueberry", "cherry" };
    auto r = roar::linq::from(words1).sequence_equal(words2);
    Assert::IsFalse(r);
  }

};

}  // namespace test
