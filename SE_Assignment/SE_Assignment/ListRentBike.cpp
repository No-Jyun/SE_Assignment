//
// ListRentBike Ŭ������ ListRentBikeUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include <vector>

#include "ListRentBike.h"
#include "LoginMember.h"
#include "UserDB.h"
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




/*
	�Լ� �̸� : ListRentBikeUI::ListRentBikeUI()
	���	  : ListRentBikeUI�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refControl -> ��Ʈ�� Ŭ���� ������, out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
ListRentBikeUI::ListRentBikeUI(ListRentBike* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refListRentBike = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
	isFirstPrint = true;
}

/*
	�Լ� �̸� : ListRentBikeUI::PrintMessage()
	���	  : ���޹��� ���ڿ��� ������Ͽ� �����
	���� ���� : info -> ����� ���ڿ�
	��ȯ��    : ����
*/
void ListRentBikeUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	if (isFirstPrint == true) {		// ù ��¿��� �޴� ���
		*out_fp << "5.1. ������ �뿩 ����Ʈ" << endl;
		isFirstPrint = false;
	}

	*out_fp << info << endl;
}

/*
	�Լ� �̸� : ListRentBikeUI::StartListRentBikeUI()
	���	  : ���� ���߱�� �Լ���, ��Ʈ�� Ŭ�������� ������ �뿩 ���� ��ȸ ó�� ��û
	���� ���� : ����
	��ȯ��    : ����
*/
void ListRentBikeUI::StartListRentBikeUI()
{
	refListRentBike->ListUpRentedBike();
}
