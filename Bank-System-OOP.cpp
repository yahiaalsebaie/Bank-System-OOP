#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <cstdlib>
#include "clsPerson.h"
#include "clsUtil.h"
#include <iomanip>

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
    cout << clsUtil::RedText("\n____________________\n");
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
        cout << clsUtil::RedText("\nError account was not saved because it's Empty");
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
        cout << clsUtil::RedText("\nAccount Number Is Already Used, Choose another one: ");
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
    cout << clsUtil::RedText("\nAre you sure you want to Delete this Client ? [Y/N] >> ");
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y')
    {
        if (Client1.Delete())
        {
            cout << clsUtil::GreenText("\nClient Deleted Successfully.\n");
            Client1.Print();
        }

        else  cout << clsUtil::RedText("\nError: Client Not Deleted.\n");
    }

}


void PrintClientRecordLine(const clsBankClient& Client)
{
    cout << clsUtil::RedText("| ") << left << setw(15) << Client.AccountNumber();
    cout << clsUtil::RedText("| ") << left << setw(20) << Client.FullName();
    cout << clsUtil::RedText("| ") << left << setw(15) << Client.Phone;
    cout << clsUtil::RedText("| ") << left << setw(25) << Client.Email;
    cout << clsUtil::RedText("| ") << left << setw(10) << Client.PinCode;
    cout << clsUtil::RedText("| ") << left << setw(12) << Client.AccountBalance;
}
void ShowClientsList()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
string SeparatorLine ="\n_________________________________________________________________________________________________________\n";

    cout << "\n\t\t\t\t\tClient List " << clsUtil::RedText("[") << vClients.size() << clsUtil::RedText("]") << " Client(s).";
    cout << SeparatorLine;

    cout << clsUtil::RedText("| ") << left << setw(15) << "Account Number";
    cout << clsUtil::RedText("| ") << left << setw(20) << "Client Name";
    cout << clsUtil::RedText("| ") << left << setw(15) << "Phone";
    cout << clsUtil::RedText("| ") << left << setw(25) << "Email";
    cout << clsUtil::RedText("| ") << left << setw(10) << "Pin Code";
    cout << clsUtil::RedText("| ") << left << setw(12) << "Balance";
    cout << SeparatorLine;

    if (vClients.size() == 0)
        clsUtil::PrintColoredTextLine("\t\t\t\tNo Clients Data Available In System!", clsUtil::RED);
        //cout << clsUtil::RedText("\t\t\t\tNo Clients Data Available In System!");
    else

        for (const clsBankClient& Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << SeparatorLine;

}


int main()

{
    //UpdateClient();
    //AddNewClient();
    //DeleteClient();
    ShowClientsList();

    system("pause>0");
    return 0;
}