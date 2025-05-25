//
// LoginMember 클래스 구현을 위한 소스 파일
// Copyright Reserved
//

#include "LoginMember.h"
#include "MemberInfo.h"

/*
	함수 이름 : LoginMember::LoginMember()
	기능	  : LoginMember의 디폴트 생성자로 포인터를 초기화함
	전달 인자 : 없음
	반환값    : 없음
*/
LoginMember::LoginMember()
{
	curLoginMember = nullptr;
}

/*
	함수 이름 : LoginMember::SetAdminLogined()
	기능	  : 관리자 로그인 처리를 위해 isAdmin 변수를 true로 바꿈
	전달 인자 : 없음
	반환값    : 없음
*/
void LoginMember::SetAdminLogined()
{
	isAdmin = true;		// 관리자가 로그인 하였으므로 true로 바꿈
}

/*
	함수 이름 : LoginMember::SetAdminLogouted()
	기능	  : 관리자 로그아웃 처리를 위해 isAdmin 변수를 false로 바꿈
	전달 인자 : 없음
	반환값    : string -> 출력용 관리자 Id 반환
*/
string LoginMember::SetAdminLogouted()
{
	isAdmin = false;		// 관리자가 로그아웃 하였으므로 false로 바꿈
	return "admin";			// 관리자 ID 반환
}

/*
	함수 이름 : LoginMember::IsAdminLogined()
	기능	  : 현재 관리자의 로그인 상태를 알려주는 isAdmin 변수를 반환해줌
	전달 인자 : 없음
	반환값    : bool -> true = 관리자 로그인 O, false = 관리자 로그인 X
*/
bool LoginMember::IsAdminLogined()
{
	return this->isAdmin;
}

/*
	함수 이름 : LoginMember::SetLogined()
	기능	  : 전달받은 멤버 포인터를 curLoginMember에 저장시킴
	전달 인자 : loginedMem -> 로그인시킬 멤버 포인터
	반환값    : 없음
*/
void LoginMember::SetLogined(MemberInfo* loginedMem)
{
	curLoginMember = loginedMem;
}

/*
	함수 이름 : LoginMember::SetLogouted()
	기능	  : 멤버 로그아웃 처리를 위해 curLoginMember를 null값으로 초기화함
	전달 인자 : 없음
	반환값    : string -> 출력용 멤버 ID 반환
*/
string LoginMember::SetLogouted()
{
	string memId = curLoginMember->GetMemberId();	// 로그아웃 전 출력용 멤버 ID 가져오기
	curLoginMember = nullptr;
	return memId;
}

/*
	함수 이름 : LoginMember::GetLoginMember()
	기능	  : 현재 로그인한 멤버를 전달하기 위해 curLoginMember를 반환해줌
	전달 인자 : 없음
	반환값    : MemberInfo* -> 현재 로그인한 멤버를 가르키는 포인터
*/
MemberInfo* LoginMember::GetLoginMember()
{
	return this->curLoginMember;
}
