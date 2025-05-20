#pragma once
#include <fstream>
#include <string>

#include "BaseUI.h"
using namespace std;

class Logout;
class LogoutUI;
class LoginMember;

class Logout 
{
private:
	LogoutUI* refLogoutUI;
	LoginMember* refLoginMember;

public:
	Logout(LoginMember* refLoginMem);
	void LogoutCurMem();
	void StartLogout(ofstream* out_fp, ifstream* in_fp);
};

class LogoutUI : public BaseUI
{
private:
	Logout* refLogout;
	
public:
	LogoutUI(Logout* refControl, ofstream* out_fp, ifstream* in_fp);
	void StartLogoutUI();
	void PrintMessage(string info) override;
};