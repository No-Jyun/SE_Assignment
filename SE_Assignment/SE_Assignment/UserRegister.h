//
// UserRegister 클래스와 UserRegisterUI 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class UserRegister;
class UserRegisterUI;
class UserDB;

// 회원가입 UseCase를 컨트롤하는 UserRegister 클래스 정의
class UserRegister 
{
private:
	UserDB* refUserDB;					// 멤버 정보를 가지는 UserDB 포인터
	UserRegisterUI* refUserRegisterUI;	// 회원가입 UseCase의 바운더리 클래스인 UserRegisterUI 포인터

public:
	UserRegister(UserDB* refDB);								// UserDB를 전달받는 생성자
	void RegisterUser(string id, string pwd, string pn);		// 전달받은 정보로 회원가입함
	void StartUserRegister(ofstream* out_fp, ifstream* in_fp);	// 회원가입 UseCase 시작함
};

// 회원가입 UseCase에 대한 UI를 담당하는 UserRegisterUI 클래스 정의
class UserRegisterUI : public BaseUI 
{
private:
	UserRegister* refUserRegister;		// 객체를 생성한 컨트롤 클래스 포인터

public:
	UserRegisterUI(UserRegister* refControl, ofstream* out_fp, ifstream* in_fp);	// 컨트롤 클래스와 파일 입출력용 포인터를 전달받는 생성자
	void HandleInputUI();															// 입력 파일에서 입력을 읽음
	void PrintMessage(string info) override;										// 출력 파일에 출력함
	void InputUserInfo(string id, string pwd, string pn);							// 입력받은 정보를 컨트롤 클래스로 넘김
};