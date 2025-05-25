//
// LoginUI 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "LoginUI.h"
#include "Login.h"

/*
	함수 이름 : LoginUI::LoginUI()
	기능	  : LoginUI의 생성자로, 멤버변수를 초기화함
	전달 인자 : refControl -> 컨트롤 클래스 포인터, out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
LoginUI::LoginUI(Login* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refLogin = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	함수 이름 : LoginUI::InputMemberInfo()
	기능	  : 입력받은 정보를 컨트롤 클래스에게 넘김
	전달 인자 : id -> 멤버 ID, pwd -> 멤버 비밀번호
	반환값    : 없음
*/
void LoginUI::InputMemberInfo(string id, string pwd)
{
	refLogin->LoginThisMember(id, pwd);
}

/*
	함수 이름 : LoginUI::HandleInputUI()
	기능	  : UI를 시작하여 파일로부터 입력을 읽음
	전달 인자 : 없음
	반환값    : 없음
*/
void LoginUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id, pwd;
	*in_fp >> id >> pwd;		// 로그인하려는 멤버의 ID, 비밀번호를 입력받음

	InputMemberInfo(id, pwd);	// 입력 처리하는 함수 호출
}

/*
	함수 이름 : LoginUI::PrintMessage()
	기능	  : 전달받은 문자열을 출력파일에 출력함
	전달 인자 : info -> 출력할 문자열
	반환값    : 없음
*/
void LoginUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "2.1. 로그인" << endl;
	*out_fp << info << endl;
}
