#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen :protected clsScreen
{
private:
	
	static clsCurrency _ReadCurrencyByCode()
	{
		cout << "\n\nPlease Enter CurrnecyCode: ";	
		string CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static clsCurrency _ReadCurrencyByCountry()
	{
		cout << "\n\nPlease Enter Country Name: ";
		string CountryName = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
		return Currency;
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card:";
		cout << "\n_____________________________";
		cout << "\n\nCountry  : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________";
	}

	static void _ShowResult(clsCurrency Currency)
	{

		if (!(Currency.IsEmpty()))
		{
			cout << "\nCurrency Found:-)";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Is Not Found:-(";
		}

	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFindCurrencyScreen");
		
		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Please Enter Number From 1 To 2 : ");

		if (Choice == 1)
		{
			cout << "\nPlease Enter CurrencyCode: ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}
		else
		{
			cout << "\nPlease Enter Country: ";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResult(Currency);
		}
	}

};

