#pragma once
#include "../../../Core/clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsShowTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : private clsScreen
{
  private:
    enum class enTransactionMenuOption
    {
        Deposit = 1,
        Withdraw,
        TotalBalances,
        Transfer,
        TransferLog,
        MainMenu
    };

    static short _ReadTransactionMenuOption()
    {
        cout << setw(37) << left << "" << "Choose an option (1-6): ";

        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
        return Choice;
    }

    static void _ReturnToTransactionsMenu()
    {
        cout << setw(37) << left << " " << "\nPress any key to go back to transactions...\n";
        system("pause>0");
        ShowTransactionsMenu();
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsShowTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }
    static void _HandleTransactionMenuOption(enTransactionMenuOption MenuOption)
    {
        switch (MenuOption)
        {
        case enTransactionMenuOption::Deposit:
            system("cls");
            _ShowDepositScreen();
            _ReturnToTransactionsMenu();
            break;
        case enTransactionMenuOption::Withdraw:
            system("cls");
            _ShowWithdrawScreen();
            _ReturnToTransactionsMenu();
            break;
        case enTransactionMenuOption::TotalBalances:
            system("cls");
            _ShowTotalBalancesScreen();
            _ReturnToTransactionsMenu();
            break;
        case enTransactionMenuOption::Transfer:
            system("cls");
            _ShowTransferScreen();
            _ReturnToTransactionsMenu();
            break;
        case enTransactionMenuOption::TransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _ReturnToTransactionsMenu();
            break;
        case enTransactionMenuOption::MainMenu:
            system("cls");

            break;
        }
    }

  public:
    static void ShowTransactionsMenu()
    {
        system("cls");
        _DrawScreenHeader("\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _HandleTransactionMenuOption(enTransactionMenuOption(_ReadTransactionMenuOption()));
    }
};
