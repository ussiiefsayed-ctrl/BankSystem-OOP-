#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = clsInputValidate::ReadStirng();

	cout << "\nEnter LastName: ";
	Client.LastName = clsInputValidate::ReadStirng();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadStirng();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadStirng();

	cout << "\nEnter PinCode: ";
	Client.PinCode = clsInputValidate::ReadStirng();

	cout << "\nEnter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();

}

void DeleteClient()
{
	string AccountNumber = "";
	
	cout << "\nPlease Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadStirng();
	if (!(clsBankClient::IsClientExist(AccountNumber)))
	{
		cout << "\nAccount Number Is Not Found, choose another one: ";
		AccountNumber = clsInputValidate::ReadStirng();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();
	
	char Answer;
	cout << "Are you sure you want delete this file y/n?";
	cin >> Answer;

	if (tolower(Answer) == 'y')
	{

		if (Client1.Delete())
		{
			cout << "\nAccount Deleted Successfully";
			Client1.Print();
		}
		else
		{
			cout << "\nError Client Was not Deleted\n";
		}
	}

}


int main()
{	
	DeleteClient();

	system("pause > 0");
	return 0;
}