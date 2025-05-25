//
// ProgramExit 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class ProgramExitUI;

// 시스템 종료를 컨트롤하는 ProgramExit 클래스 정의
class ProgramExit 
{
private:
	ProgramExitUI* refProgramExitUI;		// 시스템 종료의 바운더리 클래스인 ProgramExitUI 포인터

public:
	ProgramExit();												// 디폴트 생성자
	void StartProgramExit(ofstream* out_fp, ifstream* in_fp);	// 시스템 종료 시작
};
