//
// Login Ŭ������ LoginUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class Login;
class LoginUI;
class UserDB;
class LoginMember;

// �α��� UseCase�� ��Ʈ���ϴ� Login Ŭ���� ����
class Login 
{
private:
	LoginUI* refLoginUI;			// �α��� UseCase�� �ٿ���� Ŭ������ LoginUI ������ 
	UserDB* refUserDB;				// ��� ������ ������ UserDB ������
	LoginMember* refLoginMember;	// �α��� ������ ������ LoginMember ������

public:
	Login(UserDB* refDB, LoginMember* refLoginMem);		// UserDB�� LoginMember�� ���޹޴� ������
	void LoginThisMember(string id, string pwd);		// ���޹��� ������ �α�����
	void StartLogin(ofstream* out_fp, ifstream* in_fp);	// �α��� UseCase ������
};

// �α��� UseCase�� ���� UI�� ����ϴ� LoginUI Ŭ���� ����
class LoginUI : public BaseUI
{
private:
	Login* refLogin;		// ��ü�� ������ ��Ʈ�� Ŭ���� ������

public:
	LoginUI(Login* refControl, ofstream* out_fp, ifstream* in_fp);	// ��Ʈ�� Ŭ������ ���� ����¿� �����͸� ���޹޴� ������
	void InputMemberInfo(string id, string pwd);					// �Է¹��� ������ ��Ʈ�� Ŭ������ �ѱ�
	void HandleInputUI();											// �Է� ���Ͽ��� �Է��� ����
	void PrintMessage(string info) override;						// ��� ���Ͽ� �����
};