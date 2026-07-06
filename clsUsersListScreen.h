#pragma once
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class clsUsersListScreen : protected clsScreen
{
private:

	static void PrintUserRecordLine(const clsUser& User)
	{
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << User.UserName();
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(25) << User.FullName();
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << User.Phone;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(25) << User.Email;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(10) << User.Password;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(12) << User.Permissions;
	}


public:

	static void ShowUsersList()
	{
		const vector<clsUser>& vUsers = clsUser::GetUsersList();

		//Head
		string separatorLine = "\n____________________________________________________________________________________________________________________\n";
		string NumberOfUsers = to_string(vUsers.size());
		string Title = "\t\tUser List ";
		string SubTitle = clsUtil::ColorText("\t       [", clsUtil::enColor::RED) + clsUtil::ColorText(NumberOfUsers, clsUtil::enColor::YELLOW) + clsUtil::ColorText("]", clsUtil::enColor::RED) + " User(s).";

		_DrawScreenHeader(Title, SubTitle);


		//Body
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << "User Name";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(25) << "Full Name";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << "Phone";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(25) << "Email";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(10) << "Password";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(12) << "Permissions";
		cout << clsUtil::ColorText(separatorLine, clsUtil::enColor::YELLOW);

		if (vUsers.empty())
			clsUtil::PrintColoredTextLine("\t\t\t\tNo Users Data Available In System!", clsUtil::enColor::RED);
		else
		{
			for (const clsUser& User : vUsers)
			{
				PrintUserRecordLine(User);
				cout << endl;
			}
		}
		//Footer
		cout << clsUtil::ColorText(separatorLine, clsUtil::enColor::YELLOW);

	}

};

