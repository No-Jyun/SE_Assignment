#include "Logout.h"
#include "LoginMember.h"

Logout::Logout(LoginMember* refLoginMem)
{
	refLoginMember = refLoginMem;
	refLogoutUI = nullptr;
}

void Logout::LogoutCurMem()
{
	string memId = "";
	if (refLoginMember->IsAdminLogined() == true) {
		memId = refLoginMember->SetAdminLogouted();
	}
	else {
		memId = refLoginMember->SetLogouted();
	}

	string output = "> " + memId;
	refLogoutUI->PrintMessage(output);
}

void Logout::StartLogout(ofstream* out_fp, ifstream* in_fp)
{
	refLogoutUI = new LogoutUI(this, out_fp, in_fp);
	refLogoutUI->StartLogoutUI();
}




LogoutUI::LogoutUI(Logout* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refLogout = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

void LogoutUI::StartLogoutUI()
{
	// 시작하기
	refLogout->LogoutCurMem();
}

void LogoutUI::PrintMessage(string info)
{
	// 출력 하기
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "2.2. 로그아웃" << endl;
	*out_fp << info << endl;
}
