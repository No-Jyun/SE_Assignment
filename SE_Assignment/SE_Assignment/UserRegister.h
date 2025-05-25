//
// UserRegister 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class UserDB;
class UserRegisterUI;

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
