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

void UpdateClient()
{
	string AccountNumber = "";
	
	cout << "\nPlease Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadStirng();

	if (!(clsBankClient::IsClientExist(AccountNumber)))
	{
		cout << "\nAccount Number Is Not Found Please Enter Another One: ";
		AccountNumber = clsInputValidate::ReadStirng();
	}

	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();

	cout << "\n\nUpdate Client Info:";
	cout << "\n____________________\n";

	ReadClientInfo(Client);

	clsBankClient::enSaveResult Result;

	Result = Client.Save();

	switch (Result)
	{
	case clsBankClient::enSaveResult::svSucceeded:
	{
		cout << "\nAccount Updated Successfully :-)\n";
		Client.Print();
		break;
	}
	case clsBankClient::enSaveResult::svFaildEmptyObject:
	{
		cout << "\nError account was not saved because its Empty";
		break;
	}
	}



}


int main()
{	
	UpdateClient();

	system("pause > 0");
	return 0;
}
