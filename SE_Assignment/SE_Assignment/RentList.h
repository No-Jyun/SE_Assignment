//
// RentList Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <vector>
#include <string>

using namespace std;

class BikeInfo;

// ���� ������ �����ϱ� ���� RentList Ŭ���� ����
class RentList {
private:
	BikeInfo* memRentList[50];		// ���� ������ �����ϱ� ���� BikeInfo �������� �迭
	int numList = 0;				// memRentList �迭 ������ġ �� ���� ������

public:
	RentList();												// ����Ʈ ������
	void AddBiketoList(BikeInfo* curBike);					// ���޹��� �����Ÿ� memRentList�� ������
	vector<pair<string, string>> GetSortedRentBikeInfos();	// ���� �������� ������ ID�� �������� �����Ͽ� ��ȯ��
};