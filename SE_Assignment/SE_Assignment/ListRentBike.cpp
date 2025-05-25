//
// ListRentBike Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include <vector>

#include "ListRentBike.h"
#include "ListRentBikeUI.h"
#include "LoginMember.h"
#include "MemberInfo.h"
#include "RentList.h"

/*
	�Լ� �̸� : ListRentBike::ListRentBike()
	���	  : ListRentBike�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refLoginMem -> main���� ���� LoginMember�� ����Ű�� ������
	��ȯ��    : ����
*/
ListRentBike::ListRentBike(LoginMember* refLoginMem)
{
	refLoginMember = refLoginMem;
	refListRentBikeUI = nullptr;
	curMember = nullptr;
	curRentList = nullptr;
}

/*
	�Լ� �̸� : ListRentBike::StartListRentBike()
	���	  : ������ �뿩 ���� ��ȸ UseCase�� �ٿ���� Ŭ������ �����ϰ� ������
	���� ���� : out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
void ListRentBike::StartListRentBike(ofstream* out_fp, ifstream* in_fp)
{
	refListRentBikeUI = new ListRentBikeUI(this, out_fp, in_fp);	// �ٿ���� Ŭ���� ����
	refListRentBikeUI->StartListRentBikeUI();						// �Է� UI ���
}

/*
	�Լ� �̸� : ListRentBike::ListUpRentedBike()
	���	  : LoginMember�� ����� �α��� ������ �α����� ����� �����ͼ� �ش� ����� ���� RentList�� ���� ������ ������ ����Ѵ�.
	���� ���� : ����
	��ȯ��    : ����
*/
void ListRentBike::ListUpRentedBike()
{
	curMember = refLoginMember->GetLoginMember();	// LoginMember�� ����� �α����� ����� curMember �ʱ�ȭ
	if (curMember == nullptr) return;

	curRentList = curMember->GetRentList();			// �ش� ����� ������ �ִ� RentList�� curRentList �ʱ�ȭ
	if (curRentList == nullptr) return;

	vector<pair<string, string>> printVec = curRentList->GetSortedRentBikeInfos();	// RentList�� ����� ������ ���� ��������
	for (int i = 0; i < printVec.size(); i++) {										// ���� ������ ���θ� �ݺ���
		string info = "> " + printVec[i].first + " " + printVec[i].second;
		refListRentBikeUI->PrintMessage(info);										// �ٿ���� Ŭ�������� ������ ���� ��½�Ŵ
	}
}
