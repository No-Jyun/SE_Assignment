//
// ListRentBike 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include <vector>

#include "ListRentBike.h"
#include "ListRentBikeUI.h"
#include "LoginMember.h"
#include "MemberInfo.h"
#include "RentList.h"

/*
	함수 이름 : ListRentBike::ListRentBike()
	기능	  : ListRentBike의 생성자로, 멤버변수를 초기화함
	전달 인자 : refLoginMem -> main에서 만든 LoginMember를 가리키는 포인터
	반환값    : 없음
*/
ListRentBike::ListRentBike(LoginMember* refLoginMem)
{
	refLoginMember = refLoginMem;
	refListRentBikeUI = nullptr;
	curMember = nullptr;
	curRentList = nullptr;
}

/*
	함수 이름 : ListRentBike::StartListRentBike()
	기능	  : 자전거 대여 정보 조회 UseCase의 바운더리 클래스를 생성하고 시작함
	전달 인자 : out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
void ListRentBike::StartListRentBike(ofstream* out_fp, ifstream* in_fp)
{
	refListRentBikeUI = new ListRentBikeUI(this, out_fp, in_fp);	// 바운더리 클래스 생성
	refListRentBikeUI->StartListRentBikeUI();						// 입력 UI 출력
}

/*
	함수 이름 : ListRentBike::ListUpRentedBike()
	기능	  : LoginMember에 저장된 로그인 정보로 로그인한 멤버를 가져와서 해당 멤버가 가진 RentList를 통해 자전거 정보를 출력한다.
	전달 인자 : 없음
	반환값    : 없음
*/
void ListRentBike::ListUpRentedBike()
{
	curMember = refLoginMember->GetLoginMember();	// LoginMember에 저장된 로그인한 멤버로 curMember 초기화
	if (curMember == nullptr) return;

	curRentList = curMember->GetRentList();			// 해당 멤버가 가지고 있는 RentList로 curRentList 초기화
	if (curRentList == nullptr) return;

	vector<pair<string, string>> printVec = curRentList->GetSortedRentBikeInfos();	// RentList에 저장된 자전거 정보 가져오기
	for (int i = 0; i < printVec.size(); i++) {										// 빌린 자전거 전부를 반복함
		string info = "> " + printVec[i].first + " " + printVec[i].second;
		refListRentBikeUI->PrintMessage(info);										// 바운더리 클래스에게 자전거 정보 출력시킴
	}
}
