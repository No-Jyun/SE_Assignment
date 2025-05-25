//
// UserRegister Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class UserDB;
class UserRegisterUI;

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
