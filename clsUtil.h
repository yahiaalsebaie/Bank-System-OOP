#pragma once
#pragma warning(disable : 4996)

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include "clsDate.h"

class clsUtil
{
public:

    enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4, MixChars = 5 };
    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }
    static int RandomNumber(int From, int To) 
    {
        return rand() % (To - From + 1) + From;
    }

    static string EncryptText(std::string txt, short Key) 
    {
        for (size_t i = 0; i < txt.length(); i++)
            txt[i] += Key;
        return txt;
    }

    static string DecryptText(std::string txt, short Key) 
    {
        for (size_t i = 0; i < txt.length(); i++)
            txt[i] -= Key;
        return txt;
    }

    static void PrintInvertedNumberPattern(int Number) 
    {
        for (int i = Number; i >= 1; i--) {
            for (int j = 1; j <= i; j++) std::cout << i;
            std::cout << "\n";
        }
    }

    static bool GuessPassword(std::string Password) 
    {
        std::string word = "";
        int Counter = 0;
        for (int i = 65; i <= 90; i++) {
            for (int j = 65; j <= 90; j++) {
                for (int k = 65; k <= 90; k++) {
                    word = std::string(1, char(i)) + char(j) + char(k);
                    Counter++;
                    if (word == Password) {
                        std::cout << "Found after " << Counter << " trials.\n";
                        return true;
                    }
                }
            }
        }
        return false;
    }

    static string GetSystemDateTime() 
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        return std::to_string(now->tm_year + 1900) + "-" +
            std::to_string(now->tm_mon + 1) + "-" +
            std::to_string(now->tm_mday) + " | " +
            std::to_string(now->tm_hour) + ":" +
            std::to_string(now->tm_min) + ":" +
            std::to_string(now->tm_sec);
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {
        case SmallLetter:
            return (char)RandomNumber(97, 122);
        case CapitalLetter:
            return (char)RandomNumber(65, 90);
        case SpecialChar:
            return (char)RandomNumber(33, 47);
        case Digit:
            return (char)RandomNumber(48, 57);
       // default:
         //   return (char)RandomNumber(33, 122);
        }
    }
    static string GenerateWord(enCharType CharType, short Length = 4)
    {
        string word = "";
        for (short i = 0; i < Length; i++)
        {
            word += GetRandomCharacter(CharType);
        }
        return word;
    }
    static string GenerateKey(enCharType CharType = CapitalLetter, short NumberOfParts = 4)
    {
        string RandomKey = "";
        for (short i = 1; i < NumberOfParts; i++)
        {
            RandomKey += GenerateWord(CharType) + '-';
        }
        return RandomKey += GenerateWord(CharType);
    }
    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

   //Array
    static void ShuffleArray(int arr[], int arrLength)
    {
        // Loop through each element of the array.
        // For each iteration, swap two randomly chosen elements.
        for (int i = 0; i < arrLength; i++)
        {
            // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
            // Subtract 1 to convert it to a valid 0-based index.
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
            // Swap the elements at the two randomly chosen indices.
            Swap(arr[index1], arr[index2]);
        }
    }
    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }
    static void ShuffleArray2ndMethod(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }
    static void ShuffleArray3rdMethod(int arr[100], int arrLength)
    {
        int RandomI;
        for (short i = 0; i < arrLength; i++)
        {
            RandomI = RandomNumber(0, arrLength - 1);
            swap(arr[i], arr[RandomI]);
        }
    }
    static void FillArrayWithOrderedNumbers(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;

    }
    static void FillArrayWith1toN(int arr[100], int& arrLength)
    {
        // Function: FillArrayWith1toN
 // Purpose: Fills an array with sequential numbers from 1 to N, where N is the array length.
 // Parameters:
 //   - arr: The integer array to fill (capacity 100).
 //   - arrLength: The number of elements to fill in the array.
        // Loop through each index and assign the value (index + 1) to that element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;
    }
    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From = 1, int To = 100)
    {
        for (short i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }
    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, WordLength);
    }
    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }


    //Swap
  // Purpose: Swaps the values of two integers.
  // Parameters:
  //   - A: Reference to the first integer.
  //   - B: Reference to the second integer.
    static void Swap(int& A, int& B)
    {
        int Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }
    static void Swap(float& A, float& B)
    {
        float Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }
    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);
    }

    //Tabs and Spaces
    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 0; i < NumberOfTabs; i++)
            t += "\t";

        return t;
    }
    static string  Spaces(short NumberOfSpaces)
    {
        string s = "";

        for (int i = 0; i < NumberOfSpaces; i++)
            s += " ";

        return s;
    }
    static void PrintTabs(short NumberOfTabs)
    {
        cout << Tabs(NumberOfTabs);
    }
    static void PrintSpaces(short NumberOfSpaces)
    {
        cout << Spaces(NumberOfSpaces);
    }


};

