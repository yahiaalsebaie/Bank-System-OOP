#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class clsTransfersLogScreen :protected clsScreen
{
private:


	static void _PrintTransfersLogRecordLine(clsBankClient::stTransferLogRecord TransfersLogRecord)
	{
		cout << left << setw(5) << " ";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(25) << TransfersLogRecord.DateTime;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << TransfersLogRecord.SourceAccountNumber;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << TransfersLogRecord.DestinationBalanceAfter;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << TransfersLogRecord.TransferAmount;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << TransfersLogRecord.SourceBalanceAfter;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << TransfersLogRecord.DestinationBalanceAfter;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << TransfersLogRecord.UserName;

	}

	
public:

	static void ShowTransfersLogsScreen()
	{

		vector <clsBankClient::stTransferLogRecord> stRecords = clsBankClient::GetTransferRegisterList();
		string SeparatorLine = "\n_____________________________________________________________________________________________________________\n";
		string NumberOfRecords = to_string(stRecords.size());

		string subTitle = clsUtil::ColorText("\t    [", clsUtil::enColor::RED) + clsUtil::ColorText(NumberOfRecords, clsUtil::enColor::YELLOW) + clsUtil::ColorText("]", clsUtil::enColor::RED) + " Record(s).";

		_DrawScreenHeader("    Login Register List Screen", subTitle);

		cout << left << setw(5) << " ";
		cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

		cout << left << setw(5) << " ";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(25) << "Date/Time";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << "src.Acc";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << "des.Acc";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << "Amount";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << "src.Balance";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << "des.Balance";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(11) << "User";
		cout << left << setw(5) << " ";
		cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

		if (stRecords.size() == 0)
			clsUtil::PrintColoredTextLine("\t\t\t\tNo Records Available In System!", clsUtil::enColor::RED);
		else

			for (const clsBankClient::stTransferLogRecord& Record : stRecords)
			{
				_PrintTransfersLogRecordLine(Record);
				cout << endl;
			}
		cout << left << setw(5) << " ";
		cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

	}


};

