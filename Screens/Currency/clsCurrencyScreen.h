#pragma once
#include <iostream>
#include <clsDate.h>
#include <clsInputValidate.h>
#include <clsPeriod.h>
#include <clsUtil.h>
#include "../../Core/clsScreen.h"
#include "clsCurrenciesList.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyScreen : private clsScreen
{
private:
	enum class CurrencyMenuOption
	{
		ListCurrencies = 1,
		FindCurrency,
		UpdateCurrencyRate,
		CurrencyCalculator,
		MainMenu
	};

	static short _ReadCurrencyMenuOption()
	{
		cout << setw(37) << left << "" << "Choose an option (1-5): ";

		short MenuOptionNumber = clsInputValidate::ReadShortNumberBetween(1, 5);
		return MenuOptionNumber;
	}

	static void _ReturnToCurrencyMenu()
	{
		cout << setw(37) << left << " " << "\nPress any key to go back to the currency menu...\n";
		system("pause>0");
		ShowCurrencyMenu();
	}

	static void _ShowCurrencyListScreen() {
		clsCurrenciesList::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen() {
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen() {
		clsUpdateCurrencyRate::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen() {
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _HandleCurrencyMenuOption(CurrencyMenuOption MenuOption) {
		switch (MenuOption) {
		case CurrencyMenuOption::ListCurrencies:
			system("cls");
			_ShowCurrencyListScreen();
			_ReturnToCurrencyMenu();
			break;
		case CurrencyMenuOption::FindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_ReturnToCurrencyMenu();
			break;
		case CurrencyMenuOption::UpdateCurrencyRate:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_ReturnToCurrencyMenu();
			break;
		case CurrencyMenuOption::CurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_ReturnToCurrencyMenu();
			break;
		case CurrencyMenuOption::MainMenu:
			system("cls");
			break;
		}
	}
public:
	static void ShowCurrencyMenu()
	{
        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_HandleCurrencyMenuOption(CurrencyMenuOption(_ReadCurrencyMenuOption()));
	}
};

