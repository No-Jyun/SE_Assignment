//
// MemberInfo Ŭ���� ���Ǹ� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class RentList;
class BikeInfo;

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
