//
// LogoutUI 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class Logout;

// 회원가입 UseCase에 대한 UI를 담당하는 LogoutUI 클래스 정의
class LogoutUI : public BaseUI
{
private:
	Logout* refLogout;		// 객체를 생성한 컨트롤 클래스 포인터

public:
	LogoutUI(Logout* refControl, ofstream* out_fp, ifstream* in_fp);	// 컨트롤 클래스와 파일 입출력용 포인터를 전달받는 생성자
	void StartLogoutUI();												// 형식 맞추기용 함수
	void PrintMessage(string info) override;							// 출력 파일에 출력함
};