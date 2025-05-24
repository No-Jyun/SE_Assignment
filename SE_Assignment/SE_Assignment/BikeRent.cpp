//
// BikeRent 클래스와 BikeRentUI 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "BikeRent.h"
#include "LoginMember.h"
#include "BikeDB.h"
#include "UserDB.h"

/*
	함수 이름 : BikeRent::BikeRent()
	기능	  : BikeRent의 생성자로, 멤버변수를 초기화함
	전달 인자 : refLoginMem -> main에서 만든 LoginMember를 가리키는 포인터, refDB -> main에서 만든 BikeDB를 가리키는 포인터
	반환값    : 없음
*/
BikeRent::BikeRent(LoginMember* refLoginMem, BikeDB* refDB)
{
	refLoginMember = refLoginMem;
	refBikeDB = refDB;
	refBikeRentUI = nullptr;
	curMember = nullptr;
	curBike = nullptr;
}

/*
	함수 이름 : BikeRent::RentBike()
	기능	  : 전달받은 정보로 자전거를 찾고, 해당 자전거를 현재 로그인한 멤버의 대여 리스트에 추가함
	전달 인자 : id -> 자전거 ID
	반환값    : 없음
*/
void BikeRent::RentBike(string id)
{
	curMember = refLoginMember->GetLoginMember();	// LoginMember에 저장된 로그인한 멤버로 curMember 초기화
	if (curMember == nullptr) {
		return;
	}

	curBike = refBikeDB->GetBike(id);				// BikeDB에서 자전거 ID가 일치하는 자전거로 curBike 초기화
	if (curBike == nullptr) {
		return;
	}

	curMember->AddBiketoList(curBike);				// curMember의 자전거 대여 리스트에 curBike 추가

	string name = curBike->GetBikeName();
	string output = "> " + id + " " + name;
	refBikeRentUI->PrintMessage(output);			// 바운더리 클래스에게 출력시킴
}

/*
	함수 이름 : BikeRent::StartBikeRent()
	기능	  : 자전거 대여 UseCase의 바운더리 클래스를 생성하고 시작함
	전달 인자 : out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
void BikeRent::StartBikeRent(ofstream* out_fp, ifstream* in_fp)
{
	refBikeRentUI = new BikeRentUI(this, out_fp, in_fp);	// 바운더리 클래스 생성
	refBikeRentUI->HandleInputUI();							// 입력 UI 출력
}




/*
	함수 이름 : BikeRentUI::BikeRentUI()
	기능	  : BikeRentUI의 생성자로, 멤버변수를 초기화함
	전달 인자 : refControl -> 컨트롤 클래스 포인터, out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
BikeRentUI::BikeRentUI(BikeRent* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refBikeRent = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	함수 이름 : BikeRentUI::InputBikeInfo()
	기능	  : 입력받은 정보를 컨트롤 클래스에게 넘김
	전달 인자 : id -> 입력받은 자전거 ID
	반환값    : 없음
*/
void BikeRentUI::InputBikeInfo(string id)
{
	refBikeRent->RentBike(id);
}

/*
	함수 이름 : BikeRentUI::HandleInputUI()
	기능	  : UI를 시작하여 파일로부터 입력을 읽음
	전달 인자 : 없음
	반환값    : 없음
*/
void BikeRentUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id;
	*in_fp >> id;			// 빌릴 자전거의 ID를 입력받음

	InputBikeInfo(id);		// 입력 처리하는 함수 호출
}

/*
	함수 이름 : BikeRentUI::PrintMessage()
	기능	  : 전달받은 문자열을 출력파일에 출력함
	전달 인자 : info -> 출력할 문자열
	반환값    : 없음
*/
void BikeRentUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "4.1. 자전거 대여" << endl;
	*out_fp << info << endl;
}
