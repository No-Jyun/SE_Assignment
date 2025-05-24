//
// ListRentBike 클래스와 ListRentBikeUI 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class ListRentBike;
class ListRentBikeUI;
class LoginMember;
class MemberInfo;
class RentList;

// 자전거 대여 정보 조회 UseCase를 컨트롤하는 ListRentBike 클래스 정의
class ListRentBike 
{
private:
	LoginMember* refLoginMember;			// 로그인 정보를 가지는 LoginMember 포인터
	ListRentBikeUI* refListRentBikeUI;		// 로그인 UseCase의 바운더리 클래스인 LoginUI 포인터
	MemberInfo* curMember;					// 현재 로그인한 멤버를 가리키는 MemberInfo 포인터
	RentList* curRentList;					// 대여한 자전거 목록을 가리키는 RentList 포인터

public:
	ListRentBike(LoginMember* refLoginMem);							// LoginMember를 전달받는 생성자
	void StartListRentBike(ofstream* out_fp, ifstream* in_fp);		// 자전거 대여 정보 조회 UseCase 시작함
	void ListUpRentedBike();										// 로그인한 멤버에게 자전거 대여 리스트를 가져와 한 줄씩 정보를 출력함
};

// 자전거 대여 정보 조회 UseCase에 대한 UI를 담당하는 ListRentBikeUI 클래스 정의
class ListRentBikeUI : public BaseUI
{
private:
	ListRentBike* refListRentBike;		// 객체를 생성한 컨트롤 클래스 포인터
	bool isFirstPrint = true;			// 출력 형식 맞추기 위한 boolen값

public:
	ListRentBikeUI(ListRentBike* refControl, ofstream* out_fp, ifstream* in_fp);	// 컨트롤 클래스와 파일 입출력용 포인터를 전달받는 생성자
	void PrintMessage(string info) override;										// 출력 파일에 출력함
	void StartListRentBikeUI();														// 형식 맞추기용 함수
};