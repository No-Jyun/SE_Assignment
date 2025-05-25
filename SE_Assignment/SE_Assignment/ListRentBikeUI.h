//
// ListRentBikeUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class ListRentBike;

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