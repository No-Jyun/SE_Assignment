//
// ProgramExit Ŭ���� ���� ���� �ҽ� ����
// Copyright Reserved
//

#include "ProgramExit.h"
#include "ProgramExitUI.h"

/*
	�Լ� �̸� : ProgramExit::ProgramExit()
	���	  : ProgramExit�� �����ڷ�, ��������� �ʱ�ȭ��
	���� ���� : ����
	��ȯ��    : ����
*/
ProgramExit::ProgramExit()
{
	refProgramExitUI = nullptr;
}

/*
	�Լ� �̸� : ProgramExit::StartProgramExit()
	���	  : �ý��� ������ �ٿ���� Ŭ������ �����ϰ� ����Ѵ�
	���� ���� : out_fp -> ��� ���� ������, in_fp -> �Է� ���� ������
	��ȯ��    : ����
*/
void ProgramExit::StartProgramExit(ofstream* out_fp, ifstream* in_fp)
{
	refProgramExitUI = new ProgramExitUI(this, out_fp, in_fp);	// �ٿ���� Ŭ���� ����
	refProgramExitUI->PrintMessage("6.1. ����");				// �ٿ���� Ŭ�������� �ý��� ���� �޽��� ���
}
