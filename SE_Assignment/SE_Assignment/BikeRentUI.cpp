//
// BikeRentUI 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "BikeRentUI.h"
#include "BikeRent.h"

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
