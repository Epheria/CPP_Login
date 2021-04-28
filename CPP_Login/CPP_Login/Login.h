#pragma once
#include "Macro.h"

typedef struct Account
{
	string m_strID;
	string m_strPW;
	string m_strNickName;
	string m_strPhoneNum;
	int m_iAge;
	int m_iMile;
}Account;

class Login
{
private:
	int m_iCur;
	vector<Account> m_UserList;
public:
	bool LoginMenu();
	void ShowMenu();
	void CreateAccount();
	bool GetLogin();
	bool CheckID(Account tmp);
	bool CheckPW(Account tmp, string inputPW);
	bool CheckLogin(string checkID, string checkPW);
	void ShowInfo();
	void Modify();

	Login();
	~Login();
};

