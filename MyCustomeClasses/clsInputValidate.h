#pragma once
#include "clsDate.h"
#include "clsUtil.h"
#include <cctype>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class clsInputValidate

{

private:
	static void _PrintMessage(const string& Message)
	{
		if (Message != "") cout << Message;
	}



public:

	// -----------------------------------------------------------------------
	//  Integer - with full cin-fail recovery
	// -----------------------------------------------------------------------
	static int ReadIntNumber(string Message = "Please enter a number: ", string ErrorMessage = "Invalid Number, Enter a valid one : ")
	{
		//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int Number = 0;
		if (Message != "") cout << Message;;
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
	static float ReadFloatNumber(string Message = "", string ErrorMessage = "Invalid Number, Enter a valid one : ")
	{
		//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		float Number = 0;
		if (Message != "") cout << Message;;
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
	static double ReadDblNumber(string Message = "", string ErrorMessage = "Invalid Number, Enter a valid one : ")
	{
		//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		float Number = 0;
		if (Message != "") cout << Message;;
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
	static int ReadPositiveNumber(string Message = "")
	{
		//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int Number = 0;
		do
		{
			if (Message != "") cout << Message;;
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
	static double ReadPositiveDblNumber(string Message = "")
	{
		//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
		double Number = 0;
		do
		{
			if (Message != "") cout << Message;;
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
			if (Message != "") cout << Message;;
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
			if (Message != "") cout << Message;;
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
	static string ReadString(string Message = "")
	{
		string Text = "";
		if (Message != "") cout << Message;
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

	template <typename T>
	static T ReadNumber(string Message = "Please enter a number: ", string ErrorMessage = "Invalid Number, Enter a valid one : ")
	{
		T Number{};
		string Input = "";
		while (true)
		{
			_PrintMessage(Message);

			getline(cin, Input);

			if (_TryParse(Input, Number)) return Number;

			cout << ErrorMessage << endl;
		}
		return Number;
	}
	template <typename T>
	static T ReadNumberInRange(T From, T To, string InputMessage = "Enter number: ", string ErrorMessage = "Invalid Number, Enter a valid one : ", bool   AutoRangeMessage = true)
	{
		T Number{};
		if (From > To) clsUtil::Swap(From, To);
		string Message = "";

		do
		{

			if (AutoRangeMessage)
			{
				stringstream ss;
				ss << InputMessage << " [" << From << " to " << To << "]: ";
				Message = ss.str();
			}
			else
				Message = InputMessage;

			Number = ReadNumber<T>(Message, ErrorMessage);

			if (Number < From || Number > To)
				cout << ErrorMessage << endl;

		} while (Number < From || Number > To);
		return Number;
	}
	template <typename T>
	static void ReadVectorNumbers(vector<T>& vNumbers)
	{
		T Number;
		char AddMore = 'Y';

		do
		{
			Number = ReadNumber();
			vNumbers.push_back(Number);

			cout << "Do you want to add more? [Y/N] : ";
			cin >> AddMore;

		} while (AddMore == 'y' || AddMore == 'Y');
	}

	template <typename T>
	static bool IsNumberBetween(T Number, T From, T To, bool IncludedRangedNumbers = false)
	{
		if (From > To) clsUtil::Swap(From, To);

		return IncludedRangedNumbers ? (Number >= From && Number <= To)
			: (Number > From && Number < To);
	}

};

