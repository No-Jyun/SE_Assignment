//
// BikeRegister 클래스와 BikeRegisterUI 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class BikeRegister;
class BikeRegisterUI;
class BikeDB;

// 자전거 등록 UseCase를 컨트롤하는 BikeRegister 클래스 정의
class BikeRegister 
{
private:
	BikeDB* refBikeDB;						// 자전거 정보를 가지는 BikeDB 포인터
	BikeRegisterUI* refBikeRegisterUI;		// 자전거 등록 UseCase의 바운더리 클래스인 BikeRegisterUI 포인터 

public:
	BikeRegister(BikeDB* refDB);								// BikeDB를 전달받는 생성자
	void RegisterBike(string id, string name);					// 전달받은 정보로 자전거 등록함
	void StartBikeRegister(ofstream* out_fp, ifstream* in_fp);	// 자전거 등록 UseCase 시작함
};

// 자전거 등록 UseCase에 대한 UI를 담당하는 BikeRegisterUI 클래스 정의
class BikeRegisterUI : public BaseUI
{
private:
	BikeRegister* refBIkeRegister;			// 객체를 생성한 컨트롤 클래스 포인터

public:
	BikeRegisterUI(BikeRegister* refControl, ofstream* out_fp, ifstream* in_fp);	// 컨트롤 클래스와 파일 입출력용 포인터를 전달받는 생성자
	void InputBikeInfo(string id, string name);										// 입력받은 정보를 컨트롤 클래스로 넘김
	void HandleInputUI();															// 입력 파일에서 입력을 읽음
	void PrintMessage(string info) override;										// 출력 파일에 출력함
};