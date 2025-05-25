//
// MemberInfo 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "MemberInfo.h"
#include "RentList.h"
#include "BikeDB.h"

/*
	함수 이름 : MemberInfo::MemberInfo()
	기능	  : MemberInfo의 생성자로, 전달받은 정보로 멤버변수를 초기화하고 RentList객체를 만들어 rentBikeList를 초기화함
	전달 인자 : id -> 멤버 ID, pwd -> 멤버 비밀번호, pn -> 멤버 전화번호
	반환값    : 없음
*/
MemberInfo::MemberInfo(string id, string pwd, string pn)
{
	this->id = id;
	this->pwd = pwd;
	this->pn = pn;

	rentBikeList = new RentList();
}

/*
	함수 이름 : MemberInfo::GetMemberId()
	기능	  : 멤버 ID를 반환함
	전달 인자 : 없음
	반환값    : string -> 멤버 ID 문자열
*/
string MemberInfo::GetMemberId()
{
	return this->id;
}

/*
	함수 이름 : MemberInfo::GetMemberPwd()
	기능	  : 멤버 비밀번호를 반환함
	전달 인자 : 없음
	반환값    : string -> 멤버 비밀번호 문자열
*/
string MemberInfo::GetMemberPwd()
{
	return this->pwd;
}

/*
	함수 이름 : MemberInfo::AddBiketoList()
	기능	  : 전달받은 자전거를 rentBikeList에 저장함
	전달 인자 : curBike -> 저장할 BikeInfo 객체를 가르키는 포인터
	반환값    : 없음
*/
void MemberInfo::AddBiketoList(BikeInfo* curBike)
{
	rentBikeList->AddBiketoList(curBike);		// rentBikeList에 curBike를 저장시키라고 요청
}

/*
	함수 이름 : MemberInfo::GetRentList()
	기능	  : 해당 멤버가 대여한 자전거 정보를 저장하고 있는 rentBikeList를 반환함
	전달 인자 : 없음
	반환값    : RentList* -> 대여 리스트 저장하는 RentList 포인터
*/
RentList* MemberInfo::GetRentList()
{
	return this->rentBikeList;
}
