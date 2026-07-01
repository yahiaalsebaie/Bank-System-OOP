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


void PrintClientRecordLine(const clsBankClient& Client)
{
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(15) << Client.AccountNumber();
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(20) << Client.FullName();
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(15) << Client.Phone;
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(25) << Client.Email;
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(10) << Client.PinCode;
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(12) << Client.AccountBalance;
}
void ShowClientsList()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
string SeparatorLine = "\n_________________________________________________________________________________________________________\n";
string ClientsNumber = to_string(vClients.size());
cout << "\n\t\t\t\t\tClient List " << clsUtil::ColorText("[", clsUtil::enColor::RED) << clsUtil::ColorText(ClientsNumber, clsUtil::enColor::YELLOW) << clsUtil::ColorText("]", clsUtil::enColor::RED) << " Client(s).";
cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(15) << "Account Number";
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(20) << "Client Name";
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(15) << "Phone";
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(25) << "Email";
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(10) << "Pin Code";
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(12) << "Balance";
    cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

    if (vClients.size() == 0)
        clsUtil::PrintColoredTextLine("\t\t\t\tNo Clients Data Available In System!", clsUtil::enColor::RED);
    else

        for (const clsBankClient& Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

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