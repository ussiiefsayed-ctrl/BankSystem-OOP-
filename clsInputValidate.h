
//Ussief Dawood

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Number, short From, short To)
	{

		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{

		if(Number >= From && Number <= To)
			return true;
		else
		return false;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{

		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsDate1BeforeDate2(DateTo, DateFrom))
		{
			clsDate::SwapDates(DateFrom, DateTo);
		}

		if ((clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date,DateFrom))
			&&
			(clsDate::IsDate1BeforeDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date,DateTo))
			)
		{
			return true;
		}
		else
		{
			return true;
		}
	}

	static float ReadFloatNumber()
	{
		float Number;
		cin >> Number;

		return Number;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter Again")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number Is Not Within range, enter again:")
	{

		int Number=ReadIntNumber();

		while (!(IsNumberBetween(Number,From, To)))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string InvalidMessage = "Invalid Number, Enter Again")
	{
		double Number;
		if (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << InvalidMessage << endl;
		}
		return Number;

	}

	static double ReadDblNumberBetween(double From, double To, string InvalidMessage = "Number Is Not Within range, enter again:")
	{
		double Number = ReadDblNumber();
	
		while (!(IsNumberBetween(Number,From,To)))
		{
			cout << InvalidMessage << endl;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}	

	static string ReadStirng()
	{
		string Str;

		cin >> Str;
		return Str;
	}

};

