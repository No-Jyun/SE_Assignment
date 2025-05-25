//
// BikeRegisterUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "BikeRegisterUI.h"
#include "BikeRegister.h"

/*
	�Լ� �̸� : BikeRegisterUI::BikeRegisterUI()
	���	  : BikeRegisterUI�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refControl -> ��Ʈ�� Ŭ���� ������, out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
BikeRegisterUI::BikeRegisterUI(BikeRegister* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refBIkeRegister = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	�Լ� �̸� : BikeRegisterUI::InputBikeInfo()
	���	  : �Է¹��� ������ ��Ʈ�� Ŭ�������� �ѱ�
	���� ���� : id -> ������ ID, name -> ������ ��ǰ��
	��ȯ��    : ����
*/
void BikeRegisterUI::InputBikeInfo(string id, string name)
{
	refBIkeRegister->RegisterBike(id, name);		// ��Ʈ�� Ŭ�������� ������ �Ѱ�, ������ ��� ó��
}

/*
	�Լ� �̸� : BikeRegisterUI::HandleInputUI()
	���	  : UI�� �����Ͽ� ���Ϸκ��� �Է��� ����
	���� ���� : ����
	��ȯ��    : ����
*/
void BikeRegisterUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id, name;
	*in_fp >> id >> name;		// ����Ϸ��� �������� ID, ��ǰ���� �Է¹���

	InputBikeInfo(id, name);	// �Է� ó���ϴ� �Լ� ȣ��
}

/*
	�Լ� �̸� : BikeRegisterUI::PrintMessage()
	���	  : ���޹��� ���ڿ��� ������Ͽ� �����
	���� ���� : info -> ����� ���ڿ�
	��ȯ��    : ����
*/
void BikeRegisterUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "3.1. ������ ���" << endl;
	*out_fp << info << endl;
}
