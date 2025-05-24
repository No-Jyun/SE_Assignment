//
// Login Ŭ������ LoginUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "Login.h"
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




/*
	�Լ� �̸� : LoginUI::LoginUI()
	���	  : LoginUI�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refControl -> ��Ʈ�� Ŭ���� ������, out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
LoginUI::LoginUI(Login* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refLogin = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	�Լ� �̸� : LoginUI::InputMemberInfo()
	���	  : �Է¹��� ������ ��Ʈ�� Ŭ�������� �ѱ�
	���� ���� : id -> ��� ID, pwd -> ��� ��й�ȣ
	��ȯ��    : ����
*/
void LoginUI::InputMemberInfo(string id, string pwd)
{
	refLogin->LoginThisMember(id, pwd);
}

/*
	�Լ� �̸� : LoginUI::HandleInputUI()
	���	  : UI�� �����Ͽ� ���Ϸκ��� �Է��� ����
	���� ���� : ����
	��ȯ��    : ����
*/
void LoginUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id, pwd;
	*in_fp >> id >> pwd;		// �α����Ϸ��� ����� ID, ��й�ȣ�� �Է¹���

	InputMemberInfo(id, pwd);	// �Է� ó���ϴ� �Լ� ȣ��
}

/*
	�Լ� �̸� : LoginUI::PrintMessage()
	���	  : ���޹��� ���ڿ��� ������Ͽ� �����
	���� ���� : info -> ����� ���ڿ�
	��ȯ��    : ����
*/
void LoginUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "2.1. �α���" << endl;
	*out_fp << info << endl;
}
