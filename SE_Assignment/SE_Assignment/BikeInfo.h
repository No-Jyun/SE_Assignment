//
// BikeInfo Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

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
