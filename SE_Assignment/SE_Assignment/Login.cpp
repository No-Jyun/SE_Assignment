//
// Login Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "Login.h"
#include "LoginUI.h"
#include "LoginMember.h"
#include "UserDB.h"

/*
	�Լ� �̸� : Login::Login()
	���	  : Login�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refDB -> main���� ���� UserDB�� ����Ű�� ������, refLoginMem -> main���� ���� LoginMember�� ����Ű�� ������
	��ȯ��    : ����
*/
Login::Login(UserDB* refDB, LoginMember* refLoginMem)
{
	refUserDB = refDB;
	refLoginMember = refLoginMem;
	refLoginUI = nullptr;
}

/*
	�Լ� �̸� : Login::LoginThisMember()
	���	  : ���޹��� ������ �˸��� ����� ã��, �ش� ����� LoginMember�� �����Ŵ
	���� ���� : id -> ��� ID, pwd -> ��� ��й�ȣ
	��ȯ��    : ����
*/
void Login::LoginThisMember(string id, string pwd)
{
	if (refUserDB->IsAdmin(id, pwd) == true) {		// ���� �α����ϴ� ����� �����ڶ��
		refLoginMember->SetAdminLogined();			// LoginMember�� ������ �α��� ó��
	}
	else {	// ���� �α����ϴ� ����� �Ϲ� ����ڶ��
		MemberInfo* loginMem = refUserDB->GetThisMember(id, pwd);	// UserDB���� �˸��� ��� ã�ƿ�
		refLoginMember->SetLogined(loginMem);						// �ش� ����� LoginMember���� �α��� ó��
	}

	string output = "> " + id + " " + pwd;
	refLoginUI->PrintMessage(output);				// �ٿ���� Ŭ�������� ��½�Ŵ
}

/*
	�Լ� �̸� : Login::StartLogin()
	���	  : �α��� UseCase�� �ٿ���� Ŭ������ �����ϰ� ������
	���� ���� : out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
void Login::StartLogin(ofstream* out_fp, ifstream* in_fp)
{
	refLoginUI = new LoginUI(this, out_fp, in_fp);	// �ٿ���� Ŭ���� ����
	refLoginUI->HandleInputUI();					// �Է� UI ���
}
