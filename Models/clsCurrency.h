#pragma once
#include <fstream>
#include <clsString.h>
#include <string>

class clsCurrency
{
private:
	enum enMode { EmptyMode, UpdateMode };

	enMode _Mode;

	string _Country;

	string _CurrencyCode;

	string _CurrencyName;

	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line , string Separator = "#//#") {
		vector<string> vCurrencyData = clsString::Split(Line, Separator);
		if (vCurrencyData.size() == 4)
		{
			return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
		}
		return _GetEmptyCurrencyObject();
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#") {
		string Result = "";

		Result += Currency._Country + Separator;
		Result += Currency._CurrencyCode + Separator;
		Result += Currency._CurrencyName + Separator;
		Result += to_string(Currency._Rate) + Separator;
		return Result;
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static bool _SaveCurrencyDataToFile(vector<clsCurrency> _vCurrency) {
		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Currencies.txt", ios::out);

		if (MyFile.is_open()) {
			string Line;
			for (clsCurrency& Currency : _vCurrency) {
				Line = _ConvertCurrencyObjectToLine(Currency);
				MyFile << Line << endl;
			}
			return true;
		}
		return false;
	}

	static vector<clsCurrency> _LoadCurrencyFromFile() {
		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Currencies.txt", ios::in);
		vector<clsCurrency> vCurrency;

		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(line);

				vCurrency.push_back(Currency);
			}
		}
		return vCurrency;
	}

	void _Update() {
		vector<clsCurrency> vCurrency = _LoadCurrencyFromFile();

		for (clsCurrency& C : vCurrency) {
			
			if (C.CurrencyCode() == CurrencyCode()) {

				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrency);
	}
public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty() {
		return _Mode == EmptyMode;
	}

	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	void UpdateRate(float Rate) {
		_Rate = Rate;
		_Update();
	}

	float GetRate() {
		return _Rate;
	}

	__declspec(property(get = GetRate, put = UpdateRate)) float Rate;

	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Currencies.txt");

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country) {
					MyFile.close();
					return Currency;
				}
			}
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCode(string Code) {
		Code = clsString::UpperAllString(Code);

		fstream MyFile;
		MyFile.open("C:\\Users\\Elnour Tech\\source\\repos\\Bank System v04\\Bank System v04\\Currencies.txt");

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.CurrencyCode()) == Code) {
					MyFile.close();
					return Currency;
				}
			}
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyCodeExist(string Code) {
		clsCurrency Currency = clsCurrency::FindByCode(Code);
		return (!Currency.IsEmpty());
	}

	static bool IsCurrencyNameExist(string Country) {
		clsCurrency Currency = clsCurrency::FindByCountry(Country);
		return (!Currency.IsEmpty());
	}
	static vector <clsCurrency> GetCurrencyList() {
		return _LoadCurrencyFromFile();
	}

	double ConvertToUSD(double Amount)
	{
		return (double)(Amount / Rate);
	}

	double ConvertToOtherCurrency(double Amount, clsCurrency Currency2)
	{
		double AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (double)(AmountInUSD * Currency2.Rate);

	}

};

