#pragma once
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
#include <clsDate.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	short _Permissions;

	bool _MarkForDelete = false;

	//const string _UsersFileName = "Users.txt";

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertUserObjectToLine(const clsUser& User, string Separator = "#//#")
	{
		string UserObj = "";
		UserObj += User.FirstName + Separator;
		UserObj += User.LastName + Separator;
		UserObj += User.Email + Separator;
		UserObj += User.Phone + Separator;
		UserObj += User.UserName() + Separator;
		UserObj += User.Password + Separator;
		UserObj += to_string(User.Permissions);

		return UserObj;
	}


	static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
	{
		vector<string> vUserData = clsString::Split(Line, Separator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
	}
	
public:
	struct stLoginRegisterRecord
	{
		string DateTime;
		string	 UserName;
		string	 Password;
		short Permissions;
	};
private:

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Separator = "#//#")
	{
		vector<string> DataLine = clsString::Split(Line, Separator);

		stLoginRegisterRecord Record;

		Record.DateTime = DataLine[0];
		Record.UserName = DataLine[1];
		Record.Password = DataLine[2];
		Record.Permissions = stoi(DataLine[3]);

		return Record;

	}


	string _PrepareLoginRecord(/*const clsUser& User,*/ string Separator = "#//#")
	{
		bool includeDayName = false;
		string DateTime = clsDate::GetSystemDateTimeString(includeDayName);
		string Record = "";

		Record += DateTime + Separator;
		Record += _UserName + Separator;
		Record += _Password + Separator; //Just for learning purposes
		Record += to_string(_Permissions);

		return Record;
	}

	
	  static vector<clsUser> _LoadUsersDataFromFile(string FileName = "Users.txt")
	  {
		  vector<clsUser> vUsers;
		  fstream myFile;
		  myFile.open(FileName, ios::in);//Read (input) mode.

		  if (myFile.is_open())
		  {
			  string line;
			  while (getline(myFile, line))
			  {
				  if (line == "")
					  continue;
				  clsUser User = _ConvertLineToUserObject(line);
				  vUsers.push_back(User);
			  }
			  myFile.close();
		  }
		  return vUsers;
	  }


	
	
	static void _SaveUsersDataToFile(const vector<clsUser>& vUsers)
	{
		string FileName = "Users.txt";
		fstream myFile;
		myFile.open(FileName, ios::out);

		if (myFile.is_open())
		{
			string line;
			for (const clsUser& c : vUsers)
			{
				if (c._MarkForDelete == false)
				{
					line = _ConvertUserObjectToLine(c);
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
		vector <clsUser> _vUsers = _LoadUsersDataFromFile("Users.txt");

		for (clsUser& c : _vUsers)
		{
			if (c.UserName() == UserName())
			{
				c = *this; // *this == updated information
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile("Users.txt", _ConvertUserObjectToLine(*this));
	}

public:

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, short Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;

		_Permissions = Permissions;
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailedUserNameExists = 2 };

	enum enPermissions : short {
		epShowClientsList = 1, epAddNewClient = 2, epDeleteClient = 4, epUpdateClient = 8, epFindClient = 16, epTransactions = 32, epMangeUsers = 64, epAll = -1
	};

	bool MarkForDelete() { return _MarkForDelete; }

	bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

	string UserName() const { return _UserName; } // Get only

	void SetPassword(string Password) { _Password = Password; }
	string GetPassword() const { return _Password; }
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(float Permissions) { _Permissions = Permissions; };
	short GetPermissions() const { return _Permissions; }
	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	static clsUser Find(const string& UserName)
	{
		vector<clsUser> vUsers;

		fstream myFile;
		myFile.open("Users.txt", ios::in); //Read mode

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsUser User = _ConvertLineToUserObject(line);
				if (User.UserName() == UserName)
				{
					myFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(const string& UserName, const string& Password)
	{
		vector<clsUser> vUsers;

		fstream myFile;
		myFile.open("Users.txt", ios::in); //Read mode

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsUser User = _ConvertLineToUserObject(line);
				if (User.UserName() == UserName && User.Password == Password)
				{
					myFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(const string& UserName)
	{
		clsUser u = clsUser::Find(UserName);
		return (!u.IsEmpty());
	}

	static void PerformIsUserNameExist(string& UserName, string ErrorMessage = "\nUser Name is not found, choose another one: ")
	{
		while (!clsUser::IsUserExist(UserName))
		{
			if (ErrorMessage != "") cout << clsUtil::ColorText(ErrorMessage, clsUtil::enColor::BEIGE);
			UserName = clsInputValidate::ReadString();
		}
	}

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsUser::EmptyMode:
			if (IsEmpty())
				return enSaveResults::svFaildEmptyObject;

		case clsUser::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
		case clsUser::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
				return enSaveResults::svFailedUserNameExists;
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

		}

		}
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	//--Delete--//
	bool Delete()
	{
		vector <clsUser> _vUsers = _LoadUsersDataFromFile();

		for (clsUser& u : _vUsers)
		{
			if (_UserName == u._UserName)
			{
				u._MarkForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::epAll) return true;
		if ((this->Permissions & Permission) == Permission) return true;
		else return false;
	}

	void RegisterLogIn()
	{
		string RecordLine = _PrepareLoginRecord();

		fstream myFile;
		myFile.open("LoginRegister.txt", ios::out | ios::app);

		if (myFile.is_open())
		{
			myFile << RecordLine << endl;
			myFile.close();
		}
	}

	
	 static vector<stLoginRegisterRecord> GetLoginRegisterList(string FileName = "LoginRegister.txt")
	 {
		 vector<stLoginRegisterRecord> vLogins;
		 fstream myFile;
		 myFile.open(FileName, ios::in);//Read (input) mode.

		 if (myFile.is_open())
		 {
			 string line;
			 stLoginRegisterRecord loginRecord;
			 while (getline(myFile, line))
			 {
				 if (line == "")
					 continue;
				loginRecord = _ConvertLoginRegisterLineToRecord(line);
				 vLogins.push_back(loginRecord);
			 }
			 myFile.close();
		 }
		 return vLogins;
	 }
};
