#pragma once
#include "Macro.h"
#include "Login.h"

// Login ����� ��ǻ�Ϳ��� �ִ°�?
// Login�� �޴���, ��, ��ǻ��, ipTV ... ��� ���� �����Ѵ�.
// ���� Login �� ��ӹ޾ƾ���

// ��ɺи� ö���� �Ұ�!!
// Computer �� Login ����� ������ �ȵ�!

class Computer : public Login
{
private:

public:
	void StatusComp();
	void MenuComp();
	void Update();
	void MainDisplay();
	Computer();
	~Computer();
};

