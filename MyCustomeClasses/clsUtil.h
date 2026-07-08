#pragma once
#pragma warning(disable : 4996)

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include "clsDate.h"
#include <type_traits>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stdexcept>

class clsUtil
{
public :
    enum class enColor : unsigned char //char == 256, colors are just 50 color.
        //Using default int consumes 4 MB of memory...
        //Using an unsigned char consumes only 1 MB, saved 75% of the space with just one word!..
    {
        // --- (Standard) ---
        BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,

        // --- (Bright / Neon) ---
        BRIGHT_BLACK, BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW,
        BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE,

        // --- (Warm Colors) ---
        ORANGE, DARK_ORANGE, LIGHT_ORANGE, PINK, HOT_PINK,
        DEEP_PINK, MAROON, CRIMSON, BROWN, GOLD, BEIGE,

        // --- (Cool Colors) ---
        PURPLE, VIOLET, INDIGO, DEEP_BLUE, SKY_BLUE, LIGHT_BLUE,
        TURQUOISE, TEAL, EMERALD, MINT, OLIVE, LIME,

        // --- (Grayscale & Metallic) ---
        DARK_GRAY, GRAY, LIGHT_GRAY, SILVER, CHARCOAL, SLATE,

        RESET
    };

private:
    static string _GetColorEscapeCode(enColor Color) {
        switch (Color) {
            //Standard 
        case enColor::BLACK:        return "\033[30m";
        case enColor::RED:          return "\033[31m";
        case enColor::GREEN:        return "\033[32m";
        case enColor::YELLOW:       return "\033[33m";
        case enColor::BLUE:         return "\033[34m";
        case enColor::MAGENTA:      return "\033[35m";
        case enColor::CYAN:         return "\033[36m";
        case enColor::WHITE:        return "\033[37m";

            // bright colors
        case enColor::BRIGHT_BLACK:   return "\033[90m";
        case enColor::BRIGHT_RED:     return "\033[91m";
        case enColor::BRIGHT_GREEN:   return "\033[92m";
        case enColor::BRIGHT_YELLOW:  return "\033[93m";
        case enColor::BRIGHT_BLUE:    return "\033[94m";
        case enColor::BRIGHT_MAGENTA: return "\033[95m";
        case enColor::BRIGHT_CYAN:    return "\033[96m";
        case enColor::BRIGHT_WHITE:   return "\033[97m";
            
            //ANSI 256 Color Palette.
            // warm shades
            //38->Foreground , 5-> 256-color mode , then color number 208 = orange.
        case enColor::ORANGE:         return "\033[38;5;208m"; 
        case enColor::DARK_ORANGE:    return "\033[38;5;166m";
        case enColor::LIGHT_ORANGE:   return "\033[38;5;215m";
        case enColor::PINK:           return "\033[38;5;211m";
        case enColor::HOT_PINK:       return "\033[38;5;205m";
        case enColor::DEEP_PINK:      return "\033[38;5;198m";
        case enColor::MAROON:         return "\033[38;5;88m";
        case enColor::CRIMSON:        return "\033[38;5;160m";
        case enColor::BROWN:          return "\033[38;5;94m";
        case enColor::GOLD:           return "\033[38;5;220m";
        case enColor::BEIGE:          return "\033[38;5;223m";

            // cool gradients
        case enColor::PURPLE:         return "\033[38;5;93m";
        case enColor::VIOLET:         return "\033[38;5;129m";
        case enColor::INDIGO:         return "\033[38;5;55m";
        case enColor::DEEP_BLUE:      return "\033[38;5;19m";
        case enColor::SKY_BLUE:       return "\033[38;5;111m";
        case enColor::LIGHT_BLUE:     return "\033[38;5;153m";
        case enColor::TURQUOISE:      return "\033[38;5;43m";
        case enColor::TEAL:           return "\033[38;5;30m";
        case enColor::EMERALD:        return "\033[38;5;41m";
        case enColor::MINT:           return "\033[38;5;121m";
        case enColor::OLIVE:          return "\033[38;5;100m";
        case enColor::LIME:           return "\033[38;5;154m";

            // Grayscale & Metallic
        case enColor::DARK_GRAY:      return "\033[38;5;236m";
        case enColor::GRAY:           return "\033[38;5;244m";
        case enColor::LIGHT_GRAY:     return "\033[38;5;250m";
        case enColor::SILVER:         return "\033[38;5;7m";
        case enColor::CHARCOAL:       return "\033[38;5;234m";
        case enColor::SLATE:          return "\033[38;5;66m";

        case enColor::RESET:
        default:                      return "\033[0m";
        }
    }

