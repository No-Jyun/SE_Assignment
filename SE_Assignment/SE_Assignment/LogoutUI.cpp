//
// LogoutUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "LogoutUI.h"
#include "Logout.h"

/*
	�Լ� �̸� : LogoutUI::LogoutUI()
	���	  : LogoutUI�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refControl -> ��Ʈ�� Ŭ���� ������, out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
LogoutUI::LogoutUI(Logout* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refLogout = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	�Լ� �̸� : LogoutUI::StartLogoutUI()
	���	  : ���� ���߱�� �Լ���, ��Ʈ�� Ŭ�������� �α׾ƿ� ó�� ��û
	���� ���� : ����
	��ȯ��    : ����
*/
void LogoutUI::StartLogoutUI()
{
	refLogout->LogoutCurMem();
}

/*
	�Լ� �̸� : LogoutUI::PrintMessage()
	���	  : ���޹��� ���ڿ��� ������Ͽ� �����
	���� ���� : info -> ����� ���ڿ�
	��ȯ��    : ����
*/
void LogoutUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "2.2. �α׾ƿ�" << endl;
	*out_fp << info << endl;
}
