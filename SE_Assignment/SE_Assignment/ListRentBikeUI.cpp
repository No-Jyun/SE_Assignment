//
// ListRentBikeUI 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "ListRentBikeUI.h"
#include "ListRentBike.h"

/*
	함수 이름 : ListRentBikeUI::ListRentBikeUI()
	기능	  : ListRentBikeUI의 생성자로, 멤버변수를 초기화함
	전달 인자 : refControl -> 컨트롤 클래스 포인터, out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
ListRentBikeUI::ListRentBikeUI(ListRentBike* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refListRentBike = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
	isFirstPrint = true;
}

/*
	함수 이름 : ListRentBikeUI::PrintMessage()
	기능	  : 전달받은 문자열을 출력파일에 출력함
	전달 인자 : info -> 출력할 문자열
	반환값    : 없음
*/
void ListRentBikeUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	if (isFirstPrint == true) {		// 첫 출력에만 메뉴 출력
		*out_fp << "5.1. 자전거 대여 리스트" << endl;
		isFirstPrint = false;
	}

	*out_fp << info << endl;
}

/*
	함수 이름 : ListRentBikeUI::StartListRentBikeUI()
	기능	  : 형식 맞추기용 함수로, 컨트롤 클래스에게 자전거 대여 정보 조회 처리 요청
	전달 인자 : 없음
	반환값    : 없음
*/
void ListRentBikeUI::StartListRentBikeUI()
{
	refListRentBike->ListUpRentedBike();
}
