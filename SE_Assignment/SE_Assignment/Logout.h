//
// Logout Ŭ������ LogoutUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class Logout;
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

// ȸ������ UseCase�� ���� UI�� ����ϴ� LogoutUI Ŭ���� ����
class LogoutUI : public BaseUI
{
private:
	Logout* refLogout;		// ��ü�� ������ ��Ʈ�� Ŭ���� ������
	
public:
	LogoutUI(Logout* refControl, ofstream* out_fp, ifstream* in_fp);	// ��Ʈ�� Ŭ������ ���� ����¿� �����͸� ���޹޴� ������
	void StartLogoutUI();												// ���� ���߱�� �Լ�
	void PrintMessage(string info) override;							// ��� ���Ͽ� �����
};