    // Helper: Convert HEX to RGB
    static void _HexToRGB(const string& Hex, unsigned char& R, unsigned char& G, unsigned char& B) 
    {
        string cleanHex = Hex;
        if (cleanHex[0] == '#') cleanHex = cleanHex.substr(1);
        
        // Convert to uppercase for stoi
        for (auto& c : cleanHex) c = toupper(c);
        
        if (cleanHex.length() != 6) throw std::invalid_argument("Invalid HEX color format. Expected 6 characters.");
        
        R = (unsigned char)stoi(cleanHex.substr(0, 2), nullptr, 16);
        G = (unsigned char)stoi(cleanHex.substr(2, 2), nullptr, 16);
        B = (unsigned char)stoi(cleanHex.substr(4, 2), nullptr, 16);
    }

    // Helper: Convert HSL to RGB // HSL -> Hue Saturation Lightness
    static void _HSLToRGB(float H, float S, float L, unsigned char& R, unsigned char& G, unsigned char& B) 
    { //computer only understand RGB
        // Normalize H to 0-360, S and L to 0-1
        // HSL color(H: 0 - 360, S : 0 - 100, L : 0 - 100)
        H = fmod(H, 360.0f); //Floating-point Modulus, floating mod% Cuz mod% only in int
        if (H < 0) H += 360.0f; // if (H == -30) then (H += 360) will be 330.
        S /= 100.0f;
        L /= 100.0f;

        float C = (1.0f - fabs(2.0f * L - 1.0f)) * S; //Chroma: The higher the color intensity, the more intense the color.
        float X = C * (1.0f - fabs(fmod(H / 60.0f, 2.0f) - 1.0f)); //An intermediate value between two colors.
        float m = L - C / 2.0f;//Adding final brightness.

        float r, g, b;

        if (H >= 0 && H < 60) {
            r = C; g = X; b = 0; //Between Red and Yellow
        } else if (H >= 60 && H < 120) {
            r = X; g = C; b = 0; //Between Green and Cyan
        } else if (H >= 120 && H < 180) {
            r = 0; g = C; b = X;
        } else if (H >= 180 && H < 240) {
            r = 0; g = X; b = C;
        } else if (H >= 240 && H < 300) {
            r = X; g = 0; b = C;
        } else {
            r = C; g = 0; b = X;
        }
        // RGB -> 0-255
        R = (unsigned char)round((r + m) * 255.0f);
        G = (unsigned char)round((g + m) * 255.0f);
        B = (unsigned char)round((b + m) * 255.0f);
    }

    // Helper: Create ANSI escape code from RGB
    static string _GetRGBEscapeCode(unsigned char R, unsigned char G, unsigned char B) 
    {
        return "\033[38;2;" + std::to_string(R) + ";" + std::to_string(G) + ";" + std::to_string(B) + "m";
    }

public:

    // Original ColorText with enum
    static string ColorText(const string& Text, enColor Color)
    {
        return _GetColorEscapeCode(Color) + Text + _GetColorEscapeCode(enColor::RESET);
    }

    // ColorText with RGB values
    static string ColorText(const string& Text, unsigned char R, unsigned char G, unsigned char B) 
    {
        return _GetRGBEscapeCode(R, G, B) + Text + _GetColorEscapeCode(enColor::RESET);
    }

    // ColorText with HEX color (e.g., "96b395" or "#96b395")
    static string ColorText(const string& Text, const string& HexColor) 
    {
        unsigned char R, G, B;
        _HexToRGB(HexColor, R, G, B);
        return ColorText(Text, R, G, B);
    }

    // ColorText with HSL color (H: 0-360, S: 0-100, L: 0-100)
    static string ColorTextHSL(const string& Text, float H, float S, float L) 
    {
        unsigned char R, G, B;
        _HSLToRGB(H, S, L, R, G, B);
        return ColorText(Text, R, G, B);
    }

    // Original PrintColoredText with enum
    static void PrintColoredText(const string& Text, enColor Color) 
    {
        cout << _GetColorEscapeCode(Color) << Text << _GetColorEscapeCode(enColor::RESET);
    }

    // PrintColoredText with RGB values
    static void PrintColoredText(const string& Text, unsigned char R, unsigned char G, unsigned char B) 
    {
        cout << _GetRGBEscapeCode(R, G, B) << Text << _GetColorEscapeCode(enColor::RESET);
    }

    // PrintColoredText with HEX color - PrintColoredTextHex
    static void PrintColoredText(const string& Text, const string& HexColor) 
    {
        unsigned char R, G, B;
        _HexToRGB(HexColor, R, G, B);
        PrintColoredText(Text, R, G, B);
    }

    // PrintColoredText with HSL color - PrintColoredTextHSL
    static void PrintColoredTextHSL(const string& Text, float H, float S, float L) {
        unsigned char R, G, B;
        _HSLToRGB(H, S, L, R, G, B);
        PrintColoredText(Text, R, G, B);
    }

