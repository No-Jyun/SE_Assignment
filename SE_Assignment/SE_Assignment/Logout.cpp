//
// Logout Ŭ������ LogoutUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "Logout.h"
#include "LoginMember.h"

/*
	�Լ� �̸� : Logout::Logout()
	���	  : Logout�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refLoginMem -> main���� ���� LoginMember�� ����Ű�� ������
	��ȯ��    : ����
*/
Logout::Logout(LoginMember* refLoginMem)
{
	refLoginMember = refLoginMem;
	refLogoutUI = nullptr;
}

/*
	�Լ� �̸� : Logout::LogoutCurMem()
	���	  : LoginMember�� ����� �α��� ������ �α׾ƿ� ó����
	���� ���� : ����
	��ȯ��    : ����
*/
void Logout::LogoutCurMem()
{
	string memId = "";
	if (refLoginMember->IsAdminLogined() == true) {		// ���� �α����� ����� �����ڶ��
		memId = refLoginMember->SetAdminLogouted();		// ������ �α׾ƿ� ó��
	}
	else {												// ���� �α����� ����� �Ϲ� ����ڶ��
		memId = refLoginMember->SetLogouted();			// ��� �α׾ƿ� ó��
	}

	string output = "> " + memId;
	refLogoutUI->PrintMessage(output);					// �ٿ���� Ŭ�������� ��½�Ŵ
}

/*
	�Լ� �̸� : Logout::StartLogout()
	���	  : �α׾ƿ� UseCase�� �ٿ���� Ŭ������ �����ϰ� ������
	���� ���� : out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
void Logout::StartLogout(ofstream* out_fp, ifstream* in_fp)
{
	refLogoutUI = new LogoutUI(this, out_fp, in_fp);	// �ٿ���� Ŭ���� ����
	refLogoutUI->StartLogoutUI();						// �Է� UI ���
}




/*
	�Լ� �̸� : LogoutUI::LogoutUI()
	���	  : LogoutUI�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refControl -> ��Ʈ�� Ŭ���� ������, out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
LogoutUI::LogoutUI(Logout* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refLogout = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	�Լ� �̸� : LogoutUI::StartLogoutUI()
	���	  : ���� ���߱�� �Լ���, ��Ʈ�� Ŭ�������� �α׾ƿ� ó�� ��û
	���� ���� : ����
	��ȯ��    : ����
*/
void LogoutUI::StartLogoutUI()
{
	refLogout->LogoutCurMem();
}

/*
	�Լ� �̸� : LogoutUI::PrintMessage()
	���	  : ���޹��� ���ڿ��� ������Ͽ� �����
	���� ���� : info -> ����� ���ڿ�
	��ȯ��    : ����
*/
void LogoutUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "2.2. �α׾ƿ�" << endl;
	*out_fp << info << endl;
}
