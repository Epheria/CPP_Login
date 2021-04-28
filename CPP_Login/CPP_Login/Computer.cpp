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
	cout << "Atents 컴퓨터 on" << endl;
	Sleep(3000);
	while (1)
	{
		system("cls");
		cout << "========= 환 영 합 니 다 ==========" << endl;
		cout << "1.컴퓨터 상태" << endl;
		cout << "2.기능" << endl;
		cout << "3.회원 정보" << endl;
		cout << "4.회원 정보 변경" << endl;
		cout << "5.off" << endl;
		cout << "입력 : ";
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
				cout << "off " << i << "초 전" << endl;
				Sleep(1000);
			}
			return;
		}
	}
}

void Computer::StatusComp()
{
	system("cls");
	cout << "제  품  명 : Atents" << endl;
	cout << "현재 상태 : ON" << endl;
	cout << "그래픽 카드 : RTX 3090" << endl;
	cout << "C   P   U : I9 9900" << endl;
	cout << "메  모  리 : 32G" << endl;
	system("pause");
}

void Computer::MenuComp()
{
	int iSelect;
	while (1)
	{
		system("cls");
		cout << "1. 계  산  기" << endl;
		cout << "2. 메  모  장" << endl;
		cout << "3. 그  림  판" << endl;
		cout << "4. 돌아가기" << endl;
		cout << "입력 >>>>" << endl;
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