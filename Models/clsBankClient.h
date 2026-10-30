#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <clsString.h>
#include "clsPerson.h"
#include "../Core/Global.h"
#include <clsUtil.h>

using namespace std;

class clsBankClient : public clsPerson
{
public:
	struct stTransferLog
	{
		string TransferDateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		double TransferAmount;
		double SourceBalanceAfterTransfer;
		double DestinationBalanceAfterTransfer;
		string UserName;
	};

private:
	enum class enMode
	{
		EmptyMode,
		UpdateMode,
		AddNewMode
	};

	enMode _Mode;

	string _AccountNumber;

	string _PinCode;

	double _AccountBalance;

	bool _IsMarkedForDeletion = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{

		vector<string> vClientData = clsString::Split(Line, Separator);
		if (vClientData.size() == 7)
		{
			return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
				vClientData[4], clsUtil::DecryptText(vClientData[5], 4), stod(vClientData[6]));
		}
		else
			return _GetEmptyClient();
	}

	static string _ConvertClientToLine(clsBankClient Client, string Separator = "#//#")
	{
		string ClientRecord = "";
		ClientRecord += Client.FirstName + Separator;
		ClientRecord += Client.LastName + Separator;
		ClientRecord += Client.Email + Separator;
		ClientRecord += Client.Phone + Separator;
		ClientRecord += Client._AccountNumber + Separator;
		ClientRecord += clsUtil::EncryptText(Client.PinCode, 4) + Separator;
		ClientRecord += to_string(Client.AccountBalance);

		return ClientRecord;
	}

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientsFromFile()
	{
		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Clients.txt", ios::in);
		vector<clsBankClient> vClient;
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsBankClient Client = _ConvertLineToClientObject(line);
				vClient.push_back(Client);
			}
			MyFile.close();
		}
		return vClient;
	}

	static bool _SaveClientsToFile(vector<clsBankClient> vClient)
	{
		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Clients.txt", ios::out);
		string DataLine;
		if (MyFile.is_open())
		{
			for (const clsBankClient& C : vClient)
			{
				if (C._IsMarkedForDeletion == false)
				{
					DataLine = _ConvertClientToLine(C);
					MyFile << DataLine << endl;
				}
			}
			return true;
		}
		return false;
	}

	bool _UpdateClient()
	{
		vector<clsBankClient> vClient = _LoadClientsFromFile();
		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		if (_SaveClientsToFile(vClient))
			return true;
		return false;
	}

	bool _AppendClientRecord(string DataLine)
	{
		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Clients.txt",
			ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
			return true;
		}
		return false;
	}

	bool _AddClient()
	{
		return _AppendClientRecord(_ConvertClientToLine(*this));
	}

	static vector<string> _ConvertLineToTransferLogRecord(string Line, string Separator = "#//#")
	{
		vector<string> TransferLogFields;
		TransferLogFields = clsString::Split(Line, Separator);

		return TransferLogFields;
	}

	static vector<stTransferLog> _LoadTransferLogsFromFile()
	{
		vector<stTransferLog> vLogs;
		ifstream MyFile("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\TransferLog.txt");
		string Line;

		while (getline(MyFile, Line))
		{
			vector<string> Fields = _ConvertLineToTransferLogRecord(Line);
			if (Fields.size() < 7)
				continue;

			stTransferLog Record;
			Record.TransferDateTime = Fields[0];
			Record.SourceAccountNumber = Fields[1];
			Record.DestinationAccountNumber = Fields[2];
			Record.TransferAmount = stod(Fields[3]);
			Record.SourceBalanceAfterTransfer = stod(Fields[4]);
			Record.DestinationBalanceAfterTransfer = stod(Fields[5]);
			Record.UserName = Fields[6];
			vLogs.push_back(Record);
		}

		return vLogs;
	}

	string _PrepareTransferLog(clsBankClient To, double Amount, string Separator = "#//#")
	{
		string TransferLogLine;
		TransferLogLine += clsDate::GetSystemDateTimeString() + Separator;
		TransferLogLine += AccountNumber() + Separator;
		TransferLogLine += To.AccountNumber() + Separator;
		TransferLogLine += to_string(Amount) + Separator;
		TransferLogLine += to_string(AccountBalance) + Separator;
		TransferLogLine += to_string(To.AccountBalance) + Separator;
		TransferLogLine += CurrentUser.UserName;
		return TransferLogLine;
	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber,
		string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Phone, Email)
	{
		_Mode = Mode;

		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	enum class enSaveResults
	{
		svSucceeded,
		svFailedEmptyObject,
		svFailedAccountNumberExists
	};

	string AccountNumber()
	{
		return _AccountNumber;
	}

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (IsEmpty())
				return enSaveResults::svFailedEmptyObject;
		case enMode::UpdateMode:
			if (_UpdateClient())
				return enSaveResults::svSucceeded;
			return enSaveResults::svFailedEmptyObject;
		case enMode::AddNewMode:
			if (clsBankClient::ClientExists(_AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
			}
			_AddClient();
			_Mode = enMode::UpdateMode;
			return enSaveResults::svSucceeded;
		}
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		if (AccountBalance > 0)
			_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line, "#//#");

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClient();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line, "#//#");

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClient();
	}

	bool Delete()
	{
		vector<clsBankClient> vClient = _LoadClientsFromFile();
		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._IsMarkedForDeletion = true;
				break;
			}
		}
		_SaveClientsToFile(vClient);
		*this = _GetEmptyClient();
		return true;
	}

	static bool ClientExists(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(clsBankClient::enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsFromFile();
	}

	static float GetTotalClientBalances()
	{
		vector<clsBankClient> vClient = clsBankClient::GetClientsList();
		float TotalBalances = 0;
		for (clsBankClient& C : vClient)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}

	bool Deposit(double& Amount)
	{
		if (Amount < 0)
			return false;

		double OldBalance = AccountBalance;

		AccountBalance += Amount;

		switch (Save())
		{
		case enSaveResults::svFailedEmptyObject:
			AccountBalance -= Amount;
			return false;
		case enSaveResults::svSucceeded:
			return true;
		}

		OldBalance = AccountBalance;
		return false;
	}

	bool Withdraw(double& Amount)
	{
		if (Amount > AccountBalance || Amount <= 0)
			return false;

		double OldBalance = AccountBalance;

		AccountBalance -= Amount;

		switch (Save())
		{
		case enSaveResults::svFailedEmptyObject:
			AccountBalance = OldBalance;
			return false;

		case enSaveResults::svSucceeded:
			return true;
		}

		AccountBalance = OldBalance;
		return false;

	}

	void RegisterTransferLog(clsBankClient To, double Amount)
	{
		string TransferLogLine = _PrepareTransferLog(To, Amount);
		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\TransferLog.txt",
			ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << TransferLogLine << endl;
			MyFile.close();
		}
	}

	bool Transfer(clsBankClient& To, double Amount)
	{

		if (Amount <= 0 || Amount > AccountBalance || AccountNumber() == To.AccountNumber())
		{
			return false;
		}

		if (To.Deposit(Amount) && Withdraw(Amount))
			return true;
		return false;
	}

	static vector<stTransferLog> GetTransferLogs()
	{
		return _LoadTransferLogsFromFile();
	}
};
