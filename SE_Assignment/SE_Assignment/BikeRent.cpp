//
// BikeRent Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "BikeRent.h"
#include "BikeRentUI.h"
#include "LoginMember.h"
#include "BikeDB.h"
#include "BikeInfo.h"
#include "MemberInfo.h"

/*
	�Լ� �̸� : BikeRent::BikeRent()
	���	  : BikeRent�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refLoginMem -> main���� ���� LoginMember�� ����Ű�� ������, refDB -> main���� ���� BikeDB�� ����Ű�� ������
	��ȯ��    : ����
*/
BikeRent::BikeRent(LoginMember* refLoginMem, BikeDB* refDB)
{
	refLoginMember = refLoginMem;
	refBikeDB = refDB;
	refBikeRentUI = nullptr;
	curMember = nullptr;
	curBike = nullptr;
}

/*
	�Լ� �̸� : BikeRent::RentBike()
	���	  : ���޹��� ������ �����Ÿ� ã��, �ش� �����Ÿ� ���� �α����� ����� �뿩 ����Ʈ�� �߰���
	���� ���� : id -> ������ ID
	��ȯ��    : ����
*/
void BikeRent::RentBike(string id)
{
	curMember = refLoginMember->GetLoginMember();	// LoginMember�� ����� �α����� ����� curMember �ʱ�ȭ
	if (curMember == nullptr) {
		return;
	}

	curBike = refBikeDB->GetBike(id);				// BikeDB���� ������ ID�� ��ġ�ϴ� �����ŷ� curBike �ʱ�ȭ
	if (curBike == nullptr) {
		return;
	}

	curMember->AddBiketoList(curBike);				// curMember�� ������ �뿩 ����Ʈ�� curBike �߰�

	string name = curBike->GetBikeName();
	string output = "> " + id + " " + name;
	refBikeRentUI->PrintMessage(output);			// �ٿ���� Ŭ�������� ��½�Ŵ
}

/*
	�Լ� �̸� : BikeRent::StartBikeRent()
	���	  : ������ �뿩 UseCase�� �ٿ���� Ŭ������ �����ϰ� ������
	���� ���� : out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
void BikeRent::StartBikeRent(ofstream* out_fp, ifstream* in_fp)
{
	refBikeRentUI = new BikeRentUI(this, out_fp, in_fp);	// �ٿ���� Ŭ���� ����
	refBikeRentUI->HandleInputUI();							// �Է� UI ���
}
