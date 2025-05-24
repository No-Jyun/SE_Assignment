//
// BikeRegister Ŭ������ BikeRegisterUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "BikeRegister.h"
#include "BikeDB.h"

/*
	�Լ� �̸� : BikeRegister::BikeRegister()
	���	  : BikeRegister�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refDB -> main���� ���� BikeDB�� ����Ű�� ������
	��ȯ��    : ����
*/
BikeRegister::BikeRegister(BikeDB* refDB)
{
	refBikeDB = refDB;
	refBikeRegisterUI = nullptr;
}

/*
	�Լ� �̸� : BikeRegister::RegisterBike()
	���	  : ���޹��� ������ BikeDB�� ������ ����� ��û�ϰ� UI�� ��½�Ŵ
	���� ���� : id -> ������ ID, name -> ������ ��ǰ��
	��ȯ��    : ����
*/
void BikeRegister::RegisterBike(string id, string name)
{
	refBikeDB->RegisterBike(id, name);			// BikeDB�� ������ ������ �Ѱ� ��Ͻ�Ŵ

	string output = "> " + id + " " + name;
	refBikeRegisterUI->PrintMessage(output);	// �ٿ���� Ŭ�������� ��½�Ŵ
}

/*
	�Լ� �̸� : BikeRegister::StartBikeRegister()
	���	  : ������ ��� UseCase�� �ٿ���� Ŭ������ �����ϰ� ������
	���� ���� : out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
void BikeRegister::StartBikeRegister(ofstream* out_fp, ifstream* in_fp)
{
	refBikeRegisterUI = new BikeRegisterUI(this, out_fp, in_fp);	// �ٿ���� Ŭ���� ����
	refBikeRegisterUI->HandleInputUI();								// �Է� UI ���
}




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
