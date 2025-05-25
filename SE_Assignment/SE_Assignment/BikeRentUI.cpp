//
// BikeRentUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "BikeRentUI.h"
#include "BikeRent.h"

/*
	�Լ� �̸� : BikeRentUI::BikeRentUI()
	���	  : BikeRentUI�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refControl -> ��Ʈ�� Ŭ���� ������, out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
BikeRentUI::BikeRentUI(BikeRent* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refBikeRent = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	�Լ� �̸� : BikeRentUI::InputBikeInfo()
	���	  : �Է¹��� ������ ��Ʈ�� Ŭ�������� �ѱ�
	���� ���� : id -> �Է¹��� ������ ID
	��ȯ��    : ����
*/
void BikeRentUI::InputBikeInfo(string id)
{
	refBikeRent->RentBike(id);
}

/*
	�Լ� �̸� : BikeRentUI::HandleInputUI()
	���	  : UI�� �����Ͽ� ���Ϸκ��� �Է��� ����
	���� ���� : ����
	��ȯ��    : ����
*/
void BikeRentUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id;
	*in_fp >> id;			// ���� �������� ID�� �Է¹���

	InputBikeInfo(id);		// �Է� ó���ϴ� �Լ� ȣ��
}

/*
	�Լ� �̸� : BikeRentUI::PrintMessage()
	���	  : ���޹��� ���ڿ��� ������Ͽ� �����
	���� ���� : info -> ����� ���ڿ�
	��ȯ��    : ����
*/
void BikeRentUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "4.1. ������ �뿩" << endl;
	*out_fp << info << endl;
}
