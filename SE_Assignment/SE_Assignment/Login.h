//
// Login 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class LoginUI;
class UserDB;
class LoginMember;

// 로그인 UseCase를 컨트롤하는 Login 클래스 정의
class Login 
{
private:
	LoginUI* refLoginUI;			// 로그인 UseCase의 바운더리 클래스인 LoginUI 포인터 
	UserDB* refUserDB;				// 멤버 정보를 가지는 UserDB 포인터
	LoginMember* refLoginMember;	// 로그인 정보를 가지는 LoginMember 포인터

public:
	Login(UserDB* refDB, LoginMember* refLoginMem);		// UserDB와 LoginMember를 전달받는 생성자
	void LoginThisMember(string id, string pwd);		// 전달받은 정보로 로그인함
	void StartLogin(ofstream* out_fp, ifstream* in_fp);	// 로그인 UseCase 시작함
};
