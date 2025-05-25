//
// UserRegisterUI 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class UserRegister;

#pragma once

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