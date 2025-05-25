//
// UserDB Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "UserDB.h"
#include "MemberInfo.h"

/*
	�Լ� �̸� : UserDB::UserDB()
	���	  : UserDB�� ����Ʈ �����ڷ�, memberList ������ �迭�� �ʱ�ȭ��
	���� ���� : ����
	��ȯ��    : ����
*/
UserDB::UserDB() 
{
	for (int i = 0; i < 50; i++) {
		memberList[i] = nullptr;
	}
}

/*
	�Լ� �̸� : UserDB::RegisterUser()
	���	  : ���޹��� ������ ���ο� ����� ����� memberList�� ������
	���� ���� : id -> ��� ID, pwd -> ��� ��й�ȣ, pn -> ��� ��ȭ��ȣ
	��ȯ��    : ����
*/
void UserDB::RegisterUser(string id, string pwd, string pn) 
{	
	// ���ο� MemberInfo ��ü�� �����ϰ� memberList�� numList ��ġ�� �����͸� �����ϰ� numList�� ������Ŵ
	memberList[numList++] = new MemberInfo(id, pwd, pn);
}

/*
	�Լ� �̸� : UserDB::GetThisMember()
	���	  : ���޹��� id�� pwd�� ��ġ�ϴ� ����� ��ȯ��
	���� ���� : id -> ��� ID, pwd -> ��� ��й�ȣ
	��ȯ��    : MemberInfo* -> ��ġ�ϴ� MemberInfo ������
*/
MemberInfo* UserDB::GetThisMember(string id, string pwd)
{
	for (int i = 0; i < numList; i++) {						// ����� ��� MemberInfo�� ���캽
		string curId = memberList[i]->GetMemberId();		// ��� ID ������

		if (id == curId) {									// ���޹��� ID�� ���ٸ�
			string curPwd = memberList[i]->GetMemberPwd();	// ��� ��й�ȣ�� ������

			if (pwd == curPwd) {							// ���޹��� ��й�ȣ�� ���ٸ�
				return memberList[i];						// �ش� ����� ����Ű�� ������ ��ȯ
			}
		}
	}
	return nullptr;
}

/*
	�Լ� �̸� : UserDB::IsAdmin()
	���	  : ���޹��� ID�� ��й�ȣ�� ������ ID�� ��й�ȣ�� ���Ͽ� ��ġ���θ� ������
	���� ���� : id -> ��� ID, pwd -> ��� ��й�ȣ
	��ȯ��    : bool -> ������ O : true, ������ X : false
*/
bool UserDB::IsAdmin(string id, string pwd)
{
	if (id == adminId && pwd == adminPwd) {		// ���޹��� ID�� ��й�ȣ�� �����ڿ� ID�� ��й�ȣ�� ��ġ�Ѵٸ�
		return true;
	}
	else 
	{
		return false;
	}
}
