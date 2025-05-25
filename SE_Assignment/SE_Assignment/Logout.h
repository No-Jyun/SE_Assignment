//
// Logout Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class LogoutUI;
class LoginMember;

// �α׾ƿ� UseCase�� ��Ʈ���ϴ� Logout Ŭ���� ����
class Logout 
{
private:
	LogoutUI* refLogoutUI;			// �α׾ƿ� UseCase�� �ٿ���� Ŭ������ LogoutUI ������
	LoginMember* refLoginMember;	// �α��� ������ ������ LoginMember ������

public:
	Logout(LoginMember* refLoginMem);						// LoginMember�� ���޹޴� ������
	void LogoutCurMem();									// ���� �α����� ��� �α׾ƿ� ó��
	void StartLogout(ofstream* out_fp, ifstream* in_fp);	// �α׾ƿ� UseCase ������
};
