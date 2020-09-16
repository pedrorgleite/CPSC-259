#include "CppUnitTest.h"

/*
We need to 'include' the header file(s) for the project we are testing
*/
extern "C" {
#include "lab1_inlab_exercises.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CPSC259_2018W1_Lab1_InLabUnitTests
{
  TEST_CLASS(UnitTest1)
  {
  public:

    TEST_METHOD(ReverseArrayTest_SizeOne)
    {
      int array[] = { 2014 };
      int array_length = sizeof(array) / sizeof(*array);
      reverse_array(array, array_length);
      Assert::AreEqual(2014, array[0]);
    }

    TEST_METHOD(ReverseArrayTest_EvenSize)
    {
      int array[] = { 13, 21, 34, 55, 89, 144 }; // Fibonacci
      int reversedarray[] = { 144, 89, 55, 34, 21, 13 };
      int array_length = sizeof(array) / sizeof(*array);
      int i = 0;
      reverse_array(reversedarray, array_length);
      for (i = 0; i < array_length; ++i) {
        Assert::AreEqual(array[i], reversedarray[i]);
      }
    }

    TEST_METHOD(ReverseArrayTest_OddSize)
    {
      int array[] = { 1, 8, 27, 64, 125 }; // Cubes
      int reversedarray[] = { 125, 64, 27, 8, 1 };
      int array_length = sizeof(array) / sizeof(*array);
      int i = 0;
      reverse_array(reversedarray, array_length);
      for (i = 0; i < array_length; ++i) {
        Assert::AreEqual(array[i], reversedarray[i]);
      }
    }

    TEST_METHOD(LengthTest_SizeZero_01)
    {
      char string[] = "";
      Assert::AreEqual(length(string), 0);
    }

    TEST_METHOD(LengthTest_SizeZero_02)
    {
      char string[] = { '\0' };
      Assert::AreEqual(length(string), 0);
    }

    TEST_METHOD(LengthTest_NonTrivialLength_01)
    {
      char string[] = "Able was I, ere I saw Elba";
      Assert::AreEqual(length(string), 26);
    }

    TEST_METHOD(LengthTest_NonTrivialLength_02)
    {
      char string[] = { 'K', 'a', 'w', 'a', 's', 'a', 'k', 'i', '\0' };
      Assert::AreEqual(length(string), 8);
    }

    TEST_METHOD(CountLettersTest_EmptyString_01)
    {
      char string[] = "";
      Assert::AreEqual(count_letters(string, '\0'), 0);
    }

    TEST_METHOD(CountLettersTest_EmptyString_02)
    {
      char string[] = { '\0' };
      Assert::AreEqual(count_letters(string, '\0'), 0);
    }

    TEST_METHOD(CountLettersTest_SizeOne_PositiveTest)
    {
      char string[] = "A";
      Assert::AreEqual(count_letters(string, 'A'), 1);
    }

    TEST_METHOD(CountLettersTest_SizeOne_NegativeTest)
    {
      char string[] = "A";
      Assert::AreEqual(count_letters(string, 'a'), 0);
    }

    TEST_METHOD(CountLettersTest_NonTrivialLength_AllCharFound)
    {
      char string[] = "AAAAAAAAAA";
      Assert::AreEqual(count_letters(string, 'A'), 10);
    }

    TEST_METHOD(CountLettersTest_NonTrivialLength_FirstCharFound)
    {
      char string[] = "ABCDEFGHIJ";
      Assert::AreEqual(count_letters(string, 'A'), 1);
    }

    TEST_METHOD(CountLettersTest_NonTrivialLength_MiddleCharFound)
    {
      char string[] = "ABCDEFGHIJ";
      Assert::AreEqual(count_letters(string, 'E'), 1);
    }

    TEST_METHOD(CountLettersTest_NonTrivialLength_LastCharFound)
    {
      char string[] = "ABCDEFGHIJ";
      Assert::AreEqual(count_letters(string, 'J'), 1);
    }

    TEST_METHOD(CountLettersTest_NonTrivialLength_NoCharFound)
    {
      char string[] = "ABCDEFGHIJ";
      Assert::AreEqual(count_letters(string, 'Z'), 0);
    }

    TEST_METHOD(IsPalindromeTest_EmptyString)
    {
      char string[] = "";
      Assert::AreEqual(is_palindrome(string), 1);
    }

    TEST_METHOD(IsPalindromeTest_NegativeTestOdd)
    {
      char string[] = "the";
      Assert::AreEqual(is_palindrome(string), 0);
    }

    TEST_METHOD(IsPalindromeTest_NegativeTestEven)
    {
      char string[] = "computer";
      Assert::AreEqual(is_palindrome(string), 0);
    }

    TEST_METHOD(IsPalindromeTest_PositiveEven)
    {
      char string[] = "abba";
      Assert::AreEqual(is_palindrome(string), 1);
    }

    TEST_METHOD(IsPalindromeTest_PositiveOdd)
    {
      char string[] = "qwerty ytrewq";
      Assert::AreEqual(is_palindrome(string), 1);
    }

    TEST_METHOD(IsPalindromeTest_PositiveSymmetricSpaces)
    {
      char string[] = "able was i ere i saw elba";
      Assert::AreEqual(is_palindrome(string), 1);
    }

    TEST_METHOD(IsPalindromeTest_PositiveAsymmetricSpaces)
    {
      char string[] = "a nut for a jar of tuna";
      Assert::AreEqual(is_palindrome(string), 1);
    }

    TEST_METHOD(IsPalindromeTest_PositiveAllSpacesOdd)
    {
      char string[] = "   ";
      Assert::AreEqual(is_palindrome(string), 1);
    }

    TEST_METHOD(IsPalindromeTest_PositiveAllSpacesEven)
    {
      char string[] = "    ";
      Assert::AreEqual(is_palindrome(string), 1);
    }

    TEST_METHOD(IsPalindromeTest_AsymmetricMultipleSpaces)
    {
      char string[] = "a  nut for a jar  of tuna";
      Assert::AreEqual(is_palindrome(string), 1);
    }

  };
}