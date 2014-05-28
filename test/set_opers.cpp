// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-Set-Operators-374f34fe

TEST_CLASS(SetOperators) {
public:
  TEST_METHOD(distinct1) {
    // This sample uses Distinct to remove duplicate elements in a sequence of factors of 300.
    //public void Linq46()
    //{
    //  int[] factorsOf300 = { 2, 2, 3, 5, 5 };

    //  var uniqueFactors = factorsOf300.Distinct();

    //  Console.WriteLine("Prime factors of 300:");
    //  foreach(var f in uniqueFactors)
    //  {
    //    Console.WriteLine(f);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(distinct2) {
    // This sample uses Distinct to find the unique Category names.
    //public void Linq47()
    //{
    //  List<Product> products = GetProductList();

    //  var categoryNames = (
    //    from p in products
    //    select p.Category)
    //    .Distinct();

    //  Console.WriteLine("Category names:");
    //  foreach(var n in categoryNames)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(union1) {
    // This sample uses Union to create one sequence that contains the unique values from both arrays.
    //public void Linq48()
    //{
    //  int[] numbersA = { 0, 2, 4, 5, 6, 8, 9 };
    //  int[] numbersB = { 1, 3, 5, 7, 8 };

    //  var uniqueNumbers = numbersA.Union(numbersB);

    //  Console.WriteLine("Unique numbers from both arrays:");
    //  foreach(var n in uniqueNumbers)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(union2) {
    // This sample uses Union to create one sequence that contains the unique first letter from both product and customer names.
    //public void Linq49()
    //{
    //  List<Product> products = GetProductList();
    //  List<Customer> customers = GetCustomerList();

    //  var productFirstChars =
    //    from p in products
    //    select p.ProductName[0];
    //  var customerFirstChars =
    //    from c in customers
    //    select c.CompanyName[0];

    //  var uniqueFirstChars = productFirstChars.Union(customerFirstChars);

    //  Console.WriteLine("Unique first letters from Product names and Customer names:");
    //  foreach(var ch in uniqueFirstChars)
    //  {
    //    Console.WriteLine(ch);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(intersect1) {
    // This sample uses Intersect to create one sequence that contains the common values shared by both arrays.
    //public void Linq50()
    //{
    //  int[] numbersA = { 0, 2, 4, 5, 6, 8, 9 };
    //  int[] numbersB = { 1, 3, 5, 7, 8 };

    //  var commonNumbers = numbersA.Intersect(numbersB);

    //  Console.WriteLine("Common numbers shared by both arrays:");
    //  foreach(var n in commonNumbers)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(intersect2) {
    // This sample uses Intersect to create one sequence that contains the common values shared by both arrays.
    //public void Linq51()
    //{
    //  List<Product> products = GetProductList();
    //  List<Customer> customers = GetCustomerList();

    //  var productFirstChars =
    //    from p in products
    //    select p.ProductName[0];
    //  var customerFirstChars =
    //    from c in customers
    //    select c.CompanyName[0];

    //  var commonFirstChars = productFirstChars.Intersect(customerFirstChars);

    //  Console.WriteLine("Common first letters from Product names and Customer names:");
    //  foreach(var ch in commonFirstChars)
    //  {
    //    Console.WriteLine(ch);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(except1) {
    // This sample uses Except to create a sequence that contains the values from numbersAthat are not also in numbersB.
    //public void Linq52()
    //{
    //  int[] numbersA = { 0, 2, 4, 5, 6, 8, 9 };
    //  int[] numbersB = { 1, 3, 5, 7, 8 };

    //  IEnumerable<int> aOnlyNumbers = numbersA.Except(numbersB);

    //  Console.WriteLine("Numbers in first array but not second array:");
    //  foreach(var n in aOnlyNumbers)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(except2) {
    // This sample uses Except to create one sequence that contains the first letters of product names that are not also first letters of customer names.
    //public void Linq53()
    //{
    //  List<Product> products = GetProductList();
    //  List<Customer> customers = GetCustomerList();

    //  var productFirstChars =
    //    from p in products
    //    select p.ProductName[0];
    //  var customerFirstChars =
    //    from c in customers
    //    select c.CompanyName[0];

    //  var productOnlyFirstChars = productFirstChars.Except(customerFirstChars);

    //  Console.WriteLine("First letters from Product names, but not from Customer names:");
    //  foreach(var ch in productOnlyFirstChars)
    //  {
    //    Console.WriteLine(ch);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
