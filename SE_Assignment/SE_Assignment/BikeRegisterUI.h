//
// BikeRegisterUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class BikeRegister;

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