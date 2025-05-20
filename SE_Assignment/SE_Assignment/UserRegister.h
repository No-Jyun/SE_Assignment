#pragma once
#include <string>
#include <fstream>

#include "BaseUI.h"
using namespace std;

class UserRegister;
class UserRegisterUI;
class UserDB;

class UserRegister 
{
private:
	UserDB* refUserDB;
	UserRegisterUI* refUserRegisterUI;

public:
	UserRegister(UserDB* refDB);
	void RegisterUser(string id, string pwd, string pn);
	void StartUserRegister(ofstream* out_fp, ifstream* in_fp);
};

class UserRegisterUI : public BaseUI 
{
private:
	UserRegister* refUserRegister;

public:
	UserRegisterUI(UserRegister* refControl, ofstream* out_fp, ifstream* in_fp);
	void HandleInputUI();
	void PrintMessage(string info) override;
	void InputUserInfo(string id, string pwd, string pn);
};