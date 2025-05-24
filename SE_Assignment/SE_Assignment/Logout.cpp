//
// Logout 클래스와 LogoutUI 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "Logout.h"
#include "LoginMember.h"

/*
	함수 이름 : Logout::Logout()
	기능	  : Logout의 생성자로, 멤버변수를 초기화함
	전달 인자 : refLoginMem -> main에서 만든 LoginMember를 가리키는 포인터
	반환값    : 없음
*/
Logout::Logout(LoginMember* refLoginMem)
{
	refLoginMember = refLoginMem;
	refLogoutUI = nullptr;
}

/*
	함수 이름 : Logout::LogoutCurMem()
	기능	  : LoginMember에 저장된 로그인 정보를 로그아웃 처리함
	전달 인자 : 없음
	반환값    : 없음
*/
void Logout::LogoutCurMem()
{
	string memId = "";
	if (refLoginMember->IsAdminLogined() == true) {		// 현재 로그인한 멤버가 관리자라면
		memId = refLoginMember->SetAdminLogouted();		// 관리자 로그아웃 처리
	}
	else {												// 현재 로그인한 멤버가 일반 사용자라면
		memId = refLoginMember->SetLogouted();			// 멤버 로그아웃 처리
	}

	string output = "> " + memId;
	refLogoutUI->PrintMessage(output);					// 바운더리 클래스에게 출력시킴
}

/*
	함수 이름 : Logout::StartLogout()
	기능	  : 로그아웃 UseCase의 바운더리 클래스를 생성하고 시작함
	전달 인자 : out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
void Logout::StartLogout(ofstream* out_fp, ifstream* in_fp)
{
	refLogoutUI = new LogoutUI(this, out_fp, in_fp);	// 바운더리 클래스 생성
	refLogoutUI->StartLogoutUI();						// 입력 UI 출력
}




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
