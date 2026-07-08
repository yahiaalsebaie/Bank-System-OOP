#pragma once
#include "clsDate.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <Global.h>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

class clsScreen
{
private:
	static void _ShowUserNameAndDate()
	{
		if (CurrentUser.UserName() != "")
		{
			//std::cout << "\n\t\t\t\t Welcome [" << clsUtil::ColorText(CurrentUser.UserName(), clsUtil::enColor::BRIGHT_GREEN) << "]";
			std::cout << endl << setw(40) << left << "" << "Welcome [" << clsUtil::ColorText(CurrentUser.UserName(), clsUtil::enColor::BRIGHT_GREEN) << "]";
			std::cout << "\t\t[" << clsUtil::ColorText(clsDate::GetSystemDateToString(), clsUtil::enColor::BRIGHT_GREEN) << "]\n";
		}
		else
			std::cout << "\n\t\t\t\t\t\t\t\t[" << clsUtil::ColorText(clsDate::GetSystemDateToString(), clsUtil::enColor::BRIGHT_GREEN) << "]\n";


	}
protected:

	static void _DrawScreenHeader(std::string Title, std::string SubTitle = "")
	{

		_ShowUserNameAndDate();
		std::string SeparationLine = "\n\t\t\t\t\t______________________________________\n\n";

		std::cout << SeparationLine;
		std::cout << "\t\t\t\t\t  " << Title;
		if (SubTitle != "")
			std::cout << "\n\t\t\t\t\t  " << SubTitle;
		std::cout << SeparationLine;

	}

	static bool CheckAccessRights(clsUser::enPermissions permission)
	{
		std::string SeparationLine = "\t\t\t\t\t**************************************\n";

		if (!(CurrentUser.CheckAccessPermission(permission)))
		{
			std::cout << SeparationLine << clsUtil::ColorText("\t\t\t\t\t Access Denied! Contact Your Admin...", clsUtil::enColor::DARK_ORANGE);
			std::cout << endl << SeparationLine;
			return false;
		}
		else return true;
	}

};