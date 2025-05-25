//
// ProgramExit 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "ProgramExit.h"
#include "ProgramExitUI.h"

/*
	함수 이름 : ProgramExit::ProgramExit()
	기능	  : ProgramExit의 생성자로, 멤버변수를 초기화함
	전달 인자 : 없음
	반환값    : 없음
*/
ProgramExit::ProgramExit()
{
	refProgramExitUI = nullptr;
}

/*
	함수 이름 : ProgramExit::StartProgramExit()
	기능	  : 시스템 종료의 바운더리 클래스를 생성하고 출력한다
	전달 인자 : out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
void ProgramExit::StartProgramExit(ofstream* out_fp, ifstream* in_fp)
{
	refProgramExitUI = new ProgramExitUI(this, out_fp, in_fp);	// 바운더리 클래스 생성
	refProgramExitUI->PrintMessage("6.1. 종료");				// 바운더리 클래스에게 시스템 종료 메시지 출력
}
