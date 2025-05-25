//
// LogoutUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class Logout;

// ȸ������ UseCase�� ���� UI�� ����ϴ� LogoutUI Ŭ���� ����
class LogoutUI : public BaseUI
{
private:
	Logout* refLogout;		// ��ü�� ������ ��Ʈ�� Ŭ���� ������

public:
	LogoutUI(Logout* refControl, ofstream* out_fp, ifstream* in_fp);	// ��Ʈ�� Ŭ������ ���� ����¿� �����͸� ���޹޴� ������
	void StartLogoutUI();												// ���� ���߱�� �Լ�
	void PrintMessage(string info) override;							// ��� ���Ͽ� �����
};