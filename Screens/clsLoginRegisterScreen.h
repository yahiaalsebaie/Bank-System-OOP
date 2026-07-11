#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class clsLoginRegisterScreen :protected clsScreen
{
private:

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{

		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(35) << LoginRegisterRecord.DateTime;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(20) << LoginRegisterRecord.UserName;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(20) << LoginRegisterRecord.Password;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(10) << LoginRegisterRecord.Permissions;

	}


public:

	static void ShowLoginRegistersScreen()
	{

		vector <clsUser::stLoginRegisterRecord> stRecords = clsUser::GetLoginRegisterList();
		string SeparatorLine = "\n_________________________________________________________________________________________________________\n";
		string NumberOfRecords = to_string(stRecords.size());

		string subTitle = clsUtil::ColorText("\t    [", clsUtil::enColor::RED) + clsUtil::ColorText(NumberOfRecords, clsUtil::enColor::YELLOW) + clsUtil::ColorText("]", clsUtil::enColor::RED) + " Record(s).";

		_DrawScreenHeader("    Login Register List Screen", subTitle);

		cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(35) << "Date/Time";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(20) << "Record Name";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(20) << "Password";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(10) << "Permissions";
		cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

		if (stRecords.size() == 0)
			clsUtil::PrintColoredTextLine("\t\t\t\tNo Records Available In System!", clsUtil::enColor::RED);
		else

			for (const clsUser::stLoginRegisterRecord& Record : stRecords)
			{
				_PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}

		cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

	}


};

