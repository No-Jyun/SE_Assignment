//
// UserDB Ŭ������ MemberInfo Ŭ���� ���Ǹ� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class UserDB;
class MemberInfo;
class RentList;
class BikeInfo;

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

// ��� ������ �����ϱ� ���� MemberInfo Ŭ���� ����
class MemberInfo
{
private:
	string id;					// ��� ID
	string pwd;					// ��� ��й�ȣ
	string pn;					// ��� ��ȭ��ȣ
	RentList* rentBikeList;		// ����� ���� ������ ����Ʈ �����ϴ� RentList ������

public:
	MemberInfo(string id, string pwd, string pn);	// ��� ������ ���޹޴� ������
	string GetMemberId();							// ����� ID�� ��ȯ��
	string GetMemberPwd();							// ����� ��й�ȣ�� ��ȯ��
	void AddBiketoList(BikeInfo* curBike);			// �����Ÿ� �뿩 ����Ʈ�� ������
	RentList* GetRentList();						// ���� ������ ����Ʈ�� ��ȯ��
};
