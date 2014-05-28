// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-Restriction-Operators-b15d29ca

TEST_CLASS(RestrictionOperators) {
public:
  TEST_METHOD(whereSimple1) {
    // This sample uses where to find all elements of an array less than 5.
    //public void Linq1()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

    //  var lowNums =
    //    from n in numbers
    //    where n < 5
    //    select n;

    //  Console.WriteLine("Numbers < 5:");
    //  foreach(var x in lowNums)
    //  {
    //    Console.WriteLine(x);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(whereSimple2) {
    // This sample uses where to find all products that are out of stock.
    //public void Linq2()
    //{
    //  List<Product> products = GetProductList();

    //  var soldOutProducts =
    //    from p in products
    //    where p.UnitsInStock == 0
    //    select p;

    //  Console.WriteLine("Sold out products:");
    //  foreach(var product in soldOutProducts)
    //  {
    //    Console.WriteLine("{0} is sold out!", product.ProductName);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(whereSimple3) {
    // This sample uses where to find all products that are in stock and cost more than 3.00 per unit.
    //public void Linq3()
    //{
    //  List<Product> products = GetProductList();

    //  var expensiveInStockProducts =
    //    from p in products
    //    where p.UnitsInStock > 0 && p.UnitPrice > 3.00M
    //    select p;

    //  Console.WriteLine("In-stock products that cost more than 3.00:");
    //  foreach(var product in expensiveInStockProducts)
    //  {
    //    Console.WriteLine("{0} is in stock and costs more than 3.00.", product.ProductName);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(whereDrilldown) {
    // This sample uses where to find all customers in Washington and then uses the resulting sequence to drill down into their orde
    //public void Linq4()
    //{
    //  List<Customer> customers = GetCustomerList();

    //  var waCustomers =
    //    from c in customers
    //    where c.Region == "WA"
    //    select c;

    //  Console.WriteLine("Customers from Washington and their orders:");
    //  foreach(var customer in waCustomers)
    //  {
    //    Console.WriteLine("Customer {0}: {1}", customer.CustomerID, customer.CompanyName);
    //    foreach(var order in customer.Orders)
    //    {
    //      Console.WriteLine("  Order {0}: {1}", order.OrderID, order.OrderDate);
    //    }
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(whereIndexed) {
    // This sample demonstrates an indexed Where clause that returns digits whose name is shorter than their value.
    //public void Linq5()
    //{
    //  string[] digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    //  var shortDigits = digits.Where((digit, index) = > digit.Length < index);

    //  Console.WriteLine("Short digits:");
    //  foreach(var d in shortDigits)
    //  {
    //    Console.WriteLine("The word {0} is shorter than its value.", d);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
