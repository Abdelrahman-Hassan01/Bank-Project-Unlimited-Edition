#pragma once
#include "../../Core/clsScreen.h"
#include "../../Models/clsCurrency.h"
class clsFindCurrencyScreen : private clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card\n";
        cout << "---------------------------------------------\n";
        cout << "|" << left << setw(22) << "Country" << " : " << Currency.Country() << '\n';
        cout << "|" << left << setw(22) << "Code" << " : " << Currency.CurrencyCode() << '\n';
        cout << "|" << left << setw(22) << "Name" << " : " << Currency.CurrencyName() << '\n';
        cout << "|" << left << setw(22) << "Rate (per USD)" << " : " << Currency.Rate << '\n';
        cout << "---------------------------------------------\n";
    }


public:
    static void ShowFindCurrencyScreen() {
        _DrawScreenHeader("\tFind Currency Screen");

        cout << "Find By:    [1] Country   [2] Code\nChoice: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2);
        if (Choice == 1) {
            cout << "\nPlease Enter Country Name: ";
            string CountryName = clsInputValidate::ReadString();

            while (!clsCurrency::IsCurrencyNameExist(CountryName)) {
                cout << "\nCurrency Not Found Choose Another One: ";
                CountryName = clsInputValidate::ReadString();
            }
            cout << "\nCountry Found :-)\n";
            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
            _PrintCurrency(Currency);
        }
        if (Choice == 2) {
            cout << "\nPlease Enter Country Code: ";
            string CountryCode = clsInputValidate::ReadString();

            while (!clsCurrency::IsCurrencyCodeExist(CountryCode)) {
                cout << "\nCurrency Not Found Choose Another One: ";
                CountryCode = clsInputValidate::ReadString();
            }
            cout << "\nCountry Found :-)\n";
            clsCurrency Currency = clsCurrency::FindByCode(CountryCode);
            _PrintCurrency(Currency);
        }
    }
};

