// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include <list>
#include <vector>

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-Element-Operators-0f3f12ce

TEST_CLASS(ElementOperators) {
public:
  TEST_METHOD(firstSimple1) {
    // This sample uses First to return the first matching element as a Product, instead of as a sequence containing a Product.
    //public void Linq58()
    //{
    //  List<Product> products = GetProductList();

    //  Product product12 = (
    //    from p in products
    //  where p.ProductID == 12
    //    select p)
    //    .First();

    //  ObjectDumper.Write(product12);
    //}
    struct product {
      std::string name;
      std::size_t type;
    };
    std::list<product> l{ { "nexus", 5 }, { "iphone", 5 }, { "galaxy", 5 }, { "galaxy", 4 }, { "iphone", 4 }, { "nexus", 4 } };
    auto p = roar::linq::from(l).where([](const product& p) { return p.type == 4; }).first();
    Assert::IsTrue(p.name == "galaxy" && p.type == 4 );
  }

  TEST_METHOD(firstCondition) {
    // This sample uses First to find the first element in the array that starts with 'o'.
    //public void Linq59()
    //{
    //  string[] strings = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    //  string startsWithO = strings.First(s = > s[0] == 'o');
    //  Console.WriteLine("A string starting with 'o': {0}", startsWithO);
    //}
    std::vector<std::string> strings{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    auto starts_with_o = roar::linq::from(strings).first([](const std::string& s) { return s[0] == 'o'; });
    Assert::IsTrue(starts_with_o == "one");
  }

  TEST_METHOD(firstOrDefaultSimple) {
    // This sample uses FirstOrDefault to try to return the first element of the sequence, unless there are no elements, in which case the default value for that type is returned.
    //public void Linq61()
    //{
    //  int[] numbers = {};
    //  int firstNumOrDefault = numbers.FirstOrDefault();
    //  Console.WriteLine(firstNumOrDefault);
    //}
    std::vector<int> numbers{};
    int first_or_default = roar::linq::from(numbers).first_or_default();
    Assert::IsTrue(first_or_default == 0);
  }

  TEST_METHOD(firstOrDefaultCondition) {
    // This sample uses FirstOrDefault to return the first product whose ProductID is 789 as a single Product object, unless there is no match, in which case null is returned.
    //public void Linq62()
    //{
    //  List<Product> products = GetProductList();
    //  Product product789 = products.FirstOrDefault(p = > p.ProductID == 789);
    //  Console.WriteLine("Product 789 exists: {0}", product789 != null);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(elementAt) {
    // This sample uses ElementAt to retrieve the second number greater than 5 from an array.
    //public void Linq64()
    //{
    //  int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };

    //  int fourthLowNum = (
    //    from n in numbers
    //    where n > 5
    //    select n)
    //    .ElementAt(1);  // second number is index 1 because sequences use 0-based indexing 

    //  Console.WriteLine("Second number > 5: {0}", fourthLowNum);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
