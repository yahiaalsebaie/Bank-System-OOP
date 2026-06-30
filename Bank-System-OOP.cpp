#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <cstdlib>
#include "clsPerson.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
    //Diffrent ways to get input.

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

    clsBankClient::PerformIsClientAccountNumberExist(AccountNumber);

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

void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already Used, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient newClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(newClient);

    clsBankClient::enSaveResults saveResult;

    saveResult = newClient.Save();


}

void DeleteClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    
    clsBankClient::PerformIsClientAccountNumberExist(AccountNumber);

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    char Answer = 'n';
    cout << "\nAre you sure you want to Delete this Client ? [Y/N] >> ";
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y')
    {
        if (Client1.Delete())
        {
            cout << "\nClient Deleted Successfully.\n";
            Client1.Print();
        }

    else cout << "\nError: Client Not Deleted.\n";
    }

}
     


int main()

{
    //UpdateClient();
    //AddNewClient();
    DeleteClient();

    system("pause>0");
    return 0;
}