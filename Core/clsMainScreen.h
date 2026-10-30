#pragma once
#include "../Models/clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "../Screens/Client Actions/Client/clsClientListScreen.h"
#include "../Screens/Client Actions/Client/clsAddNewClientScreen.h"
#include "../Screens/Client Actions/Client/clsDeleteClientScreen.h"
#include "../Screens/Client Actions/Client/clsUpdateClientScreen.h"
#include "../Screens/Client Actions/Client/clsFindClientScreen.h"
#include "../Screens/Client Actions/Transactions/clsTransactionsScreen.h"
#include "../Screens/Users/Manage Users/clsManageUsersScreen.h"
#include "Global.h"
#include "../Models/clsUser.h"
#include "../Screens/Users/clsLoginRegisterScreen.h"
#include "../Screens/Currency/clsCurrencyScreen.h"
class clsMainScreen : private clsScreen
{
  private:
    static short _ReadMainMenuOption(short MaxOption)
    {
        cout << setw(37) << left << "" << "Choose an option (1-" << MaxOption << "): ";

        short Choice = clsInputValidate::ReadShortNumberBetween(1, MaxOption);
        return Choice;
    }

    static void _ShowClientList()
    {

        clsClientListScreen::ShowClientsList();
    }

    static void _AddNewClient()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _DeleteClient()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _UpdateClientInfo()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _FindClient()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _Transactions()
    {
        clsTransactionsScreen::ShowTransactionsMenu();
    }

    static void _ManageUsers()
    {
        clsManageUsersScreen::ShowManageUsersMenu();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _CurrencyScreen() {
        clsCurrencyScreen::ShowCurrencyMenu();
    }

    static void _Logout()
    {
        CurrentUser.Logout();
    }

    static void _RequestExit()
    {
        CurrentUser.Logout();
        IsExitRequested = true;
    }

    static void _HandleMainMenuOption(short MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case 1:
            if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::pListClients))
            {
                cout << "Access denied.\n";
                _ReturnToMainMenu();
                break;
            }
            system("cls");
            _ShowClientList();
            _ReturnToMainMenu();
            break;
        case 2:
            if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::pAddNewClient))
            {
                cout << "Access denied.\n";
                _ReturnToMainMenu();
                break;
            }
            system("cls");
            _AddNewClient();
            _ReturnToMainMenu();
            break;
        case 3:
            if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::pDeleteClient))
            {
                cout << "Access denied.\n";
                _ReturnToMainMenu();
                break;
            }
            system("cls");
            _DeleteClient();
            _ReturnToMainMenu();
            break;
        case 4:
            if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::pUpdateClients))
            {
                cout << "Access denied.\n";
                _ReturnToMainMenu();
                break;
            }
            system("cls");
            _UpdateClientInfo();
            _ReturnToMainMenu();
            break;
        case 5:
            if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::pFindClient))
            {
                cout << "Access denied.\n";
                _ReturnToMainMenu();
                break;
            }
            system("cls");
            _FindClient();
            _ReturnToMainMenu();
            break;
        case 6:
            if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::pTransactions))
            {
                cout << "Access denied.\n";
                _ReturnToMainMenu();
                break;
            }
            system("cls");
            _Transactions();
            _ReturnToMainMenu();
            break;
        case 7:
            if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::pManageUsers))
            {
                cout << "Access denied.\n";
                _ReturnToMainMenu();
                break;
            }
            system("cls");
            _ManageUsers();
            _ReturnToMainMenu();
            break;
        case 8:
            system("cls");
            _ShowLoginRegisterScreen();
            _ReturnToMainMenu();
            break;
        case 9:
            system("cls");
            _CurrencyScreen();
            _ReturnToMainMenu();
        case 10:
            system("cls");
            _DrawScreenHeader("\tExit/Left Screen");
            cout << "\n\t[1] Exit\n\t[2] Leave\n\tChoice: ";

            short Choice = clsInputValidate::ReadShortNumberBetween(1,2);
            if (Choice == 1)
                _RequestExit();
            else
            _Logout();

            break;
        

        
        }
    }

  public:
    static void _ReturnToMainMenu()
    {
        cout << setw(37) << left << " " << "\n\tPress any key to go back to main menu...\n";
        system("pause>0");
        ShowMainMenu();
    }

    static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        short Counter = 0;
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pListClients))
            cout << setw(37) << left << "" << "\t[" << ++Counter << "] Show Client List.\n";
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pAddNewClient))
            cout << setw(37) << left << "" << "\t[" << ++Counter << "] Add New Client.\n";
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pDeleteClient))
            cout << setw(37) << left << "" << "\t[" << ++Counter << "] Delete Client.\n";
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pUpdateClients))
            cout << setw(37) << left << "" << "\t[" << ++Counter << "] Update Client.\n";
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pFindClient))
            cout << setw(37) << left << "" << "\t[" << ++Counter << "] Find Client.\n";
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pTransactions))
            cout << setw(37) << left << "" << "\t[" << ++Counter << "] Transactions.\n";
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pManageUsers))
            cout << setw(37) << left << "" << "\t[" << ++Counter << "] Manage Users.\n";
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pLoginRegister))
            cout << setw(37) << left << "" << "\t[" << ++Counter << "] Login Register.\n";
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pCurrency))
            cout << setw(37) << left << "" << "\t[" << ++Counter << "] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[" << ++Counter << "] Exit / Logout.\n";
      
        cout << setw(37) << left << "" << "===========================================\n";

        short Choice = _ReadMainMenuOption(Counter);

        Counter = 0;
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pListClients))
        {
            Counter++;
            if (Choice == Counter)
            {
                _HandleMainMenuOption(1);
                return;
            }
        }
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pAddNewClient))
        {
            Counter++;
            if (Choice == Counter)
            {
                _HandleMainMenuOption(2);
                return;
            }
        }
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pDeleteClient))
        {
            Counter++;
            if (Choice == Counter)
            {
                _HandleMainMenuOption(3);
                return;
            }
        }
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pUpdateClients))
        {
            Counter++;
            if (Choice == Counter)
            {
                _HandleMainMenuOption(4);
                return;
            }
        }
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pFindClient))
        {
            Counter++;
            if (Choice == Counter)
            {
                _HandleMainMenuOption(5);
                return;
            }
        }
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pTransactions))
        {
            Counter++;
            if (Choice == Counter)
            {
                _HandleMainMenuOption(6);
                return;
            }
        }
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pManageUsers))
        {
            Counter++;
            if (Choice == Counter)
            {
                _HandleMainMenuOption(7);
                return;
            }
        }
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pLoginRegister))
        {
            Counter++;
            if (Choice == Counter)
            {
                _HandleMainMenuOption(8);
                return;
            }
        }
        
        if (CurrentUser.CheckAccessPermission(clsUser::enPermissions::pCurrency)) {
            Counter++;
            if (Choice == Counter) {
                _HandleMainMenuOption(9);
                return;
            }
        }
        _HandleMainMenuOption(10);
    }
};
