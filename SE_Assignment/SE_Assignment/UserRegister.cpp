//
// UserRegister Ŭ������ UserRegisterUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "UserRegister.h"
#include "UserDB.h"

/*
	�Լ� �̸� : UserRegister::UserRegister()
	���	  : UserRegister�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refDB -> main���� ���� UserDB�� ����Ű�� ������
	��ȯ��    : ����
*/
UserRegister::UserRegister(UserDB* refDB)
{
	refUserDB = refDB;
	refUserRegisterUI = nullptr;
}

/*
	�Լ� �̸� : UserRegister::RegisterUser()
	���	  : ���޹��� ������ UserDB�� ȸ�������� ��û�ϰ� UI�� ��½�Ŵ
	���� ���� : id -> ������ ID, pwd -> ������ ��й�ȣ, pn -> ������ ��ȭ��ȣ
	��ȯ��    : ����
*/
void UserRegister::RegisterUser(string id, string pwd, string pn)
{
	refUserDB->RegisterUser(id, pwd, pn);				// UserDB�� ������ ������ �Ѱ� ȸ������ ��Ŵ

	string output = "> " + id + " " + pwd + " " + pn;
	refUserRegisterUI->PrintMessage(output);			// �ٿ���� Ŭ�������� ��½�Ŵ
}

/*
	�Լ� �̸� : UserRegister::StartUserRegister()
	���	  : ȸ������ UseCase�� �ٿ���� Ŭ������ �����ϰ� ������
	���� ���� : out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
void UserRegister::StartUserRegister(ofstream* out_fp, ifstream* in_fp)
{
	refUserRegisterUI = new UserRegisterUI(this, out_fp, in_fp);	// �ٿ���� Ŭ���� ����
	refUserRegisterUI->HandleInputUI();								// �Է� UI ���
}




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
