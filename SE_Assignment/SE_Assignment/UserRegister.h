//
// UserRegister Ŭ������ UserRegisterUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class UserRegister;
class UserRegisterUI;
class UserDB;

// ȸ������ UseCase�� ��Ʈ���ϴ� UserRegister Ŭ���� ����
class UserRegister 
{
private:
	UserDB* refUserDB;					// ��� ������ ������ UserDB ������
	UserRegisterUI* refUserRegisterUI;	// ȸ������ UseCase�� �ٿ���� Ŭ������ UserRegisterUI ������

public:
	UserRegister(UserDB* refDB);								// UserDB�� ���޹޴� ������
	void RegisterUser(string id, string pwd, string pn);		// ���޹��� ������ ȸ��������
	void StartUserRegister(ofstream* out_fp, ifstream* in_fp);	// ȸ������ UseCase ������
};

// ȸ������ UseCase�� ���� UI�� ����ϴ� UserRegisterUI Ŭ���� ����
class UserRegisterUI : public BaseUI 
{
private:
	UserRegister* refUserRegister;		// ��ü�� ������ ��Ʈ�� Ŭ���� ������

public:
	UserRegisterUI(UserRegister* refControl, ofstream* out_fp, ifstream* in_fp);	// ��Ʈ�� Ŭ������ ���� ����¿� �����͸� ���޹޴� ������
	void HandleInputUI();															// �Է� ���Ͽ��� �Է��� ����
	void PrintMessage(string info) override;										// ��� ���Ͽ� �����
	void InputUserInfo(string id, string pwd, string pn);							// �Է¹��� ������ ��Ʈ�� Ŭ������ �ѱ�
};