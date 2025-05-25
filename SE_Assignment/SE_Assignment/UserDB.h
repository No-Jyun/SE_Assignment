//
// UserDB Ŭ���� ���Ǹ� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class MemberInfo;

// ȸ�������� ����� �����ϱ� ���� UserDB Ŭ���� ����
class UserDB 
{
private:
	MemberInfo* memberList[50];		// ��� �����ϱ� ���� MemberInfo �������� �迭
	int numList = 0;				// memberList �迭 ������ġ �� ���� ������
	string adminId = "admin";		// ������ ID
	string adminPwd = "admin";		// ������ ��й�ȣ

public:
	UserDB();												// ����Ʈ ������
	void RegisterUser(string id, string pwd, string pn);	// ���޹��� id, pwd, pn���� ���ο� ����� ����� ������
	MemberInfo* GetThisMember(string id, string pwd);		// ���޹��� id, pwd�� ���� ����� ��ȯ��
	bool IsAdmin(string id, string pwd);					// ���޹��� id, pwd�� ���������� Ȯ����
};
