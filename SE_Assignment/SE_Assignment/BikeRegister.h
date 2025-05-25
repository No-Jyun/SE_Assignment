//
// BikeRegister Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class BikeRegisterUI;
class BikeDB;

// ������ ��� UseCase�� ��Ʈ���ϴ� BikeRegister Ŭ���� ����
class BikeRegister 
{
private:
	BikeDB* refBikeDB;						// ������ ������ ������ BikeDB ������
	BikeRegisterUI* refBikeRegisterUI;		// ������ ��� UseCase�� �ٿ���� Ŭ������ BikeRegisterUI ������ 

public:
	BikeRegister(BikeDB* refDB);								// BikeDB�� ���޹޴� ������
	void RegisterBike(string id, string name);					// ���޹��� ������ ������ �����
	void StartBikeRegister(ofstream* out_fp, ifstream* in_fp);	// ������ ��� UseCase ������
};
