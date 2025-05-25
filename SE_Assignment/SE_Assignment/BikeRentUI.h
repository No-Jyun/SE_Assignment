//
// BikeRentUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class BikeRent;

// ������ �뿩 UseCase�� ���� UI�� ����ϴ� BikeRentUI Ŭ���� ����
class BikeRentUI : public BaseUI
{
private:
	BikeRent* refBikeRent;		// ��ü�� ������ ��Ʈ�� Ŭ���� ������

public:
	BikeRentUI(BikeRent* refControl, ofstream* out_fp, ifstream* in_fp);	// ��Ʈ�� Ŭ������ ���� ����¿� �����͸� ���޹޴� ������
	void InputBikeInfo(string id);											// �Է¹��� ������ ��Ʈ�� Ŭ������ �ѱ�
	void HandleInputUI();													// �Է� ���Ͽ��� �Է��� ����
	void PrintMessage(string info) override;								// ��� ���Ͽ� �����
};