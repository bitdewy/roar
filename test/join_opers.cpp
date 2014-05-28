// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-Join-Operators-dabef4e9

TEST_CLASS(JoinOperators) {
public:
  TEST_METHOD(crossJoin) {
    // This sample shows how to efficiently join elements of two sequences based on equality between key expressions over the two.
    //public void Linq102()
    //{

    //  string[] categories = new string[]{
    //    "Beverages",
    //      "Condiments",
    //      "Vegetables",
    //      "Dairy Products",
    //      "Seafood" };

    //  List<Product> products = GetProductList();

    //  var q =
    //    from c in categories
    //    join p in products on c equals p.Category
    //    select new{ Category = c, p.ProductName };

    //  foreach(var v in q)
    //  {
    //    Console.WriteLine(v.ProductName + ": " + v.Category);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(groupJoin) {
    // Using a group join you can get all the products that match a given category bundled as a sequence.
    //public void Linq103()
    //{
    //  string[] categories = new string[]{
    //    "Beverages",
    //      "Condiments",
    //      "Vegetables",
    //      "Dairy Products",
    //      "Seafood" };

    //  List<Product> products = GetProductList();

    //  var q =
    //    from c in categories
    //    join p in products on c equals p.Category into ps
    //    select new{ Category = c, Products = ps };

    //  foreach(var v in q)
    //  {
    //    Console.WriteLine(v.Category + ":");
    //    foreach(var p in v.Products)
    //    {
    //      Console.WriteLine("   " + p.ProductName);
    //    }
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(crossJoinWithGroupJoin) {
    // The group join operator is more general than join, as this slightly more verbose version of the cross join sample shows.
    //public void Linq104()
    //{
    //  string[] categories = new string[]{
    //    "Beverages",
    //      "Condiments",
    //      "Vegetables",
    //      "Dairy Products",
    //      "Seafood" };

    //  List<Product> products = GetProductList();
    //  var q =
    //    from c in categories
    //    join p in products on c equals p.Category into ps
    //    from p in ps
    //    select new{ Category = c, p.ProductName };

    //  foreach(var v in q)
    //  {
    //    Console.WriteLine(v.ProductName + ": " + v.Category);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(leftOuterJoin) {
    // A so-called outer join can be expressed with a group join. A left outer joinis like a cross join, except that all the left hand side elements get included at least once, even if they don't match any right hand side elements. Note how Vegetablesshows up in the output even though it has no matching products.
    //public void Linq105()
    //{
    //  string[] categories = new string[]{
    //    "Beverages",
    //      "Condiments",
    //      "Vegetables",
    //      "Dairy Products",
    //      "Seafood" };

    //  List<Product> products = GetProductList();
    //  var q =
    //    from c in categories
    //    join p in products on c equals p.Category into ps
    //    from p in ps.DefaultIfEmpty()
    //    select new{ Category = c, ProductName = p == null ? "(No products)" : p.ProductName };

    //  foreach(var v in q)
    //  {
    //    Console.WriteLine(v.ProductName + ": " + v.Category);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
