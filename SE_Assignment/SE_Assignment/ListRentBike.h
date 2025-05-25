//
// ListRentBike Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

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
