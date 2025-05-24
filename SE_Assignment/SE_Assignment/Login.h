//
// Login 클래스와 LoginUI 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class Login;
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

// 로그인 UseCase에 대한 UI를 담당하는 LoginUI 클래스 정의
class LoginUI : public BaseUI
{
private:
	Login* refLogin;		// 객체를 생성한 컨트롤 클래스 포인터

public:
	LoginUI(Login* refControl, ofstream* out_fp, ifstream* in_fp);	// 컨트롤 클래스와 파일 입출력용 포인터를 전달받는 생성자
	void InputMemberInfo(string id, string pwd);					// 입력받은 정보를 컨트롤 클래스로 넘김
	void HandleInputUI();											// 입력 파일에서 입력을 읽음
	void PrintMessage(string info) override;						// 출력 파일에 출력함
};