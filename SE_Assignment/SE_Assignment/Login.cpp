#include "Login.h"
#include "LoginMember.h"
#include "UserDB.h"

Login::Login(UserDB* refDB, LoginMember* refLoginMem)
{
	refUserDB = refDB;
	refLoginMember = refLoginMem;
	refLoginUI = nullptr;
}

void Login::LoginThisMember(string id, string pwd)
{
	if (refUserDB->IsAdmin(id, pwd) == true) {
		refLoginMember->SetAdminLogined();
	}
	else {
		MemberInfo* loginMem = refUserDB->GetThisMember(id, pwd);
		refLoginMember->SetLogined(loginMem);
	}

	string output = "> " + id + " " + pwd;
	refLoginUI->PrintMessage(output);
}

void Login::StartLogin(ofstream* out_fp, ifstream* in_fp)
{
	refLoginUI = new LoginUI(this, out_fp, in_fp);
	refLoginUI->HandleInputUI();
}




LoginUI::LoginUI(Login* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refLogin = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

void LoginUI::InputMemberInfo(string id, string pwd)
{
	refLogin->LoginThisMember(id, pwd);
}

void LoginUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id, pwd;
	*in_fp >> id >> pwd;

	InputMemberInfo(id, pwd);
}

void LoginUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "2.1. ·Î±×ÀÎ" << endl;
	*out_fp << info << endl;
}
