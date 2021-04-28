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
				cout << "�ο��ʰ�! �� �̻� �߰��� �� �����ϴ�." << endl;
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
		cout << "ȸ�������� ������ �����ϴ�." << endl;
		return false;
	}

	while (1)
	{
		system("cls");
		cout << "���̵� �Է� : ";
		cin >> checkID;
		cout << "��й�ȣ �Է� : ";
		cin >> checkPW;
		if (!CheckLogin(checkID, checkPW))
		{
			cout << "�ش� ���̵� ���ų� ��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
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
		cout << "���̵� �Է�([3�����̻�], [�ѱ�x]): ";
		cin >> tmp.m_strID;
		if (CheckID(tmp) == false)
		{
			system("pause");
			continue;
		}
		else
		{
			system("cls");
			cout << "��й�ȣ �Է�([8�����̻�], [����&��������]): ";
			cin >> inputPW;
			cout << "��й�ȣ Ȯ�� : ";
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
	cout << "�г��� �Է� : ";
	cin >> tmp.m_strNickName;
	cout << "���� �Է� : ";
	cin >> tmp.m_iAge;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> tmp.m_strPhoneNum;
	cout << "ȸ������ ���� !! ���ϸ��� 1000�� ���" << endl;
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
			cout << "�̹� �Ȱ��� id�� �ֽ��ϴ�." << endl;
			flag = false;
			break;
		}
	}

	for (int j = 0; j < tmp.m_strID.length(); j++)
	{
		if (tmp.m_strID[j] < '0' || (tmp.m_strID[j] > '9' && tmp.m_strID[j] < 'A') ||
			(tmp.m_strID[j] > 'Z' && tmp.m_strID[j] < 'a') || tmp.m_strID[j] > 'z')
		{
			cout << "���ڳ� ����ƴմϴ�" << endl;
			flag = false;
			break;
		}
	}

	if (tmp.m_strID.length() < 3)
	{
		cout << "���̵� 3���� �����Դϴ�.\n";
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
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		flag = false;
	}

	if (inputPW.length() < 8)
	{
		cout << "Password�� 8���� �����Դϴ�." << endl;
		flag = false;
	}

	for (int j = 0; j < tmp.m_strPW.length(); j++)
	{
		if (tmp.m_strPW[j] < '0' || (tmp.m_strPW[j] > '9' && tmp.m_strPW[j] < 'A') ||
			(tmp.m_strPW[j] > 'Z' && tmp.m_strPW[j] < 'a') || tmp.m_strPW[j] > 'z')
		{
			cout << "���ڳ� ������ �ƴմϴ�." << endl;
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
		cout << "���ڰ� ���ԵǾ� ���� �ʽ��ϴ�." << endl;
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
	cout << "========== ȸ�� ���� ==========" << endl;
	cout << "ID : " << m_UserList[m_iCur].m_strID << "    �г��� : " << m_UserList[m_iCur].m_strNickName << endl;
	cout << "���� : " << m_UserList[m_iCur].m_iAge << "    �޴��� ��ȣ : " << m_UserList[m_iCur].m_strPhoneNum << endl;
	cout << "���ϸ��� : " << m_UserList[m_iCur].m_iMile << "��" << endl;
	cout << "================================" << endl;
	return;
}

void Login::ShowMenu()
{
	cout << "====== Login Program ======(ȸ����[" << m_UserList.size() << "��])" << endl;
	cout << "1. ȸ������" << endl;
	cout << "2. �α���" << endl;
	cout << "3. ����" << endl;
	cout << "===========================" << endl;
	cout << "�޴� ���� : ";
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
		cout << "1. �г��� ����" << endl;
		cout << "2. ���� ����" << endl;
		cout << "3. �޴��� ��ȣ ����" << endl;
		cout << "4. ���ư���" << endl;
		cout << "�Է� : ";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "���� �г��� : " << m_UserList[m_iCur].m_strNickName << endl;
			cout << "������ �г��� �Է� : ";
			cin >> cNickname;
			cout << m_UserList[m_iCur].m_strNickName << " -> " << cNickname << endl;
			m_UserList[m_iCur].m_strNickName = cNickname;
			break;

		case 2:
			cout << "���� ���� : " << m_UserList[m_iCur].m_iAge << endl;
			cout << "������ ���� �Է� : ";
			cin >> cAge;
			cout << m_UserList[m_iCur].m_iAge << " -> " << cAge << endl;
			m_UserList[m_iCur].m_iAge = cAge;
			break;

		case 3:
			cout << "���� �޴��� ��ȣ : " << m_UserList[m_iCur].m_strPhoneNum << endl;
			cout << "������ �޴��� ��ȣ �Է� : ";
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