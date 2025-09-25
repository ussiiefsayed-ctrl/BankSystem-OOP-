#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;

class clsBankClient :public clsPerson
{
private:
	enum enMode {EmptyMode = 0,UpdatedMode = 1};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line,string Delim = "#//#")
	{
		vector <string> vClientData = clsString::Split(Line, Delim);

		return clsBankClient(enMode::UpdatedMode, vClientData[0], vClientData[1],vClientData[2]
			, vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadDataFromFileToObject()
	{
		fstream MyFile;
		vector <clsBankClient> vClient;

		MyFile.open("Clients.txt", ios::in);
		string Line;

		if (MyFile.is_open())
		{

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClient.push_back(Client);
			}
			MyFile.close();

		}
		return vClient;
	}
	
	static string ConvertClientObjectToLine(clsBankClient Client,string Delim = "#//#")
	{
		string stClientLine = "";

		stClientLine += Client.FirstName + Delim;
		stClientLine += Client.LastName + Delim;
		stClientLine += Client.Email + Delim;
		stClientLine += Client.Phone + Delim;
		stClientLine += Client.AccountNumber() + Delim;
		stClientLine += Client.PinCode + Delim;
		stClientLine += to_string(Client.AccountBalance);

		return stClientLine;
	}

	static void SaveClientDataToFile(vector <clsBankClient> vClient)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		string Client;

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClient)
			{
				Client = ConvertClientObjectToLine(C);
				MyFile << Client << endl;
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients =_LoadDataFromFileToObject();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}
		SaveClientDataToFile(_vClients);
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
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

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFistName    : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFullName    : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in); //ReadOnly

		if (MyFile.is_open())
		{
			string Line;
			
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
					
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

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in); //ReadOnly

		if (MyFile.is_open())
		{
			string Line;


			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

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

	enum enSaveResult { svFaildEmptyObject = 0,svSucceeded = 1};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResult::svFaildEmptyObject;
		}

		case enMode::UpdatedMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
					
		}

	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}




};
 