    // Original PrintColoredTextLine with enum
    static void PrintColoredTextLine(const string& Text, enColor Color) {
        cout << _GetColorEscapeCode(Color) << Text << _GetColorEscapeCode(enColor::RESET) << endl;
    }

    // PrintColoredTextLine with RGB values
    static void PrintColoredTextLine(const string& Text, unsigned char R, unsigned char G, unsigned char B) {
        cout << _GetRGBEscapeCode(R, G, B) << Text << _GetColorEscapeCode(enColor::RESET) << endl;
    }

    // PrintColoredTextLine with HEX color - PrintColoredTextLinHex
    static void PrintColoredTextLine(const string& Text, const string& HexColor) {
        unsigned char R, G, B;
        _HexToRGB(HexColor, R, G, B);
        PrintColoredTextLine(Text, R, G, B);
    }

    // PrintColoredTextLine with HSL color - PrintColoredTextLineHSL
    static void PrintColoredTextLineHSL(const string& Text, float H, float S, float L) {
        unsigned char R, G, B;
        _HSLToRGB(H, S, L, R, G, B);
        PrintColoredTextLine(Text, R, G, B);
    }

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
            t += " ";

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

    template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type> //to avoid compile error
    static string ConvertNumberToText(T Number)
    {
        if (Number == 0) return "";

        if (Number >= 1 && Number < 20)
        {
            static const string arr[]{
                "","One","Two","Three","Four","Five","Six","Seven",
                "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
                "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return arr[Number];
        }

        if (Number >= 20 && Number < 100)
        {
            static const string arr[]{
                "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return arr[Number / 10] + (Number % 10 != 0 ? " " + ConvertNumberToText(Number % 10) : "");
        }


        if (Number >= 100 && Number < 1000)
        {
            return ConvertNumberToText(Number / 100) + " Hundred" + (Number % 100 != 0 ? " " + ConvertNumberToText(Number % 100) : "");
        }

        // Thousands: 1,000 to 999,999
       if (Number >= static_cast<T>(1000) && Number < static_cast<T>(1000000))
        {
            return ConvertNumberToText(Number / 1000) + " Thousand" + (Number % 1000 != 0 ? " " + ConvertNumberToText(Number % 1000) : "");
        }

       // Millions: 1,000,000 to 999,999,999
       if (Number >= static_cast<T>(1000000) && Number < static_cast<T>(1000000000))
        {
            return ConvertNumberToText(Number / 1000000) + " Million" + (Number % 1000000 != 0 ? " " + ConvertNumberToText(Number % 1000000) : "");
        }

       // Billions: 1,000,000,000 to 999,999,999,999
       if (Number >= static_cast<T>(1000000000) && Number < static_cast<T>(1000000000000ULL))
        {
            return ConvertNumberToText(Number / 1000000000) + " Billion" + (Number % 1000000000 != 0 ? " " + ConvertNumberToText(Number % 1000000000) : "");
        }

       // Trillions: 1,000,000,000,000 to 999,999,999,999,999
        if (Number >= static_cast<T>(1000000000000ULL) && Number < static_cast<T>(1000000000000000ULL))
        {
            return ConvertNumberToText(Number / 1000000000000ULL) + " Trillion" + (Number % 1000000000000ULL != 0 ? " " + ConvertNumberToText(Number % 1000000000000ULL) : "");
        }

        // Quadrillions: 1,000,000,000,000,000 to 999,999,999,999,999,999
        if (Number >= static_cast<T>(1000000000000000ULL) && Number < static_cast<T>(1000000000000000000ULL))
        {
            return ConvertNumberToText(Number / 1000000000000000ULL) + " Quadrillion" + (Number % 1000000000000000ULL != 0 ? " " + ConvertNumberToText(Number % 1000000000000000ULL) : "");
        }

        // Quintillions: 1,000,000,000,000,000,000 to 9,223,372,036,854,775,807 
   // unsigned long long int RealMaxNumber = 18'446'744'073'709'551'615ULL;
        if (Number >= static_cast<T>(1000000000000000000ULL))
        {
            return ConvertNumberToText(Number / 1000000000000000000ULL) + " Quintillion" + (Number % 1000000000000000000ULL != 0 ? " " + ConvertNumberToText(Number % 1000000000000000000ULL) : "");
        }

        return "Out of range...";
    }

    template <typename T>
   static string ConvertNumberTo1eNum(/*unsigned long long*/ T number)
    {
        if (number == 0) return "0e0";
        short count = 0;

        while (number >= 10)
        {
            number /= 10;
            count++;
        }
        return to_string(number) + "e" + to_string(count);
    }

};


