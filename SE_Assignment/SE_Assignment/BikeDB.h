//
// BikeDB Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class BikeInfo;

// ����� ������ �����ϱ� ���� BikeDB Ŭ���� ����
class BikeDB 
{
private:
	BikeInfo* bikeList[50];		// ����� ������ �����ϱ� ���� BikeInfo �������� �迭
	int numList = 0;			// bikeList �迭 ������ġ �� ���� ������

public:
	BikeDB();										// ����Ʈ ������
	void RegisterBike(string id, string name);		// ���޹��� id, name���� ���ο� �����Ÿ� ����� ������
	BikeInfo* GetBike(string id);					// ���޹��� id�� ���� �����Ÿ� ��ȯ��
};
