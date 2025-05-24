//
// BikeDB Ŭ������ BikeInfo Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class BikeDB;
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

// ������ ������ �����ϱ� ���� BikeInfo Ŭ���� ����
class BikeInfo 
{
private:
	string id;			// ������ ID
	string name;		// ������ ��ǰ��

public:
	BikeInfo(string id, string name);		// ������ ������ ���޹޴� ������
	string GetBikeId();						// �������� ID�� ��ȯ��
	string GetBikeName();					// �������� ��ǰ���� ��ȯ��
};
