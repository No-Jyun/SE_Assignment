//
// ListRentBikeUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "ListRentBikeUI.h"
#include "ListRentBike.h"

/*
	�Լ� �̸� : ListRentBikeUI::ListRentBikeUI()
	���	  : ListRentBikeUI�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refControl -> ��Ʈ�� Ŭ���� ������, out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
ListRentBikeUI::ListRentBikeUI(ListRentBike* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refListRentBike = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
	isFirstPrint = true;
}

/*
	�Լ� �̸� : ListRentBikeUI::PrintMessage()
	���	  : ���޹��� ���ڿ��� ������Ͽ� �����
	���� ���� : info -> ����� ���ڿ�
	��ȯ��    : ����
*/
void ListRentBikeUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	if (isFirstPrint == true) {		// ù ��¿��� �޴� ���
		*out_fp << "5.1. ������ �뿩 ����Ʈ" << endl;
		isFirstPrint = false;
	}

	*out_fp << info << endl;
}

/*
	�Լ� �̸� : ListRentBikeUI::StartListRentBikeUI()
	���	  : ���� ���߱�� �Լ���, ��Ʈ�� Ŭ�������� ������ �뿩 ���� ��ȸ ó�� ��û
	���� ���� : ����
	��ȯ��    : ����
*/
void ListRentBikeUI::StartListRentBikeUI()
{
	refListRentBike->ListUpRentedBike();
}
