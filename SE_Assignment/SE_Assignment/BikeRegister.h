//
// BikeRegister 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

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
