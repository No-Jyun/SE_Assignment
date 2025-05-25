//
// BikeRegisterUI 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "BikeRegisterUI.h"
#include "BikeRegister.h"

/*
	함수 이름 : BikeRegisterUI::BikeRegisterUI()
	기능	  : BikeRegisterUI의 생성자로, 멤버변수를 초기화함
	전달 인자 : refControl -> 컨트롤 클래스 포인터, out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
BikeRegisterUI::BikeRegisterUI(BikeRegister* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refBIkeRegister = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

/*
	함수 이름 : BikeRegisterUI::InputBikeInfo()
	기능	  : 입력받은 정보를 컨트롤 클래스에게 넘김
	전달 인자 : id -> 자전거 ID, name -> 자전거 제품명
	반환값    : 없음
*/
void BikeRegisterUI::InputBikeInfo(string id, string name)
{
	refBIkeRegister->RegisterBike(id, name);		// 컨트롤 클래스에게 정보를 넘겨, 자전거 등록 처리
}

/*
	함수 이름 : BikeRegisterUI::HandleInputUI()
	기능	  : UI를 시작하여 파일로부터 입력을 읽음
	전달 인자 : 없음
	반환값    : 없음
*/
void BikeRegisterUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id, name;
	*in_fp >> id >> name;		// 등록하려는 자전거의 ID, 제품명을 입력받음

	InputBikeInfo(id, name);	// 입력 처리하는 함수 호출
}

/*
	함수 이름 : BikeRegisterUI::PrintMessage()
	기능	  : 전달받은 문자열을 출력파일에 출력함
	전달 인자 : info -> 출력할 문자열
	반환값    : 없음
*/
void BikeRegisterUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "3.1. 자전거 등록" << endl;
	*out_fp << info << endl;
}
