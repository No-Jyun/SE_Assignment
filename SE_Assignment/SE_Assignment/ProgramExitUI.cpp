//
// ProgramExitUI Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "ProgramExitUI.h"

/*
	�Լ� �̸� : ProgramExitUI::ProgramExitUI()
	���	  : ProgramExitUI�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : refControl -> ��Ʈ�� Ŭ���� ������, out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
ProgramExitUI::ProgramExitUI(ProgramExit* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refProgramExit = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	�Լ� �̸� : ProgramExitUI::PrintMessage()
	���	  : ���޹��� ���ڿ��� ������Ͽ� �����
	���� ���� : info -> ����� ���ڿ�
	��ȯ��    : ����
*/
void ProgramExitUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << info;
}
