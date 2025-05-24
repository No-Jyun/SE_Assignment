//
// ListRentBike Ŭ������ ListRentBikeUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class ListRentBike;
class ListRentBikeUI;
class LoginMember;
class MemberInfo;
class RentList;

// ������ �뿩 ���� ��ȸ UseCase�� ��Ʈ���ϴ� ListRentBike Ŭ���� ����
class ListRentBike 
{
private:
	LoginMember* refLoginMember;			// �α��� ������ ������ LoginMember ������
	ListRentBikeUI* refListRentBikeUI;		// �α��� UseCase�� �ٿ���� Ŭ������ LoginUI ������
	MemberInfo* curMember;					// ���� �α����� ����� ����Ű�� MemberInfo ������
	RentList* curRentList;					// �뿩�� ������ ����� ����Ű�� RentList ������

public:
	ListRentBike(LoginMember* refLoginMem);							// LoginMember�� ���޹޴� ������
	void StartListRentBike(ofstream* out_fp, ifstream* in_fp);		// ������ �뿩 ���� ��ȸ UseCase ������
	void ListUpRentedBike();										// �α����� ������� ������ �뿩 ����Ʈ�� ������ �� �پ� ������ �����
};

// ������ �뿩 ���� ��ȸ UseCase�� ���� UI�� ����ϴ� ListRentBikeUI Ŭ���� ����
class ListRentBikeUI : public BaseUI
{
private:
	ListRentBike* refListRentBike;		// ��ü�� ������ ��Ʈ�� Ŭ���� ������
	bool isFirstPrint = true;			// ��� ���� ���߱� ���� boolen��

public:
	ListRentBikeUI(ListRentBike* refControl, ofstream* out_fp, ifstream* in_fp);	// ��Ʈ�� Ŭ������ ���� ����¿� �����͸� ���޹޴� ������
	void PrintMessage(string info) override;										// ��� ���Ͽ� �����
	void StartListRentBikeUI();														// ���� ���߱�� �Լ�
};