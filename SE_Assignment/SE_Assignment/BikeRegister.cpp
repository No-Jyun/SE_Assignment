//
// BikeRegister 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "BikeRegister.h"
#include "BikeRegisterUI.h"
#include "BikeDB.h"

/*
	함수 이름 : BikeRegister::BikeRegister()
	기능	  : BikeRegister의 생성자로, 멤버변수를 초기화함
	전달 인자 : refDB -> main에서 만든 BikeDB를 가리키는 포인터
	반환값    : 없음
*/
BikeRegister::BikeRegister(BikeDB* refDB)
{
	refBikeDB = refDB;
	refBikeRegisterUI = nullptr;
}

/*
	함수 이름 : BikeRegister::RegisterBike()
	기능	  : 전달받은 정보로 BikeDB에 자전거 등록을 요청하고 UI를 출력시킴
	전달 인자 : id -> 자전거 ID, name -> 자전거 제품명
	반환값    : 없음
*/
void BikeRegister::RegisterBike(string id, string name)
{
	refBikeDB->RegisterBike(id, name);			// BikeDB에 자전거 정보를 넘겨 등록시킴

	string output = "> " + id + " " + name;
	refBikeRegisterUI->PrintMessage(output);	// 바운더리 클래스에게 출력시킴
}

/*
	함수 이름 : BikeRegister::StartBikeRegister()
	기능	  : 자전거 등록 UseCase의 바운더리 클래스를 생성하고 시작함
	전달 인자 : out_fp -> 출력 파일 포인터, in_fp -> 입력 파일 포인터
	반환값    : 없음
*/
void BikeRegister::StartBikeRegister(ofstream* out_fp, ifstream* in_fp)
{
	refBikeRegisterUI = new BikeRegisterUI(this, out_fp, in_fp);	// 바운더리 클래스 생성
	refBikeRegisterUI->HandleInputUI();								// 입력 UI 출력
}
