//
// UserRegister 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "UserRegister.h"
#include "UserRegisterUI.h"
#include "UserDB.h"

/*
	함수 이름 : UserRegister::UserRegister()
	기능	  : UserRegister의 생성자로, 멤버변수를 초기화함
	전달 인자 : refDB -> main에서 만든 UserDB를 가리키는 포인터
	반환값    : 없음
*/
UserRegister::UserRegister(UserDB* refDB)
{
	refUserDB = refDB;
	refUserRegisterUI = nullptr;
}

/*
	함수 이름 : UserRegister::RegisterUser()
	기능	  : 전달받은 정보로 UserDB에 회원가입을 요청하고 UI를 출력시킴
	전달 인자 : id -> 가입자 ID, pwd -> 가입자 비밀번호, pn -> 가입자 전화번호
	반환값    : 없음
*/
void UserRegister::RegisterUser(string id, string pwd, string pn)
{
	refUserDB->RegisterUser(id, pwd, pn);				// UserDB에 가입자 정보를 넘겨 회원가입 시킴

	string output = "> " + id + " " + pwd + " " + pn;
	refUserRegisterUI->PrintMessage(output);			// 바운더리 클래스에게 출력시킴
}

/*
	함수 이름 : UserRegister::StartUserRegister()
	기능	  : 회원가입 UseCase의 바운더리 클래스를 생성하고 시작함
	전달 인자 : out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
void UserRegister::StartUserRegister(ofstream* out_fp, ifstream* in_fp)
{
	refUserRegisterUI = new UserRegisterUI(this, out_fp, in_fp);	// 바운더리 클래스 생성
	refUserRegisterUI->HandleInputUI();								// 입력 UI 출력
}
