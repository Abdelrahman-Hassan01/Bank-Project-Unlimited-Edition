#pragma once
#include "../../Core/clsScreen.h"
#include "../../Models/clsCurrency.h"
class clsCurrenciesList : private clsScreen
{
    static void _PrintCurrencyListRow(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(27) << left << Currency.Country();
        cout << "| " << setw(25) << left << Currency.CurrencyCode();
        cout << "| " << setw(12) << left << Currency.CurrencyName();
        cout << "| " << setw(20) << left << Currency.Rate;
       
    }

public:
    static void ShowCurrenciesList()
    {
        vector<clsCurrency> vCurrencies = clsCurrency::GetCurrencyList();

        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);
        cout << "\n        _______________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(12) << "Country";
        cout << "| " << left << setw(25) << "Code";
        
        cout << "| " << left << setw(20) << "Name";
        cout << "| " << left << setw(10) << "Rate";
       
        cout << "\n        _______________________________________________________________________________________________________\n\n";

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsCurrency Currency : vCurrencies)
            {

                _PrintCurrencyListRow(Currency);
                cout << endl;
            }
        cout << "\n        _______________________________________________________________________________________________________\n\n";
    }
};

