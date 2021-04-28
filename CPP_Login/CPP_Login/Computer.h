#pragma once
#include "Macro.h"
#include "Login.h"

// Login 기능이 컴퓨터에만 있는가?
// Login은 휴대폰, 웹, 컴퓨터, ipTV ... 등에도 역시 존재한다.
// 따라서 Login 을 상속받아야함

// 기능분리 철저히 할것!!
// Computer 에 Login 기능이 있으면 안됨!

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

