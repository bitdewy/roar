// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/SQL-Ordering-Operators-050af19e

TEST_CLASS(OrderingOperators) {
public:
  TEST_METHOD(orderBySimple1) {
    // This sample uses orderby to sort a list of words alphabetically.
    //public void Linq28()
    //{
    //  string[] words = { "cherry", "apple", "blueberry" };

    //  var sortedWords =
    //    from w in words
    //    orderby w
    //    select w;

    //  Console.WriteLine("The sorted list of words:");
    //  foreach(var w in sortedWords)
    //  {
    //    Console.WriteLine(w);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(orderBySimple2) {
    // This sample uses orderby to sort a list of words by length.
    //public void Linq29()
    //{
    //  string[] words = { "cherry", "apple", "blueberry" };

    //  var sortedWords =
    //    from w in words
    //    orderby w.Length
    //    select w;

    //  Console.WriteLine("The sorted list of words (by length):");
    //  foreach(var w in sortedWords)
    //  {
    //    Console.WriteLine(w);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(orderBySimple3) {
    // This sample uses orderby to sort a list of products by name.
    //public void Linq30()
    //{
    //  List<Product> products = GetProductList();

    //  var sortedProducts =
    //    from p in products
    //    orderby p.ProductName
    //    select p;

    //  ObjectDumper.Write(sortedProducts);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(orderByComparer) {
    // This sample uses an OrderBy clause with a custom comparer to do a case-insensitive sort of the words in an array.
    //public void Linq31()
    //{
    //  string[] words = { "aPPLE", "AbAcUs", "bRaNcH", "BlUeBeRrY", "ClOvEr", "cHeRry" };

    //  var sortedWords = words.OrderBy(a = > a, new CaseInsensitiveComparer());

    //  ObjectDumper.Write(sortedWords);
    //}

    //public class CaseInsensitiveComparer : IComparer<string>
    //{
    //  public int Compare(string x, string y)
    //  {
    //    return string.Compare(x, y, StringComparison.OrdinalIgnoreCase);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(orderByDescendingSimple1) {
    // This sample uses orderby and descending to sort a list of doubles from highest to lowest.
    //public void Linq32()
    //{
    //  double[] doubles = { 1.7, 2.3, 1.9, 4.1, 2.9 };

    //  var sortedDoubles =
    //    from d in doubles
    //    orderby d descending
    //    select d;

    //  Console.WriteLine("The doubles from highest to lowest:");
    //  foreach(var d in sortedDoubles)
    //  {
    //    Console.WriteLine(d);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(orderByDescendingSimple2) {
    // This sample uses orderby to sort a list of products by units in stock from highest to lowest.
    //public void Linq33()
    //{
    //  List<Product> products = GetProductList();

    //  var sortedProducts =
    //    from p in products
    //    orderby p.UnitsInStock descending
    //    select p;

    //  ObjectDumper.Write(sortedProducts);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(orderByDescendingComparer) {
    // This sample uses an OrderBy clause with a custom comparer to do a case-insensitive descending sort of the words in an array.
    //public void Linq34()
    //{
    //  string[] words = { "aPPLE", "AbAcUs", "bRaNcH", "BlUeBeRrY", "ClOvEr", "cHeRry" };

    //  var sortedWords = words.OrderByDescending(a = > a, new CaseInsensitiveComparer());

    //  ObjectDumper.Write(sortedWords);
    //}

    //public class CaseInsensitiveComparer : IComparer<string>
    //{
    //  public int Compare(string x, string y)
    //  {
    //    return string.Compare(x, y, StringComparison.OrdinalIgnoreCase);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(thenBySimple) {
    // This sample uses a compound orderby to sort a list of digits, first by length of their name, and then alphabetically by the name itself.
    //public void Linq35()
    //{
    //  string[] digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    //  var sortedDigits =
    //    from d in digits
    //    orderby d.Length, d
    //    select d;

    //  Console.WriteLine("Sorted digits:");
    //  foreach(var d in sortedDigits)
    //  {
    //    Console.WriteLine(d);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(thenByComparer) {
    // This sample uses an OrderBy and a ThenBy clause with a custom comparer to sort first by word length and then by a case-insensitive sort of the words in an array.
    //public void Linq36()
    //{
    //  string[] words = { "aPPLE", "AbAcUs", "bRaNcH", "BlUeBeRrY", "ClOvEr", "cHeRry" };

    //  var sortedWords =
    //    words.OrderBy(a = > a.Length)
    //    .ThenBy(a = > a, new CaseInsensitiveComparer());

    //  ObjectDumper.Write(sortedWords);
    //}

    //public class CaseInsensitiveComparer : IComparer<string>
    //{
    //  public int Compare(string x, string y)
    //  {
    //    return string.Compare(x, y, StringComparison.OrdinalIgnoreCase);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(thenByDescendingSimple) {
    // This sample uses a compound orderby to sort a list of products, first by category, and then by unit price, from highest to lowest.
    //public void Linq37()
    //{
    //  List<Product> products = GetProductList();

    //  var sortedProducts =
    //    from p in products
    //    orderby p.Category, p.UnitPrice descending
    //    select p;

    //  ObjectDumper.Write(sortedProducts);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(thenByDescendingComparer) {
    // This sample uses an OrderBy and a ThenBy clause with a custom comparer to sort first by word length and then by a case-insensitive descending sort of the words in an array.
    //public void Linq38()
    //{
    //  string[] words = { "aPPLE", "AbAcUs", "bRaNcH", "BlUeBeRrY", "ClOvEr", "cHeRry" };

    //  var sortedWords =
    //    words.OrderBy(a = > a.Length)
    //    .ThenByDescending(a = > a, new CaseInsensitiveComparer());

    //  ObjectDumper.Write(sortedWords);
    //}

    //public class CaseInsensitiveComparer : IComparer<string>
    //{
    //  public int Compare(string x, string y)
    //  {
    //    return string.Compare(x, y, StringComparison.OrdinalIgnoreCase);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(reverse) {
    // This sample uses Reverse to create a list of all digits in the array whose second letter is 'i' that is reversed from the order in the original array.
    //public void Linq39()
    //{
    //  string[] digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    //  var reversedIDigits = (
    //    from d in digits
    //    where d[1] == 'i'
    //    select d)
    //    .Reverse();

    //  Console.WriteLine("A backwards list of the digits with a second character of 'i':");
    //  foreach(var d in reversedIDigits)
    //  {
    //    Console.WriteLine(d);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
