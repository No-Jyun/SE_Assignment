//
// ProgramExit Ŭ���� ���� ���� ��� ����
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class ProgramExitUI;

// �ý��� ���Ḧ ��Ʈ���ϴ� ProgramExit Ŭ���� ����
class ProgramExit 
{
private:
	ProgramExitUI* refProgramExitUI;		// �ý��� ������ �ٿ���� Ŭ������ ProgramExitUI ������

public:
	ProgramExit();												// ����Ʈ ������
	void StartProgramExit(ofstream* out_fp, ifstream* in_fp);	// �ý��� ���� ����
};
