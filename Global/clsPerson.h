#pragma once
#include <iostream>
#include <string>
#include "clsInputValidate.h"

using namespace std;

class clsPerson
{

private:

    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;


protected:
    enum enGender { Male = 0, Female = 1 };
    enGender _Gender;
    enum enMartialStatus { Single = 0, Married = 1 };
    enMartialStatus _MartialStatus;

public:

    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {

        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    //Property Set
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string GetFirstName() const { return _FirstName; }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    //Property Set
    void SetLastName(string LastName) 
    {
        _LastName = LastName;
    }

    //Property Get
    string GetLastName() const
    {
        return _LastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    //Property Set
    void SetEmail(string Email)
    {
        _Email = Email;
    }

    //Property Get
    string GetEmail() const
    {
        return _Email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    //Property Set
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string GetPhone() const
    {
        return _Phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;

    string FullName() const
    {
        return _FirstName + " " + _LastName;
    }

    /*void Print() //make it in UI only
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }*/

    static void PerformFullNameInfo(clsPerson& Person, string ErrorMessage = "Invalid Name, Please Enter a Valid Name [without any spatial characters] : ")
    {
        string Name = clsInputValidate::ReadString(); // read full name with spaces
        while (!clsInputValidate::IsValidName(Name))
        {
            if (ErrorMessage != "") cout << ErrorMessage;
            Name = clsInputValidate::ReadString();
        }

        // Split into first and last name (first token -> FirstName, rest -> LastName)
        short pos = Name.find(' ');
        if (pos == string::npos)
        {
            Person.FirstName = Name;
            Person.LastName = "";
        }
        else
        {
            Person.FirstName = Name.substr(0, pos);
            // trim leading spaces of last name part
            short start = pos + 1;
            while (start < Name.size() && Name[start] == ' ') ++start;
            Person.LastName = (start < Name.size()) ? Name.substr(start) : "";
        }
    }

    static void PerformFirstName(clsPerson& Person, string ErrorMessage = "Invalid Name, Please Enter a Valid Name [without any spatial characters] : ")
    {
        string Name = clsInputValidate::ReadString();
        while (!clsInputValidate::IsValidName(Name))
        {
            if (ErrorMessage != "") cout << ErrorMessage;
            Name = clsInputValidate::ReadString();
        }
        Person.FirstName = Name;
    }

    static void PerformLastName(clsPerson& Person, string ErrorMessage = "Invalid Name, Please Enter a Valid Name [without any numbers or spatial characters] : ")
    {
        string Name = clsInputValidate::ReadString();
        while (!clsInputValidate::IsValidName(Name))
        {
            if (ErrorMessage != "") cout << ErrorMessage;
            Name = clsInputValidate::ReadString();
        }
        Person.LastName = Name;
    }
   
    static void PerformEmail(clsPerson& Person, string ErrorMessage = "Invalid Email, Please Enter a Valid Email : ")
    {
        do
        {
            Person.Email = clsInputValidate::ReadString();
            if (!clsInputValidate::IsValidEmail(Person.Email))
                if (ErrorMessage != "") cout << ErrorMessage;
            
        } while (!clsInputValidate::IsValidEmail(Person.Email));
    }
    static void PerformPhone(clsPerson& Person, string ErrorMessage = "Invalid Phone Number, Please Enter a Valid Phone Number : ")
    {
        do
        {
            Person.Phone = clsInputValidate::ReadString();
                if (!clsInputValidate::IsValidPhone(Person.Phone))
                    if (ErrorMessage != "") cout << ErrorMessage;
                

        } while (!clsInputValidate::IsValidPhone(Person.Phone));
    }
   
    static void PerformGenderInfo(clsPerson& Person, string ErrorMessage = "Invalid Gender, Please Enter [M Or F Only] : ")
    {
        char Gender;

        do
        {
            cin >> Gender;
            if (Gender == 'M' || Gender == 'm' || Gender == '0')
            {
                Person._Gender = Male;
                break;
            }
            else if (Gender == 'f' || Gender == 'F' || Gender == '1')
            {
                Person._Gender = Female;
                break;
            }
            else
            {
                if (ErrorMessage != "") cout << ErrorMessage;
            }
            cin.ignore(1000, '\n');
        } while (true);


    }
    static void PerformMartialState(clsPerson& Person, string ErrorMessage = "Invalid Marital Status, Please Enter [1 Or 0 Only] : ")
    {
        short IsMarried;
        do
        {
            cin >> IsMarried;
            if (IsMarried == 1)
            {
                Person._MartialStatus = Married;
                break;
            }
            else if (IsMarried == 0)
            {
                Person._MartialStatus = Single;
                break;
            }
            else
            {
                if (ErrorMessage != "") cout << ErrorMessage;
            }
            cin.ignore(1000, '\n');
        } while (true);


    }


};

