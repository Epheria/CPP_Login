#include "Computer.h"

Computer::Computer()
{

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

void Computer::ShowMenu()
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