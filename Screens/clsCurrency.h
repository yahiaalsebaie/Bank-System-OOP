#pragma once
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	bool _MarkForEdit = false;

	static string _ConvertCurrencyObjectToLine(const clsCurrency& Currency, string Separator = "#//#")
	{
		string CurrencyObj = "";
		CurrencyObj += Currency.Country() + Separator;
		CurrencyObj += Currency.CurrencyCode() + Separator;
		CurrencyObj += Currency.CurrencyName() + Separator;
		CurrencyObj += to_string(Currency._Rate);

		return CurrencyObj;
	}


	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Separator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
			stod(vCurrencyData[3]));

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
	static vector<clsCurrency> _LoadCurrenciesDataFromFile(string FileName = "Currencies.txt")
	{
		vector<clsCurrency> vCurrencies;
		fstream myFile;
		myFile.open(FileName, ios::in);//Read (input) mode.

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				if (line == "")
					continue;
				clsCurrency Currency = _ConvertLineToCurrencyObject(line);
				vCurrencies.push_back(Currency);
			}
			myFile.close();
		}
		return vCurrencies;
	}
	static void _SaveCurrenciesDataToFile(const vector<clsCurrency>& vCurrencies)
	{
		string FileName = "Currencies.txt";
		fstream myFile;
		myFile.open(FileName, ios::out);
		string line;

		if (myFile.is_open())
		{
			for (const clsCurrency& c : vCurrencies)
			{
				if (c._MarkForEdit == false)
				{
					line = _ConvertCurrencyObjectToLine(c);
					myFile << line << endl;
				}
			}
			myFile.close();
		}
	}

	static void _AddDataLineToFile(string FileName, const string DataLine)
	{
		fstream myFile;
		myFile.open(FileName, ios::out | ios::app);

		if (myFile.is_open())
		{
			myFile << DataLine << endl;
			myFile.close();
		}
	}
	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile("Currencies.txt");

		for (clsCurrency& c : vCurrencies)
		{
			if (c.CurrencyCode() == CurrencyCode())
			{
				c = *this; // *this == updated information
				break;
			}
		}
		_SaveCurrenciesDataToFile(vCurrencies);


	}

	/*void _AddNew()
	{
		_AddDataLineToFile("Currencies.txt", _ConvertCurrencyObjectToLine(*this));
	}*/


public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName,
		float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	/*enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailedCountryExists = 2 };*/

	bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

	string Country() const { return _Country; } // Get only
	string CurrencyCode() const { return _CurrencyCode; }
	string CurrencyName() const { return _CurrencyName; }

	void UpdateRate(float newRate)
	{
		_Rate = newRate;
		_Update();
	}

	float Rate() const { return _Rate; }

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		//vector<clsCurrency> vCurrencies;

		fstream myFile;
		myFile.open("Currencies.txt", ios::in); //Read mode

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					myFile.close();
					return Currency;
				}
				//vCurrencies.push_back(Currency);
			}
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{
		//vector<clsCurrency> vCurrencies;
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream myFile;
		myFile.open("Currencies.txt", ios::in); //Read mode

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					myFile.close();
					return Currency;
				}
				//vCurrencies.push_back(Currency);
			}
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency c = clsCurrency::FindByCode(clsString::UpperAllString(CurrencyCode));
		return (!c.IsEmpty());
	}
	static bool IsCurrencyExistByCountryName(string Country)
	{
		clsCurrency c = clsCurrency::FindByCountry(clsString::UpperAllString(Country));
		return (!c.IsEmpty());
	}

	static void PerformIsCurrencyCountryExist(string& Country, string ErrorMessage = "\nCountry is not found, choose another one: ")
	{
		while (!clsCurrency::IsCurrencyExistByCountryName(Country))
		{
			if (ErrorMessage != "") cout << clsUtil::ColorText(ErrorMessage, clsUtil::enColor::ORANGE);
			Country = clsInputValidate::ReadString();
		}
	}
	static void PerformIsCurrencyCodeExist(string& CurrencyCode, string ErrorMessage = "\nCurrency Code is not found, choose another one: ")
	{
		while (!clsCurrency::IsCurrencyExist((CurrencyCode)))
		{
			if (ErrorMessage != "") cout << clsUtil::ColorText(ErrorMessage, clsUtil::enColor::ORANGE);
			CurrencyCode = clsInputValidate::ReadString();
		}
	}

	//enSaveResults Save()
	//{
	//	switch (_Mode)
	//	{
	//	case clsCurrency::EmptyMode:
	//		if (IsEmpty())
	//			return enSaveResults::svFaildEmptyObject;

	//	case clsCurrency::UpdateMode:
	//	{
	//		_Update();
	//		return enSaveResults::svSucceeded;
	//	}
	//	case clsCurrency::AddNewMode:
	//	{
	//		if (clsCurrency::IsCurrencyExist(_Country))
	//			return enSaveResults::svFailedCountryExists;
	//		else
	//		{
	//			_AddNew();
	//			_Mode = enMode::UpdateMode;
	//			return enSaveResults::svSucceeded;
	//		}

	//	}

	//	}
	//}


	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}




};
