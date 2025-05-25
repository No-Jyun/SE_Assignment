//
// LogoutUI 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "LogoutUI.h"
#include "Logout.h"

/*
	함수 이름 : LogoutUI::LogoutUI()
	기능	  : LogoutUI의 생성자로, 멤버변수를 초기화함
	전달 인자 : refControl -> 컨트롤 클래스 포인터, out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
LogoutUI::LogoutUI(Logout* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refLogout = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	함수 이름 : LogoutUI::StartLogoutUI()
	기능	  : 형식 맞추기용 함수로, 컨트롤 클래스에게 로그아웃 처리 요청
	전달 인자 : 없음
	반환값    : 없음
*/
void LogoutUI::StartLogoutUI()
{
	refLogout->LogoutCurMem();
}

/*
	함수 이름 : LogoutUI::PrintMessage()
	기능	  : 전달받은 문자열을 출력파일에 출력함
	전달 인자 : info -> 출력할 문자열
	반환값    : 없음
*/
void LogoutUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "2.2. 로그아웃" << endl;
	*out_fp << info << endl;
}
