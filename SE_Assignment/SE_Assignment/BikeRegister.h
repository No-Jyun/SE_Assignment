//
// BikeRegister Ŭ������ BikeRegisterUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class BikeRegister;
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

// ������ ��� UseCase�� ���� UI�� ����ϴ� BikeRegisterUI Ŭ���� ����
class BikeRegisterUI : public BaseUI
{
private:
	BikeRegister* refBIkeRegister;			// ��ü�� ������ ��Ʈ�� Ŭ���� ������

public:
	BikeRegisterUI(BikeRegister* refControl, ofstream* out_fp, ifstream* in_fp);	// ��Ʈ�� Ŭ������ ���� ����¿� �����͸� ���޹޴� ������
	void InputBikeInfo(string id, string name);										// �Է¹��� ������ ��Ʈ�� Ŭ������ �ѱ�
	void HandleInputUI();															// �Է� ���Ͽ��� �Է��� ����
	void PrintMessage(string info) override;										// ��� ���Ͽ� �����
};