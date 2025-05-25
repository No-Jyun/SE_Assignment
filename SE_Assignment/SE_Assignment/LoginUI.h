//
// LoginUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class Login;

// �α��� UseCase�� ���� UI�� ����ϴ� LoginUI Ŭ���� ����
class LoginUI : public BaseUI
{
private:
	Login* refLogin;		// ��ü�� ������ ��Ʈ�� Ŭ���� ������

public:
	LoginUI(Login* refControl, ofstream* out_fp, ifstream* in_fp);	// ��Ʈ�� Ŭ������ ���� ����¿� �����͸� ���޹޴� ������
	void InputMemberInfo(string id, string pwd);					// �Է¹��� ������ ��Ʈ�� Ŭ������ �ѱ�
	void HandleInputUI();											// �Է� ���Ͽ��� �Է��� ����
	void PrintMessage(string info) override;						// ��� ���Ͽ� �����
};