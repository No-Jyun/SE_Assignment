#include "UserRegister.h"
#include "UserDB.h"

UserRegister::UserRegister(UserDB* refDB)
{
	refUserDB = refDB;
	refUserRegisterUI = nullptr;
}

void UserRegister::RegisterUser(string id, string pwd, string pn)
{
	refUserDB->RegisterUser(id, pwd, pn);

	string output = "> " + id + " " + pwd + " " + pn;
	refUserRegisterUI->PrintMessage(output);
}

void UserRegister::StartUserRegister(ofstream* out_fp, ifstream* in_fp)
{
	refUserRegisterUI = new UserRegisterUI(this, out_fp, in_fp);
	refUserRegisterUI->HandleInputUI();
}




UserRegisterUI::UserRegisterUI(UserRegister* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refUserRegister = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

void UserRegisterUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id, pwd, pn;
	*in_fp >> id >> pwd >> pn;
	InputUserInfo(id, pwd, pn);
}

void UserRegisterUI::PrintMessage(string info) 
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "1.1. 회원가입" << endl;
	*out_fp << info << endl;
}

void UserRegisterUI::InputUserInfo(string id, string pwd, string pn)
{
	refUserRegister->RegisterUser(id, pwd, pn);
}
