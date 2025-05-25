//
// MemberInfo 클래스 정의를 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class RentList;
class BikeInfo;

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
