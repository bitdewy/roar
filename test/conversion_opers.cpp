// Copyright 2014, bitdewy@gmail.com
// The MIT License (MIT)

#include "CppUnitTest.h"
#include "../roar/linq/linq.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

// http://code.msdn.microsoft.com/LINQ-Conversion-Operators-e4e59714

TEST_CLASS(ConversionOperators) {
public:
  TEST_METHOD(toArray) {
    // This sample uses ToArray to immediately evaluate a sequence into an array.
    //public void Linq54()
    //{
    //  double[] doubles = { 1.7, 2.3, 1.9, 4.1, 2.9 };

    //  var sortedDoubles =
    //    from d in doubles
    //    orderby d descending
    //    select d;
    //  var doublesArray = sortedDoubles.ToArray();

    //  Console.WriteLine("Every other double from highest to lowest:");
    //  for (int d = 0; d < doublesArray.Length; d += 2)
    //  {
    //    Console.WriteLine(doublesArray[d]);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(toList) {
    // This sample uses ToList to immediately evaluate a sequence into a List<T>.
    //public void Linq55()
    //{
    //  string[] words = { "cherry", "apple", "blueberry" };

    //  var sortedWords =
    //    from w in words
    //    orderby w
    //    select w;
    //  var wordList = sortedWords.ToList();

    //  Console.WriteLine("The sorted word list:");
    //  foreach(var w in wordList)
    //  {
    //    Console.WriteLine(w);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(toDictionary) {
    // This sample uses ToDictionary to immediately evaluate a sequence and a related key expression into a dictionary.
    //public void Linq56()
    //{
    //  var scoreRecords = new[] { new{ Name = "Alice", Score = 50 },
    //    new{ Name = "Bob", Score = 40 },
    //    new{ Name = "Cathy", Score = 45 }
    //  };

    //  var scoreRecordsDict = scoreRecords.ToDictionary(sr = > sr.Name);

    //  Console.WriteLine("Bob's score: {0}", scoreRecordsDict["Bob"]);
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

  TEST_METHOD(ofType) {
    // This sample uses OfType to return only the elements of the array that are of type double.
    //public void Linq57()
    //{
    //  object[] numbers = { null, 1.0, "two", 3, "four", 5, "six", 7.0 };

    //  var doubles = numbers.OfType<double>();

    //  Console.WriteLine("Numbers stored as doubles:");
    //  foreach(var d in doubles)
    //  {
    //    Console.WriteLine(d);
    //  }
    //}
    Assert::Fail(L"TODO(bitdewy): ");
  }

};

}  // namespace test
