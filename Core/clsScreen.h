#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "../Models/clsBankClient.h"
#include "../Models/clsUser.h"
#include <string>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsDate.h"
#include "clsString.h"
#include "Global.h"
class clsScreen
{
  protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        clsDate Date;
        cout << "\t\t\t\t\tUser: " << setw(16) << left << CurrentUser.UserName << " | Date: "
             << clsDate::DateToString(clsDate()) << "\n\n";
    }
};
