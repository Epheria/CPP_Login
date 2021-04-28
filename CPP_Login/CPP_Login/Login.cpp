#include "Login.h"

Login::Login()
{
	m_iCur = 0;
}

bool Login::LoginMenu()
{
	int iSelect;

	while (1)
	{
		system("cls");
		ShowMenu();
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			if (m_UserList.size() >= MAX_ACCOUNT)
				cout << "인원초과! 더 이상 추가할 수 없습니다." << endl;
			else
				CreateAccount();
			system("pause");
			break;

		case 2:
			if (GetLogin() == true)
				return true;
			break;

		case 3:
			return false;
		}
	}
}

bool Login::GetLogin()
{
	bool flag;
	string checkID, checkPW;
	if (m_UserList.empty())
	{
		cout << "회원가입한 유저가 없습니다." << endl;
		return false;
	}

	while (1)
	{
		system("cls");
		cout << "아이디 입력 : ";
		cin >> checkID;
		cout << "비밀번호 입력 : ";
		cin >> checkPW;
		if (!CheckLogin(checkID, checkPW))
		{
			cout << "해당 아이디가 없거나 비밀번호가 틀렸습니다." << endl;
			system("pause");
			flag = false;
		}
		else
		{
			flag = true;
			break;
		}
	}

	return flag;
}

void Login::CreateAccount()
{
	Account tmp;
	string inputPW;

	while (1)
	{
		system("cls");
		cout << "아이디 입력([3글자이상], [한글x]): ";
		cin >> tmp.m_strID;
		if (CheckID(tmp) == false)
		{
			system("pause");
			continue;
		}
		else
		{
			system("cls");
			cout << "비밀번호 입력([8글자이상], [영문&숫자포함]): ";
			cin >> inputPW;
			cout << "비밀번호 확인 : ";
			cin >> tmp.m_strPW;
			if (CheckPW(tmp, inputPW) == false)
			{
				system("pause");
				continue;
			}
			else
				break;
		}
	}

	system("cls");
	cout << "닉네임 입력 : ";
	cin >> tmp.m_strNickName;
	cout << "나이 입력 : ";
	cin >> tmp.m_iAge;
	cout << "휴대폰 번호 입력 : ";
	cin >> tmp.m_strPhoneNum;
	cout << "회원가입 성공 !! 마일리지 1000원 등록" << endl;
	tmp.m_iMile = 1000;

	m_UserList.push_back(tmp);
}

bool Login::CheckID(Account tmp)
{
	bool flag = true;

	for (vector<Account>::iterator iter = m_UserList.begin(); iter != m_UserList.end(); iter++)
	{
		if (tmp.m_strID == iter->m_strID)
		{
			cout << "이미 똑같은 id가 있습니다." << endl;
			flag = false;
			break;
		}
	}

	for (int j = 0; j < tmp.m_strID.length(); j++)
	{
		if (tmp.m_strID[j] < '0' || (tmp.m_strID[j] > '9' && tmp.m_strID[j] < 'A') ||
			(tmp.m_strID[j] > 'Z' && tmp.m_strID[j] < 'a') || tmp.m_strID[j] > 'z')
		{
			cout << "숫자나 영어가아닙니다" << endl;
			flag = false;
			break;
		}
	}

	if (tmp.m_strID.length() < 3)
	{
		cout << "아이디가 3글자 이하입니다.\n";
		flag = false;
	}

	return flag;
}

bool Login::CheckPW(Account tmp, string inputPW)
{
	bool flag = true;
	int iCount = 0;

	if (inputPW != tmp.m_strPW)
	{
		cout << "비밀번호가 일치하지 않습니다." << endl;
		flag = false;
	}

	if (inputPW.length() < 8)
	{
		cout << "Password가 8글자 이하입니다." << endl;
		flag = false;
	}

	for (int j = 0; j < tmp.m_strPW.length(); j++)
	{
		if (tmp.m_strPW[j] < '0' || (tmp.m_strPW[j] > '9' && tmp.m_strPW[j] < 'A') ||
			(tmp.m_strPW[j] > 'Z' && tmp.m_strPW[j] < 'a') || tmp.m_strPW[j] > 'z')
		{
			cout << "숫자나 영문이 아닙니다." << endl;
			flag = false;
			break;
		}
	}

	for (int i = 0; i < tmp.m_strPW.length(); i++)
	{
		if (tmp.m_strPW[i] >= '0' && tmp.m_strPW[i] <= '9')
		{
			iCount++;
		}
	}
	if (iCount == 0)
	{
		cout << "숫자가 포함되어 있지 않습니다." << endl;
		flag = false;
	}

	return flag;
}

bool Login::CheckLogin(string checkID, string checkPW)
{
	m_iCur = 0;
	for (vector<Account>::iterator iter = m_UserList.begin(); iter != m_UserList.end(); iter++)
	{
		if (checkID == iter->m_strID && checkPW == iter->m_strPW)
			return true;
		m_iCur++;
	}
	return false;
}

void Login::ShowInfo()
{
	cout << "========== 회원 정보 ==========" << endl;
	cout << "ID : " << m_UserList[m_iCur].m_strID << "    닉네임 : " << m_UserList[m_iCur].m_strNickName << endl;
	cout << "나이 : " << m_UserList[m_iCur].m_iAge << "    휴대폰 번호 : " << m_UserList[m_iCur].m_strPhoneNum << endl;
	cout << "마일리지 : " << m_UserList[m_iCur].m_iMile << "원" << endl;
	cout << "================================" << endl;
	return;
}

void Login::ShowMenu()
{
	cout << "====== Login Program ======(회원수[" << m_UserList.size() << "명])" << endl;
	cout << "1. 회원가입" << endl;
	cout << "2. 로그인" << endl;
	cout << "3. 종료" << endl;
	cout << "===========================" << endl;
	cout << "메뉴 선택 : ";
}

void Login::Modify()
{
	int iSelect;
	string cNickname, cPhoneNum;
	int cAge;
	while (1)
	{
		system("cls");
		ShowInfo();
		cout << "1. 닉네임 변경" << endl;
		cout << "2. 나이 변경" << endl;
		cout << "3. 휴대폰 번호 변경" << endl;
		cout << "4. 돌아가기" << endl;
		cout << "입력 : ";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "현재 닉네임 : " << m_UserList[m_iCur].m_strNickName << endl;
			cout << "변경할 닉네임 입력 : ";
			cin >> cNickname;
			cout << m_UserList[m_iCur].m_strNickName << " -> " << cNickname << endl;
			m_UserList[m_iCur].m_strNickName = cNickname;
			break;

		case 2:
			cout << "현재 나이 : " << m_UserList[m_iCur].m_iAge << endl;
			cout << "변경할 나이 입력 : ";
			cin >> cAge;
			cout << m_UserList[m_iCur].m_iAge << " -> " << cAge << endl;
			m_UserList[m_iCur].m_iAge = cAge;
			break;

		case 3:
			cout << "현재 휴대폰 번호 : " << m_UserList[m_iCur].m_strPhoneNum << endl;
			cout << "변경할 휴대폰 번호 입력 : ";
			cin >> cPhoneNum;
			cout << m_UserList[m_iCur].m_strPhoneNum << " -> " << cPhoneNum << endl;
			m_UserList[m_iCur].m_strPhoneNum = cPhoneNum;
			break;

		case 4:
			return;
		}
	}
}

Login::~Login()
{

}