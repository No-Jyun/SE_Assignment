//
// RentList 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <vector>
#include <string>

using namespace std;

class BikeInfo;

// 빌린 자전거 저장하기 위한 RentList 클래스 정의
class RentList {
private:
	BikeInfo* memRentList[50];		// 빌린 자전거 저장하기 위한 BikeInfo 포인터의 배열
	int numList = 0;				// memRentList 배열 저장위치 및 길이 관리용

public:
	RentList();												// 디폴트 생성자
	void AddBiketoList(BikeInfo* curBike);					// 전달받은 자전거를 memRentList에 저장함
	vector<pair<string, string>> GetSortedRentBikeInfos();	// 빌린 자전거의 정보를 ID를 기준으로 정렬하여 반환함
};