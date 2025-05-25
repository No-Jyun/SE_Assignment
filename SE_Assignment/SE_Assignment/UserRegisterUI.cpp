//
// UserRegisterUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "UserRegisterUI.h"
#include "UserRegister.h"

/*
	�Լ� �̸� : UserRegisterUI::UserRegisterUI()
	���	  : UserRegisterUI�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refControl -> ��Ʈ�� Ŭ���� ������, out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
UserRegisterUI::UserRegisterUI(UserRegister* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refUserRegister = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	�Լ� �̸� : UserRegisterUI::HandleInputUI()
	���	  : UI�� �����Ͽ� ���Ϸκ��� �Է��� ����
	���� ���� : ����
	��ȯ��    : ����
*/
void UserRegisterUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id, pwd, pn;
	*in_fp >> id >> pwd >> pn;		// �������� ID, ��й�ȣ, ��ȭ��ȣ�� �Է¹���

	InputUserInfo(id, pwd, pn);		// �Է� ó���ϴ� �Լ� ȣ��
}

/*
	�Լ� �̸� : UserRegisterUI::PrintMessage()
	���	  : ���޹��� ���ڿ��� ������Ͽ� �����
	���� ���� : info -> ����� ���ڿ�
	��ȯ��    : ����
*/
void UserRegisterUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "1.1. ȸ������" << endl;
	*out_fp << info << endl;
}

/*
	�Լ� �̸� : UserRegisterUI::InputUserInfo()
	���	  : �Է¹��� ������ ��Ʈ�� Ŭ�������� �ѱ�
	���� ���� : id -> ������ ID, pwd -> ������ ��й�ȣ, pn -> ������ ��ȭ��ȣ
	��ȯ��    : ����
*/
void UserRegisterUI::InputUserInfo(string id, string pwd, string pn)
{
	refUserRegister->RegisterUser(id, pwd, pn);		// ��Ʈ�� Ŭ�������� ������ �Ѱ�, ȸ������ ó��
}
