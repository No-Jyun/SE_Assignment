#pragma once
#include <string>
using namespace std;

class MemberInfo;

class LoginMember 
{
private:
	MemberInfo* curLoginMember;
	bool isAdmin = false;

public:
	LoginMember();
	void SetAdminLogined();
	string SetAdminLogouted();
	bool IsAdminLogined();
	void SetLogined(MemberInfo* loginedMem);
	string SetLogouted();
	MemberInfo* GetLoginMember();
};