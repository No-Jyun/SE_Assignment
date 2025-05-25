//
// BikeRent 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class LoginMember;
class BikeDB;
class BikeRentUI;
class MemberInfo;
class BikeInfo;

// 자전거 대여 UseCase를 컨트롤하는 BikeRent 클래스 정의
class BikeRent 
{
private:
	LoginMember* refLoginMember;	// 로그인 정보를 가지는 LoginMember 포인터
	BikeDB* refBikeDB;				// 자전거 정보를 가지는 BikeDB 포인터
	BikeRentUI* refBikeRentUI;		// 자전거 대여 UseCase의 바운더리 클래스인 BikeRentUI 포인터
	MemberInfo* curMember;			// 현재 로그인한 멤버를 가리키는 MemberInfo 포인터
	BikeInfo* curBike;				// 대여할 자전거를 가리키는 BikeInfo 포인터

public:
	BikeRent(LoginMember* refLoginMem, BikeDB* refDB);		// LoginMember와 BikeDB를 전달받는 생성자
	void RentBike(string id);								// 전달받은 정보로 자전거를 찾아, 현재 로그인한 멤버의 대여 리스트에 추가함
	void StartBikeRent(ofstream* out_fp, ifstream* in_fp);	// 자전거 대여 UseCase 시작함
};
