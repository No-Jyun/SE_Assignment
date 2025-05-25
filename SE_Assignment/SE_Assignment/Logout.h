//
// Logout 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class LogoutUI;
class LoginMember;

// 로그아웃 UseCase를 컨트롤하는 Logout 클래스 정의
class Logout 
{
private:
	LogoutUI* refLogoutUI;			// 로그아웃 UseCase의 바운더리 클래스인 LogoutUI 포인터
	LoginMember* refLoginMember;	// 로그인 정보를 가지는 LoginMember 포인터

public:
	Logout(LoginMember* refLoginMem);						// LoginMember를 전달받는 생성자
	void LogoutCurMem();									// 현재 로그인한 멤버 로그아웃 처리
	void StartLogout(ofstream* out_fp, ifstream* in_fp);	// 로그아웃 UseCase 시작함
};
