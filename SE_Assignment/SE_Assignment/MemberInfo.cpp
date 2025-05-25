//
// MemberInfo Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "MemberInfo.h"
#include "RentList.h"
#include "BikeDB.h"

/*
	�Լ� �̸� : MemberInfo::MemberInfo()
	���	  : MemberInfo�� �����ڷ�, ���޹��� ������ ��������� �ʱ�ȭ�ϰ� RentList��ü�� ����� rentBikeList�� �ʱ�ȭ��
	���� ���� : id -> ��� ID, pwd -> ��� ��й�ȣ, pn -> ��� ��ȭ��ȣ
	��ȯ��    : ����
*/
MemberInfo::MemberInfo(string id, string pwd, string pn)
{
	this->id = id;
	this->pwd = pwd;
	this->pn = pn;

	rentBikeList = new RentList();
}

/*
	�Լ� �̸� : MemberInfo::GetMemberId()
	���	  : ��� ID�� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��� ID ���ڿ�
*/
string MemberInfo::GetMemberId()
{
	return this->id;
}

/*
	�Լ� �̸� : MemberInfo::GetMemberPwd()
	���	  : ��� ��й�ȣ�� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��� ��й�ȣ ���ڿ�
*/
string MemberInfo::GetMemberPwd()
{
	return this->pwd;
}

/*
	�Լ� �̸� : MemberInfo::AddBiketoList()
	���	  : ���޹��� �����Ÿ� rentBikeList�� ������
	���� ���� : curBike -> ������ BikeInfo ��ü�� ����Ű�� ������
	��ȯ��    : ����
*/
void MemberInfo::AddBiketoList(BikeInfo* curBike)
{
	rentBikeList->AddBiketoList(curBike);		// rentBikeList�� curBike�� �����Ű��� ��û
}

/*
	�Լ� �̸� : MemberInfo::GetRentList()
	���	  : �ش� ����� �뿩�� ������ ������ �����ϰ� �ִ� rentBikeList�� ��ȯ��
	���� ���� : ����
	��ȯ��    : RentList* -> �뿩 ����Ʈ �����ϴ� RentList ������
*/
RentList* MemberInfo::GetRentList()
{
	return this->rentBikeList;
}
