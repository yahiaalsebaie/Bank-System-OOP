#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <cstdlib>
#include "clsPerson.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName: "; 
    clsPerson::PerformFirstName(Client); //Upcasting -> Zero Performance Overhead // PerformFirstName() here without any numbers or spatial characters.

    Client.LastName = clsInputValidate::ReadString("\nEnter LastName: "); // Normal input.

    cout << "\nEnter Email: ";
    clsPerson::PerformEmail(Client);

    cout << "\nEnter Phone: ";
    Client.PerformPhone(Client);

    cout << "Enter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();

    //cout << "Enter Gender [M/F]: "; //I didn't implement it and MartialStatus in output to keep it as simple as can.
    //Client.PerformGenderInfo(Client);
}



void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    clsBankClient::PerformAccountNumber(AccountNumber);

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    
    
    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";
    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }

    }
}

int main()

{
    UpdateClient();

    system("pause>0");
    return 0;
}