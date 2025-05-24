//
// BikeDB Ŭ������ BikeInfo Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "BikeDB.h"

/*
	�Լ� �̸� : BikeDB::BikeDB()
	���	  : BikeDB ����Ʈ �����ڷ� bikeList ������ �迭�� �ʱ�ȭ��
	���� ���� : ����
	��ȯ��    : ����
*/
BikeDB::BikeDB()
{
	for (int i = 0; i < 50; i++) {
		bikeList[i] = nullptr;
	}
}

/*
	�Լ� �̸� : BikeDB::RegisterBike()
	���	  : ���޹��� ������ ���ο� �����Ÿ� ����� bikeList�� ������
	���� ���� : id -> ����� ������ ID, name -> ����� ������ ��й�ȣ
	��ȯ��    : ����
	*/
void BikeDB::RegisterBike(string id, string name)
{
	// ���ο� BikeInfo ��ü�� �����ϰ� bikeList�� numList ��ġ�� �����͸� �����ϰ� numList�� ������Ŵ
	bikeList[numList++] = new BikeInfo(id, name);	
}

/*
	�Լ� �̸� : BikeDB::GetBike()
	���	  : ���޹��� id�� ��ġ�ϴ� �����Ÿ� ��ȯ��
	���� ���� : id -> ã�� �������� ID
	��ȯ��    : BikeInfo* -> ��ġ�ϴ� BikeInfo ��ü�� ����Ű�� ������
*/
BikeInfo* BikeDB::GetBike(string id)
{
	for (int i = 0; i < numList; i++) {				// ����� ��� BikeInfo�� ���캽
		string curId = bikeList[i]->GetBikeId();	// ������ ID�� ������

		if (id == curId) {							// ���޹��� ID�� ���ٸ�
			return bikeList[i];						// �ش� �����Ÿ� ����Ű�� ������ ��ȯ
		}
	}
	return nullptr;
}




/*
	�Լ� �̸� : BikeInfo::BikeInfo()
	���	  : BikeInfo�� �����ڷ�, ���޹��� ������ ��������� �ʱ�ȭ��
	���� ���� : id -> ������ ID, name -> ������ ��ǰ��
	��ȯ��    : ����
*/
BikeInfo::BikeInfo(string id, string name)
{
	this->id = id;
	this->name = name;
}

/* 
	�Լ� �̸� : BikeInfo::GetBikeId()
	���	  : ������ ID�� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ������ ID ���ڿ�
*/
string BikeInfo::GetBikeId()
{
	return this->id;
}

/*
	�Լ� �̸� : BikeInfo::GetBikeName()
	���	  : ������ ��ǰ���� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ������ ��ǰ�� ���ڿ�
*/
string BikeInfo::GetBikeName()
{
	return this->name;
}
