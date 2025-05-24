//
// LoginMember 클래스 정의를 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class MemberInfo;

// 로그인 정보를 저장하기 위한 LoginMember 클래스 정의
class LoginMember 
{
private:
	MemberInfo* curLoginMember;		// 현재 로그인한 멤버 저장용 포인터
	bool isAdmin = false;			// 관리자 로그인용

public:
	LoginMember();								// 디폴트 생성자
	void SetAdminLogined();						// 관리자 로그인 처리함
	string SetAdminLogouted();					// 관리자 로그아웃 처리함
	bool IsAdminLogined();						// 현재 로그인한 멤버가 관리자인지 알려줌
	void SetLogined(MemberInfo* loginedMem);	// 전달받은 멤버로 로그인 처리함
	string SetLogouted();						// 현재 로그인한 멤버 로그아웃 처리함
	MemberInfo* GetLoginMember();				// 현재 로그인한 멤버 반환함
};