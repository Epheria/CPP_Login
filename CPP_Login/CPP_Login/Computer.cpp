#include "Computer.h"

Computer::Computer()
{

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

void Computer::ShowMenu()
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