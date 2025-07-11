//
// UserRegisterUI 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "UserRegisterUI.h"
#include "UserRegister.h"

/*
	함수 이름 : UserRegisterUI::UserRegisterUI()
	기능	  : UserRegisterUI의 생성자로, 멤버변수를 초기화함
	전달 인자 : refControl -> 컨트롤 클래스 포인터, out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
UserRegisterUI::UserRegisterUI(UserRegister* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refUserRegister = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	함수 이름 : UserRegisterUI::HandleInputUI()
	기능	  : UI를 시작하여 파일로부터 입력을 읽음
	전달 인자 : 없음
	반환값    : 없음
*/
void UserRegisterUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id, pwd, pn;
	*in_fp >> id >> pwd >> pn;		// 가입자의 ID, 비밀번호, 전화번호를 입력받음

	InputUserInfo(id, pwd, pn);		// 입력 처리하는 함수 호출
}

/*
	함수 이름 : UserRegisterUI::PrintMessage()
	기능	  : 전달받은 문자열을 출력파일에 출력함
	전달 인자 : info -> 출력할 문자열
	반환값    : 없음
*/
void UserRegisterUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "1.1. 회원가입" << endl;
	*out_fp << info << endl;
}

/*
	함수 이름 : UserRegisterUI::InputUserInfo()
	기능	  : 입력받은 정보를 컨트롤 클래스에게 넘김
	전달 인자 : id -> 가입자 ID, pwd -> 가입자 비밀번호, pn -> 가입자 전화번호
	반환값    : 없음
*/
void UserRegisterUI::InputUserInfo(string id, string pwd, string pn)
{
	refUserRegister->RegisterUser(id, pwd, pn);		// 컨트롤 클래스에게 정보를 넘겨, 회원가입 처리
}
