//
// Login Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

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
