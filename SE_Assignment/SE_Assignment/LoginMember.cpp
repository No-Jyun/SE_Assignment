#include "LoginMember.h"
#include "UserDB.h"

LoginMember::LoginMember()
{
	curLoginMember = nullptr;
}

void LoginMember::SetAdminLogined()
{
	isAdmin = true;
}

string LoginMember::SetAdminLogouted()
{
	isAdmin = false;
	return "admin";
}

bool LoginMember::IsAdminLogined()
{
	return isAdmin;
}

void LoginMember::SetLogined(MemberInfo* loginedMem)
{
	curLoginMember = loginedMem;
}

string LoginMember::SetLogouted()
{
	string memId = curLoginMember->GetMemberId();
	curLoginMember = nullptr;
	return memId;
}

MemberInfo* LoginMember::GetLoginMember()
{
	return curLoginMember;
}
