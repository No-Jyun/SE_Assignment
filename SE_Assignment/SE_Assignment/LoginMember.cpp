//
// LoginMember Ŭ���� ������ ���� �ҽ� ����
// Copyright Reserved
//

#include "LoginMember.h"
#include "MemberInfo.h"

/*
	�Լ� �̸� : LoginMember::LoginMember()
	���	  : LoginMember�� ����Ʈ �����ڷ� �����͸� �ʱ�ȭ��
	���� ���� : ����
	��ȯ��    : ����
*/
LoginMember::LoginMember()
{
	curLoginMember = nullptr;
}

/*
	�Լ� �̸� : LoginMember::SetAdminLogined()
	���	  : ������ �α��� ó���� ���� isAdmin ������ true�� �ٲ�
	���� ���� : ����
	��ȯ��    : ����
*/
void LoginMember::SetAdminLogined()
{
	isAdmin = true;		// �����ڰ� �α��� �Ͽ����Ƿ� true�� �ٲ�
}

/*
	�Լ� �̸� : LoginMember::SetAdminLogouted()
	���	  : ������ �α׾ƿ� ó���� ���� isAdmin ������ false�� �ٲ�
	���� ���� : ����
	��ȯ��    : string -> ��¿� ������ Id ��ȯ
*/
string LoginMember::SetAdminLogouted()
{
	isAdmin = false;		// �����ڰ� �α׾ƿ� �Ͽ����Ƿ� false�� �ٲ�
	return "admin";			// ������ ID ��ȯ
}

/*
	�Լ� �̸� : LoginMember::IsAdminLogined()
	���	  : ���� �������� �α��� ���¸� �˷��ִ� isAdmin ������ ��ȯ����
	���� ���� : ����
	��ȯ��    : bool -> true = ������ �α��� O, false = ������ �α��� X
*/
bool LoginMember::IsAdminLogined()
{
	return this->isAdmin;
}

/*
	�Լ� �̸� : LoginMember::SetLogined()
	���	  : ���޹��� ��� �����͸� curLoginMember�� �����Ŵ
	���� ���� : loginedMem -> �α��ν�ų ��� ������
	��ȯ��    : ����
*/
void LoginMember::SetLogined(MemberInfo* loginedMem)
{
	curLoginMember = loginedMem;
}

/*
	�Լ� �̸� : LoginMember::SetLogouted()
	���	  : ��� �α׾ƿ� ó���� ���� curLoginMember�� null������ �ʱ�ȭ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ��� ID ��ȯ
*/
string LoginMember::SetLogouted()
{
	string memId = curLoginMember->GetMemberId();	// �α׾ƿ� �� ��¿� ��� ID ��������
	curLoginMember = nullptr;
	return memId;
}

/*
	�Լ� �̸� : LoginMember::GetLoginMember()
	���	  : ���� �α����� ����� �����ϱ� ���� curLoginMember�� ��ȯ����
	���� ���� : ����
	��ȯ��    : MemberInfo* -> ���� �α����� ����� ����Ű�� ������
*/
MemberInfo* LoginMember::GetLoginMember()
{
	return this->curLoginMember;
}
