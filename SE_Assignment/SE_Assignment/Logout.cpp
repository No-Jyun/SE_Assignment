//
// Logout 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "Logout.h"
#include "LogoutUI.h"
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
