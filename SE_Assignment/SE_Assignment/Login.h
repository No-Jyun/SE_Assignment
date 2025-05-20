#pragma once
#include <string>
#include <fstream>

#include "BaseUI.h"
using namespace std;

class Login;
class LoginUI;
class UserDB;
class LoginMember;

class Login 
{
private:
	LoginUI* refLoginUI;
	UserDB* refUserDB;
	LoginMember* refLoginMember;

public:
	Login(UserDB* refDB, LoginMember* refLoginMem);
	void LoginThisMember(string id, string pwd);
	void StartLogin(ofstream* out_fp, ifstream* in_fp);
};

class LoginUI : public BaseUI
{
private:
	Login* refLogin;

public:
	LoginUI(Login* refControl, ofstream* out_fp, ifstream* in_fp);
	void InputMemberInfo(string id, string pwd);
	void HandleInputUI();
	void PrintMessage(string info) override;
};