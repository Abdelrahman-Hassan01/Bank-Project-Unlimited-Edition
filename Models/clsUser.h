#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <clsDate.h>
#include <clsUtil.h>
using namespace std;
class clsUser : public clsPerson
{
  public:
    struct stLoginRegisterRecord
    {

        string DateTime;
        string UserName;
        string Password;
        int Permissions;
    };

  private:
    enum class enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;
    void _ResetToEmptyUser()
    {
        *this = _GetEmptyUser();
    }
    bool _IsMarkedForDeletion = false;

    static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Separator);
        if (vUserData.size() == 7)
        {
            return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4],
                           clsUtil::DecryptText(vUserData[5], 5), stoi(vUserData[6]));
        }
        else
            return _GetEmptyUser();
    }

    static vector<string> _ConvertLineToLoginRegisterRecord(string Line, string Separator = "#//#")
    {
        vector<string> vLoginRegister;
        vLoginRegister = clsString::Split(Line, Separator);

        return vLoginRegister;
    }
    static string _ConvertUserToLine(clsUser User, string Separator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Separator;
        UserRecord += User.LastName + Separator;
        UserRecord += User.Email + Separator;
        UserRecord += User.Phone + Separator;
        UserRecord += User.UserName + Separator;
        UserRecord += clsUtil::EncryptText(User.Password, 5) + Separator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;
    }

    string _BuildLoginRegisterRecord(string Separator = "#//#")
    {
        string LoginRecord;
        LoginRecord += clsDate::GetSystemDateTimeString() + Separator;
        LoginRecord += UserName + Separator;
        LoginRecord += clsUtil::EncryptText(Password, 3) + Separator;
        LoginRecord += to_string(Permissions);
        return LoginRecord;
    }

    static vector<clsUser> _LoadUsersFromFile()
    {

        vector<clsUser> vUsers;

        fstream MyFile;
        MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Users.txt",
                    ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLineToUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();
        }

        return vUsers;
    }

    static vector<stLoginRegisterRecord> _LoadLoginRegisterRecords()
    {
        vector<stLoginRegisterRecord> vLogs;
        ifstream MyFile("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\LoginRegister.txt");
        string Line;

        while (getline(MyFile, Line))
        {
            vector<string> Fields = _ConvertLineToLoginRegisterRecord(Line);
            if (Fields.size() < 4)
                continue;

            stLoginRegisterRecord Record;
            Record.DateTime = Fields[0];
            Record.UserName = Fields[1];
            Record.Password = Fields[2];
            Record.Permissions = stoi(Fields[3]);
            vLogs.push_back(Record);
        }

        return vLogs;
    }

    static void _SaveUsersToFile(vector<clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Users.txt",
                    ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsUser U : vUsers)
            {
                if (U.IsMarkedForDeletion() == false)
                {
                    DataLine = _ConvertUserToLine(U);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _UpdateUser()
    {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersFromFile();

        for (clsUser &U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }
        }

        _SaveUsersToFile(_vUsers);
    }

    void _AddNewUser()
    {

        _AppendUserRecord(_ConvertUserToLine(*this));
    }

    void _AppendUserRecord(string DataLine)
    {
        fstream MyFile;
        MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Users.txt",
                    ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

    static clsUser _GetEmptyUser()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

  public:
    enum enPermissions
    {
        eAll = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClients = 8,
        pFindClient = 16,
        pTransactions = 32,
        pManageUsers = 64,
        pLoginRegister = 128,
        pCurrency = 256
    };

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName,
            string Password, int Permissions)
        : clsPerson(FirstName, LastName, Phone, Email)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool IsMarkedForDeletion()
    {
        return _IsMarkedForDeletion;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Users.txt",
                    ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }

        return _GetEmptyUser();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Users.txt",
                    ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }
        return _GetEmptyUser();
    }

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedUserExists = 2
    };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode: {
            if (IsEmpty())
            {
                return enSaveResults::svFailedEmptyObject;
            }
        }

        case enMode::UpdateMode: {
            _UpdateUser();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode: {
            // This will add new record to file or database
            if (clsUser::UserExists(_UserName))
            {
                return enSaveResults::svFailedUserExists;
            }
            else
            {
                _AddNewUser();
                // We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }
    }

    static bool UserExists(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersFromFile();

        for (clsUser &U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._IsMarkedForDeletion = true;
                break;
            }
        }

        _SaveUsersToFile(_vUsers);

        *this = _GetEmptyUser();

        return true;
    }

    void Logout()
    {
        _ResetToEmptyUser();
    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector<clsUser> GetUsersList()
    {
        return _LoadUsersFromFile();
    }

    static vector<stLoginRegisterRecord> GetLoginRegisterRecords()
    {
        return _LoadLoginRegisterRecords();
    }

    void RegisterLogin()
    {
        string LoginRecordLine = _BuildLoginRegisterRecord();
        fstream MyFile;
        MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\LoginRegister.txt",
                    ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << LoginRecordLine << endl;
            MyFile.close();
        }
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;
    }
};
