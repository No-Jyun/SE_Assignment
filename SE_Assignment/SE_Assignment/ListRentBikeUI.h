//
// ListRentBikeUI 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

#include "BaseUI.h"

using namespace std;

class ListRentBike;

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