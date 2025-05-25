//
// BikeRent Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class LoginMember;
class BikeDB;
class BikeRentUI;
class MemberInfo;
class BikeInfo;

// ������ �뿩 UseCase�� ��Ʈ���ϴ� BikeRent Ŭ���� ����
class BikeRent 
{
private:
	LoginMember* refLoginMember;	// �α��� ������ ������ LoginMember ������
	BikeDB* refBikeDB;				// ������ ������ ������ BikeDB ������
	BikeRentUI* refBikeRentUI;		// ������ �뿩 UseCase�� �ٿ���� Ŭ������ BikeRentUI ������
	MemberInfo* curMember;			// ���� �α����� ����� ����Ű�� MemberInfo ������
	BikeInfo* curBike;				// �뿩�� �����Ÿ� ����Ű�� BikeInfo ������

public:
	BikeRent(LoginMember* refLoginMem, BikeDB* refDB);		// LoginMember�� BikeDB�� ���޹޴� ������
	void RentBike(string id);								// ���޹��� ������ �����Ÿ� ã��, ���� �α����� ����� �뿩 ����Ʈ�� �߰���
	void StartBikeRent(ofstream* out_fp, ifstream* in_fp);	// ������ �뿩 UseCase ������
};
