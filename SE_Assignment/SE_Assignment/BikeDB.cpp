//
// BikeDB Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "BikeDB.h"
#include "BikeInfo.h"

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
