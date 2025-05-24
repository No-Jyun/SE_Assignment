//
// LoginMember Ŭ���� ���Ǹ� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class MemberInfo;

// �α��� ������ �����ϱ� ���� LoginMember Ŭ���� ����
class LoginMember 
{
private:
	MemberInfo* curLoginMember;		// ���� �α����� ��� ����� ������
	bool isAdmin = false;			// ������ �α��ο�

public:
	LoginMember();								// ����Ʈ ������
	void SetAdminLogined();						// ������ �α��� ó����
	string SetAdminLogouted();					// ������ �α׾ƿ� ó����
	bool IsAdminLogined();						// ���� �α����� ����� ���������� �˷���
	void SetLogined(MemberInfo* loginedMem);	// ���޹��� ����� �α��� ó����
	string SetLogouted();						// ���� �α����� ��� �α׾ƿ� ó����
	MemberInfo* GetLoginMember();				// ���� �α����� ��� ��ȯ��
};