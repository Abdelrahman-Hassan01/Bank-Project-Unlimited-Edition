#pragma once
#include "../../Core/clsScreen.h"
#include "../../Models/clsCurrency.h"
#include "clsFindCurrencyScreen.h"
class clsUpdateCurrencyRate : private clsScreen
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
    static void ShowUpdateRateScreen() {
        cout << "\nPlease Enter Country Code: ";
        string CountryCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyCodeExist(CountryCode)) {
            cout << "\nCurrency Not Found Choose Another One: ";
            CountryCode = clsInputValidate::ReadString();
        }
        cout << "\nCountry Found :-)\n";
        clsCurrency Currency = clsCurrency::FindByCode(CountryCode);
        _PrintCurrency(Currency);

        cout << "Are You Sure You Want To Update The Rate Of This Currency Y/N ? ";
        char Answer;
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            cout << "\nUpdate Currency Rate:\n_______________________\n";
            cout << "\nEnter New Rate: ";
            double NewRate = clsInputValidate::ReadDblNumber();

            Currency.Rate = NewRate;
        }
        else
            cout << "Update Currency Canclled";
    }
};

