//
// BaseUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <fstream>
using namespace std;

// ��� �ٿ���� Ŭ������ ���� ������ �Լ��� ������ Super Ŭ������ BaseUI �߻� Ŭ���� ����
class BaseUI 
{
protected:
	ofstream* out_fp;		// ���� ��¿� ������
	ifstream* in_fp;		// ���� �Է¿� ������
	
public:
	virtual void PrintMessage(string info) = 0;		// ��� ���Ͽ� ����� ���� ���� ���� �Լ�
};