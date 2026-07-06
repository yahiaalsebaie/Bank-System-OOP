#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

class clsAddNewUserScreen : protected clsScreen
{

private:

	static short _ReadPermissions()
	{
		short Permissions = 0;
		char choice = 'y';
		cout << "\nDo you want to give full access ? [Y/N] >> ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y') return Permissions = -1;

		cout << "\nDo you want to give access to :\n";

		cout << "\nShow Clients List ? [Y/N] >> ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')  Permissions += clsUser::enPermissions::epShowClientsList;

		cout << "\nAdd New Client ? [Y/N] >> ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')  Permissions += clsUser::enPermissions::epAddNewClient;

		cout << "\nDelete Client ? [Y/N] >> ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')  Permissions += clsUser::enPermissions::epDeleteClient;

		cout << "\nUpdate Client ? [Y/N] >> ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')  Permissions += clsUser::enPermissions::epUpdateClient;

		cout << "\nFind Client ? [Y/N] >> ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')  Permissions += clsUser::enPermissions::epFindClient;

		cout << "\nTransactions ? [Y/N] >> ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')  Permissions += clsUser::enPermissions::epTransactions;

		cout << "\nMange Users ? [Y/N] >> ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')  Permissions += clsUser::enPermissions::epMangeUsers;

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		//Different ways to get input.

		cout << "\nEnter FirstName: ";
		clsPerson::PerformFirstName(User); //Upcasting -> Zero Performance Overhead // PerformFirstName() here without any numbers or spatial characters.

		User.LastName = clsInputValidate::ReadString("\nEnter LastName: "); // Normal input.

		cout << "\nEnter Email: ";
		clsPerson::PerformEmail(User);

		cout << "\nEnter Phone: ";
		User.PerformPhone(User);

		cout << "Enter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissions();

		//cout << "Enter Gender [M/F]: "; //I didn't implement it and MartialStatus in output to keep it as simple as can.
		//User.PerformGenderInfo(User);
	}

	static void _PrintUser(const clsUser& User)
	{
		cout << clsUtil::ColorText("\n[User Card]", "#9b96bc");
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName();
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:
	static void ShowAddNewUserScreen()
	{
		string UserName = "";

		_DrawScreenHeader("\t Add New User Screen");

		cout << "\nPlease Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << clsUtil::ColorText("\nUser Name Is Already Used, Choose another one: ", clsUtil::enColor::ORANGE);
			UserName = clsInputValidate::ReadString();
		}

		clsUser newUser = clsUser::GetAddNewUserObject(UserName);
		
		_ReadUserInfo(newUser);

		clsUser::enSaveResults saveResult;

		saveResult = newUser.Save();

		switch (saveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
			cout << clsUtil::ColorText("\nAccount Added Successfully\n\n", clsUtil::enColor::GOLD);
			_PrintUser(newUser);
			break;
		case clsUser::enSaveResults::svFaildEmptyObject:
			cout << clsUtil::ColorText("\nError: account was Not saved!\n\n", clsUtil::enColor::RED);
			break;

		}

	}

};
