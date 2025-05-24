//
// UserDB 클래스와 MemberInfo 클래스 정의를 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class UserDB;
class MemberInfo;
class RentList;
class BikeInfo;

// 회원가입한 멤버를 저장하기 위한 UserDB 클래스 정의
class UserDB 
{
private:
	MemberInfo* memberList[50];		// 멤버 저장하기 위한 MemberInfo 포인터의 배열
	int numList = 0;				// memberList 배열 저장위치 및 길이 관리용
	string adminId = "admin";		// 관리자 ID
	string adminPwd = "admin";		// 관리자 비밀번호

public:
	UserDB();												// 디폴트 생성자
	void RegisterUser(string id, string pwd, string pn);	// 전달받은 id, pwd, pn으로 새로운 멤버를 만들고 저장함
	MemberInfo* GetThisMember(string id, string pwd);		// 전달받은 id, pwd를 갖는 멤버를 반환함
	bool IsAdmin(string id, string pwd);					// 전달받은 id, pwd가 관리자인지 확인함
};

// 멤버 정보를 저장하기 위한 MemberInfo 클래스 정의
class MemberInfo
{
private:
	string id;					// 멤버 ID
	string pwd;					// 멤버 비밀번호
	string pn;					// 멤버 전화번호
	RentList* rentBikeList;		// 멤버가 빌린 자전거 리스트 저장하는 RentList 포인터

public:
	MemberInfo(string id, string pwd, string pn);	// 멤버 정보를 전달받는 생성자
	string GetMemberId();							// 멤버의 ID를 반환함
	string GetMemberPwd();							// 멤버의 비밀번호를 반환함
	void AddBiketoList(BikeInfo* curBike);			// 자전거를 대여 리스트에 저장함
	RentList* GetRentList();						// 빌린 자전거 리스트를 반환함
};
