//
// BikeDB 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <string>

using namespace std;

class BikeInfo;

// 등록한 자전거 저장하기 위한 BikeDB 클래스 정의
class BikeDB 
{
private:
	BikeInfo* bikeList[50];		// 등록한 자전거 저장하기 위한 BikeInfo 포인터의 배열
	int numList = 0;			// bikeList 배열 저장위치 및 길이 관리용

public:
	BikeDB();										// 디폴트 생성자
	void RegisterBike(string id, string name);		// 전달받은 id, name으로 새로운 자전거를 만들고 저장함
	BikeInfo* GetBike(string id);					// 전달받은 id를 갖는 자전거를 반환함
};
