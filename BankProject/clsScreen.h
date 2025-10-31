#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
extern clsUser CurrentUser;

using namespace std;

class clsScreen
{
	
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\n\t\t\t\t\t______________________________________\n\n";
		
		clsDate Date = clsDate::GetSystemDate();

		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate:";
		Date.Print();
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{

		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t________________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin";
			cout << "\n\t\t\t\t\t________________________________________";
			return false;
		}
		else
		{
			return true;
		}

	}

};

