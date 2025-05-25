//
// BikeInfo Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "BikeInfo.h"

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
