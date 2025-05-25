//
// BikeRegister Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "BikeRegister.h"
#include "BikeRegisterUI.h"
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
