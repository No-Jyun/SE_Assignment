//
// LoginUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "LoginUI.h"
#include "Login.h"

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
