//
// Login 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "Login.h"
#include "LoginUI.h"
#include "LoginMember.h"
#include "UserDB.h"

/*
	함수 이름 : Login::Login()
	기능	  : Login의 생성자로, 멤버변수를 초기화함
	전달 인자 : refDB -> main에서 만든 UserDB를 가리키는 포인터, refLoginMem -> main에서 만든 LoginMember를 가리키는 포인터
	반환값    : 없음
*/
Login::Login(UserDB* refDB, LoginMember* refLoginMem)
{
	refUserDB = refDB;
	refLoginMember = refLoginMem;
	refLoginUI = nullptr;
}

/*
	함수 이름 : Login::LoginThisMember()
	기능	  : 전달받은 정보로 알맞은 멤버를 찾고, 해당 멤버를 LoginMember에 저장시킴
	전달 인자 : id -> 멤버 ID, pwd -> 멤버 비밀번호
	반환값    : 없음
*/
void Login::LoginThisMember(string id, string pwd)
{
	if (refUserDB->IsAdmin(id, pwd) == true) {		// 현재 로그인하는 멤버가 관리자라면
		refLoginMember->SetAdminLogined();			// LoginMember에 관라자 로그인 처리
	}
	else {	// 현재 로그인하는 멤버가 일반 사용자라면
		MemberInfo* loginMem = refUserDB->GetThisMember(id, pwd);	// UserDB에서 알맞은 멤버 찾아옴
		refLoginMember->SetLogined(loginMem);						// 해당 멤버를 LoginMember에서 로그인 처리
	}

	string output = "> " + id + " " + pwd;
	refLoginUI->PrintMessage(output);				// 바운더리 클래스에게 출력시킴
}

/*
	함수 이름 : Login::StartLogin()
	기능	  : 로그인 UseCase의 바운더리 클래스를 생성하고 시작함
	전달 인자 : out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
void Login::StartLogin(ofstream* out_fp, ifstream* in_fp)
{
	refLoginUI = new LoginUI(this, out_fp, in_fp);	// 바운더리 클래스 생성
	refLoginUI->HandleInputUI();					// 입력 UI 출력
}
