#include "Computer.h"

Computer::Computer()
{

}

void Computer::Update()
{
	while (1)
	{
		if (LoginMenu() == false)
			return;

		MainDisplay();
	}
}

void Computer::MainDisplay()
{
	int iSelect;
	string checkID, checkPW;
	cout << "Atents ��ǻ�� on" << endl;
	Sleep(3000);
	while (1)
	{
		system("cls");
		cout << "========= ȯ �� �� �� �� ==========" << endl;
		cout << "1.��ǻ�� ����" << endl;
		cout << "2.���" << endl;
		cout << "3.ȸ�� ����" << endl;
		cout << "4.ȸ�� ���� ����" << endl;
		cout << "5.off" << endl;
		cout << "�Է� : ";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			StatusComp();
			break;

		case 2:
			MenuComp();
			break;

		case 3:
			ShowInfo();
			system("pause");
			break;

		case 4:
			Modify();
			system("pause");
			break;

		case 5:
			for (int i = 5; i > 0; i--)
			{
				cout << "off " << i << "�� ��" << endl;
				Sleep(1000);
			}
			return;
		}
	}
}

void Computer::StatusComp()
{
	system("cls");
	cout << "��  ǰ  �� : Atents" << endl;
	cout << "���� ���� : ON" << endl;
	cout << "�׷��� ī�� : RTX 3090" << endl;
	cout << "C   P   U : I9 9900" << endl;
	cout << "��  ��  �� : 32G" << endl;
	system("pause");
}

void Computer::MenuComp()
{
	int iSelect;
	while (1)
	{
		system("cls");
		cout << "1. ��  ��  ��" << endl;
		cout << "2. ��  ��  ��" << endl;
		cout << "3. ��  ��  ��" << endl;
		cout << "4. ���ư���" << endl;
		cout << "�Է� >>>>" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			system("calc");
			system("pause");
			break;

		case 2:
			system("notepad");
			system("pause");
			break;

		case 3:
			system("mspaint");
			system("pause");
			break;

		case 4:
			return;
		}
	}
}

Computer::~Computer()
{

}