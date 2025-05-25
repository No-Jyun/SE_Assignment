//
// ProgramExitUI Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class ProgramExit;

// �ý��� ���ῡ ���� UI�� ����ϴ� ProgramExitUI Ŭ���� ����
class ProgramExitUI : public BaseUI
{
private:
	ProgramExit* refProgramExit;		// ��ü�� ������ ��Ʈ�� Ŭ���� ������

public:
	ProgramExitUI(ProgramExit* refControl, ofstream* out_fp, ifstream* in_fp);	// ��Ʈ�� Ŭ������ ���� ����¿� �����͸� ���޹޴� ������
	void PrintMessage(string info) override;									// ��� ���Ͽ� �����
};