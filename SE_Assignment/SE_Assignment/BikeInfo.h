//
// BikeInfo 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

// 자전거 정보를 저장하기 위한 BikeInfo 클래스 정의
class BikeInfo
{
private:
	string id;			// 자전거 ID
	string name;		// 자전거 제품명

public:
	BikeInfo(string id, string name);		// 자전거 정보를 전달받는 생성자
	string GetBikeId();						// 자전거의 ID를 반환함
	string GetBikeName();					// 자전거의 제품명을 반환함
};
