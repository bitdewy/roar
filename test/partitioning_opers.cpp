// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-Partitioning-Operators-c68aaccc

TEST_CLASS(PartitioningOperators) {
public:
  TEST_METHOD(takeSimple) {
    // This sample uses Take to get only the first 3 elements of the array.
    //public void Linq20()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  var first3Numbers = numbers.Take(3);
    //  Console.WriteLine("First 3 numbers:");
    //  foreach(var n in first3Numbers)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(takeNested) {
    // This sample uses Take to get the first 3 orders from customers in Washington.
    //public void Linq21()
    //{
    //  List<Customer> customers = GetCustomerList();
    //  var first3WAOrders = (
    //    from c in customers
    //    from o in c.Orders
    //    where c.Region == "WA"
    //    select new{ c.CustomerID, o.OrderID, o.OrderDate })
    //    .Take(3);
    //  Console.WriteLine("First 3 orders in WA:");
    //  foreach(var order in first3WAOrders)
    //  {
    //    ObjectDumper.Write(order);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(skipSimple) {
    // This sample uses Skip to get all but the first 4 elements of the array.
    //public void Linq22()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  var allButFirst4Numbers = numbers.Skip(4);
    //  Console.WriteLine("All but first 4 numbers:");
    //  foreach(var n in allButFirst4Numbers)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(skipNested) {
    // This sample uses Take to get all but the first 2 orders from customers in Washington.
    //public void Linq23()
    //{
    //  List<Customer> customers = GetCustomerList();
    //  var waOrders =
    //    from c in customers
    //    from o in c.Orders
    //    where c.Region == "WA"
    //    select new{ c.CustomerID, o.OrderID, o.OrderDate };
    //  var allButFirst2Orders = waOrders.Skip(2);
    //  Console.WriteLine("All but first 2 orders in WA:");
    //  foreach(var order in allButFirst2Orders)
    //  {
    //    ObjectDumper.Write(order);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(takeWhileSimple) {
    // This sample uses TakeWhile to return elements starting from the beginning of the array until a number is hit that is not less than 6.
    //public void Linq24()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  var firstNumbersLessThan6 = numbers.TakeWhile(n = > n < 6);
    //  Console.WriteLine("First numbers less than 6:");
    //  foreach(var n in firstNumbersLessThan6)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(takeWhileIndexed) {
    // This sample uses TakeWhile to return elements starting from the beginning of the array until a number is hit that is less than its position in the array.
    //public void Linq25()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  var firstSmallNumbers = numbers.TakeWhile((n, index) = > n >= index);
    //  Console.WriteLine("First numbers not less than their position:");
    //  foreach(var n in firstSmallNumbers)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(skipWhileSimple) {
    // This sample uses SkipWhile to get the elements of the array starting from the first element divisible by 3.
    //public void Linq26()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  var allButFirst3Numbers = numbers.SkipWhile(n = > n % 3 != 0);
    //  Console.WriteLine("All elements starting from first element divisible by 3:");
    //  foreach(var n in allButFirst3Numbers)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(skipWhileIndexed) {
    // This sample uses SkipWhile to get the elements of the array starting from the first element less than its position.
    //public void Linq27()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    //  var laterNumbers = numbers.SkipWhile((n, index) = > n >= index);
    //  Console.WriteLine("All elements starting from first element less than its position:");
    //  foreach(var n in laterNumbers)
    //  {
    //    Console.WriteLine(n);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
