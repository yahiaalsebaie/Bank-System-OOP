#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <cstdlib>
#include "clsPerson.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsMainScreen.h"

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
    cout << clsUtil::ColorText("\n____________________\n",clsUtil::enColor::GREEN);
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
        cout << clsUtil::ColorText("\nError account was not saved because it's Empty", clsUtil::enColor::RED);
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
        cout << clsUtil::ColorText("\nAccount Number Is Already Used, Choose another one: ", clsUtil::enColor::ORANGE);
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
    cout << clsUtil::ColorText("\nAre you sure you want to Delete this Client ? [Y/N] >> ", clsUtil::enColor::RED);
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y')
    {
        if (Client1.Delete())
        {
            cout << clsUtil::ColorText("\nClient Deleted Successfully.\n", clsUtil::enColor::BRIGHT_GREEN);
            Client1.Print();
        }

        else  cout << clsUtil::ColorText("\nError: Client Not Deleted.\n", clsUtil::enColor::RED);
    }

}

//--TotalBalances--
void PrintClientRecordBalanceLine(const clsBankClient& Client)
{
    cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << Client.AccountNumber();
    cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(30) << Client.FullName();
    cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << Client.AccountBalance;
}
void ShowTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
string SeparatorLine = "\n_________________________________________________________________________________________________________\n";
string NumberOfClients = to_string(vClients.size());
cout << "\n\t\t\t\t\tClient List " << clsUtil::ColorText("[", clsUtil::enColor::RED) << clsUtil::ColorText(NumberOfClients, clsUtil::enColor::YELLOW) << clsUtil::ColorText("]", clsUtil::enColor::RED) << " Client(s).";
cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(15) << "Account Number";
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(30) << "Client Name";
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(15) << "Balance";
    cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

    if (vClients.size() == 0)
        clsUtil::PrintColoredTextLine("\t\t\t\tNo Clients Available In System!", clsUtil::enColor::RED);
    else

        for (const clsBankClient& Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

    //Total Balances
    double TotalBalances = clsBankClient::GetTotalBalances(vClients);

    cout << clsUtil::ColorText(("\t\t\t\tTotal Balances = " + to_string(TotalBalances)), clsUtil::enColor::GREEN);

    string txt = clsUtil::ConvertNumberToText<unsigned long>(TotalBalances);

    if (TotalBalances == 0)
        cout << "\n\t\t\t\t\t\t" << "Zero" << endl;
    else 
        cout << "\n\t\t\t" << txt << endl;

}


int main()

{
    //UpdateClient();
    //AddNewClient();
    //DeleteClient();
    //ShowClientsList();
    //ShowTotalBalances();

    clsMainScreen::ShowMainMenu();
     system("pause>0");
    return 0;
}