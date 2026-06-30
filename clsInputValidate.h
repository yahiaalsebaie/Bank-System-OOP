#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "clsUtil.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate

{
private:


public:

    // -----------------------------------------------------------------------
    //  Integer - with full cin-fail recovery
    // -----------------------------------------------------------------------
    static int ReadIntNumber(string Message = "Please enter a number: ", string ErrorMessage = "Invalid Number, Enter a valid one : ")
    {
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int Number = 0;
        cout << Message;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
            cin >> Number;
        }
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Float
    // -----------------------------------------------------------------------
    static float ReadFloatNumber(string Message, string ErrorMessage = "Invalid Number, Enter a valid one : ")
    {
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        float Number = 0;
        cout << Message;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
            cin >> Number;
        }
        return Number;
    }
    // -----------------------------------------------------------------------
    //  Double
    // -----------------------------------------------------------------------
    static double ReadDblNumber(string Message, string ErrorMessage = "Invalid Number, Enter a valid one : ")
    {
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        float Number = 0;
        cout << Message;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
            cin >> Number;
        }
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Positive integer (> 0)
    // -----------------------------------------------------------------------
    static int ReadPositiveNumber(string Message)
    {
   //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int Number = 0;
        do
        {
            cout << Message;
            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one: ";
                cin >> Number;
            }
        } while (Number <= 0);
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Unsigned long long - rejects negative sign
    // -----------------------------------------------------------------------
    static unsigned long long ReadUnsignedLongPositiveNumber(
        bool   isIncludeZero = false,
        string Message = "Please enter a number: ")
    {
   //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
        unsigned long long Number = 0;
        do
        {
            cout << Message;
            cin >> ws;
            if (cin.peek() == '-')
                cin.setstate(ios::failbit);
            else
                cin >> Number;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one: ";
                cin >> ws;
                if (cin.peek() == '-')
                    cin.setstate(ios::failbit);
                else
                    cin >> Number;
            }
        } while (isIncludeZero ? (Number < 0) : (Number <= 0));
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Long long positive
    // -----------------------------------------------------------------------
    static long long ReadLongPositiveNumber(
        bool   isIncludeZero = false,
        string Message = "Please enter a number: ")
    {
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        long long Number = 0;
        do
        {
            cout << Message;
            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one: ";
                cin >> Number;
            }
        } while (isIncludeZero ? (Number < 0) : (Number <= 0));
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Integer within [From, To] inclusive
    // -----------------------------------------------------------------------

    static int ReadNumberInRange(int From, int To, string InputMessage = "Enter number: ", string ErrorMessage = "Invalid Number, Enter a valid one : ", bool   AutoRangeMessage = true)
    {
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int Number = 0;
        do
        {
            if (AutoRangeMessage)
                cout << InputMessage << " [" << From << " to " << To << "]: ";
            else
                cout << InputMessage;

            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ErrorMessage;
                cin >> Number;
            }
        } while (Number < From || Number > To);
        return Number;
    }
    //Double Number 
    static double ReadDblNumberBetween(double From, double To, string InputMessage = "Enter number: ", string ErrorMessage = "Invalid Number, Enter a valid one : ", bool   AutoRangeMessage = true)
    {
      //  cin.ignore(numeric_limits<streamsize>::max(), '\n');
        double Number = 0;
        do
        {
            if (AutoRangeMessage)
                cout << InputMessage << " [" << From << " to " << To << "]: ";
            else
                cout << InputMessage;

            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ErrorMessage;
                cin >> Number;
            }
        } while (Number < From || Number > To);
        return Number;
    }

    // -----------------------------------------------------------------------
    //  Full-line string
    // -----------------------------------------------------------------------
    static string ReadText(string Message)
    {
       // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string Text = "";
        cout << Message;
        getline(cin >> ws, Text);
        return Text;
    }

    // -----------------------------------------------------------------------
    //  Fill a vector of integers interactively
    // -----------------------------------------------------------------------
    static void ReadVectorNumbers(vector<int>& vNumbers)
    {
        char AddMore = 'y';
        do
        {
            int Number;
            cout << "Enter a Number: ";
            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one: ";
                cin >> Number;
            }
            vNumbers.push_back(Number);
            cout << "Add more Numbers? (y/n): ";
            cin >> AddMore;
        } while (AddMore == 'y' || AddMore == 'Y');
    }


    // -----------------------------------------------------------------------
    //  is Number Between 2 numbers within [From, To] inclusive
    // -----------------------------------------------------------------------

    static bool IsNumberBetween(int Number, int From, int To, bool IncludedRangedNumbers = false)
    {
        if (From > To) clsUtil::Swap(From, To);
        return IncludedRangedNumbers ? (Number >= From && Number <= To)
            : (Number > From && Number < To);
        /*if (IncludedRangedNumbers)
            return (Number >= From && Number <= To);

        return (Number > From && Number < To);*/
    }
    static bool IsNumberBetween(float Number, float From, float To, bool IncludedRangedNumbers = false)
    {
        if (From > To) clsUtil::Swap(From, To);
        return IncludedRangedNumbers ? (Number >= From && Number <= To)
            : (Number > From && Number < To);
    }
    static bool IsNumberBetween(double Number, double From, double To, bool IncludedRangedNumbers = false)
    {
        if (From > To) clsUtil::Swap(From, To);
        return IncludedRangedNumbers ? (Number >= From && Number <= To)
            : (Number > From && Number < To);
    }

    static bool IsDateBetween(clsDate Date, clsDate Date1From, clsDate Date2To)
    {
        if (clsDate::IsDate1AfterDate2(Date1From, Date2To)) clsUtil::Swap(Date1From, Date2To);

        return (clsDate::IsDate1BeforeDate2(Date, Date2To) && (clsDate::IsDate1AfterDate2(Date, Date1From)));
    }

    static	bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static bool IsValidName(const string& Name)
    {
        // Using Short Range Based..
        if (Name.empty()) return false;
        for (const char& c : Name) // Const and &Ref to avoid making copy or edit.
        {
            if (!isalpha(c) && c != ' ') return false;
        }
        return true;

        // Or Using Normal Index Based and Array..
       /* for (short i = 0; i < Name.length(); i++)
        {
           const char& c = Name[i];
            if (!isalpha(c) && c != ' ') return false;
        }
        return true;*/
    }
    static bool IsValidEmail(const string& Email)
    {
        //Return true if email contains '@' and '.' , Otherwise return false.
        return Email.find('@') != string::npos && Email.find('.') != string::npos;
    }
    static bool IsValidPhone(const string& Phone)
    {
        //Return true if phone contains only digits, Otherwise return false.
        //if (Phone.length() != 11) return false; //Egyptian Phone Number Length is 11 Digits, but if you want to allow any length, just remove this line.
        for (const char& c : Phone)
        {
            if (!isdigit(c) && c != '+') return false;
        }
        return true;
    }

};

