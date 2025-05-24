//
// RentList Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include <algorithm>

#include "RentList.h"
#include "BikeDB.h"

/*
	�Լ� �̸� : RentList::RentList()
	���	  : RentList�� ����Ʈ �����ڷ�, memRentList ������ �迭�� �ʱ�ȭ��
	���� ���� : ����
	��ȯ��    : ����
*/
RentList::RentList()
{
	for (int i = 0; i < 50; i++) {
		memRentList[i] = nullptr;
	}
}

/*
	�Լ� �̸� : RentList::AddBiketoList()
	���	  : ���޹��� �����Ÿ� memRentList�� ������
	���� ���� : curBike -> ������ BikeInfo ��ü�� ����Ű�� ������
	��ȯ��    : ����
*/
void RentList::AddBiketoList(BikeInfo* curBike)
{
	memRentList[numList++] = curBike;	// memRentList�� numList ��ġ�� curBike�� �����ϰ� numList�� ������Ŵ
}

/*
	�Լ� �̸� : RentList::GetSortedRentBikeInfos()
	���	  : memRentList�� ����� BikeInfo ��ü���� id�� name�� ������, ���Ϳ� ������ �� id�� �������� �����Ͽ� ��ȯ��
	���� ���� : ����
	��ȯ��    : vector<pair<string, string>> -> �������� ID�� ��ǰ���� ��� �ִ� ����
*/
vector<pair<string, string>> RentList::GetSortedRentBikeInfos()
{
	vector<pair<string, string>> result;		// ���Ͽ� ���� ����

	for (int i = 0; i < numList; i++) {			// ����� ��� BikeInfo�� ���캽
		string id, name;
		id = memRentList[i]->GetBikeId();		// ���� �������� ID ��������
		name = memRentList[i]->GetBikeName();	// ���� �������� ��ǰ�� ��������
		result.push_back({ id,name });			// { ID, ��ǰ�� } �� ���Ϳ� �ֱ�
	}
	sort(result.begin(), result.end());			// ������ ID�� �տ� �����Ƿ� ������ ID�� 1������ ����

	return result;								// ���� ��ȯ
}
