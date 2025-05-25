//
// UserRegister Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "UserRegister.h"
#include "UserRegisterUI.h"
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
