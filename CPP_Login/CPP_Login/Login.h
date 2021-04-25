#pragma once
#include "Macro.h"
#include "Computer.h"

typedef struct Account
{
	string m_strID;
	string m_strPW;
	string m_strNickName;
	string m_strPhoneNum;
	int m_iAge;
	int m_iMile;
}Account;

class Login : public Computer
{
private:
	int m_iCur;
	Account m_User;
	vector<Account> m_UserList;
	Computer m_Com;
public:
	void Update();
	void ShowMenu();
	void CreateAccount();
	bool CheckID(Account tmp);
	bool CheckPW(Account tmp, string inputPW);
	void GetLogin();
	bool CheckLogin(string checkID, string checkPW);
	void ShowInfo();
	void Modify();

	Login();
	~Login();
};

