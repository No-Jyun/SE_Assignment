//
// RentList 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include <algorithm>

#include "RentList.h"
#include "BikeDB.h"

/*
	함수 이름 : RentList::RentList()
	기능	  : RentList의 디폴트 생성자로, memRentList 포인터 배열을 초기화함
	전달 인자 : 없음
	반환값    : 없음
*/
RentList::RentList()
{
	for (int i = 0; i < 50; i++) {
		memRentList[i] = nullptr;
	}
}

/*
	함수 이름 : RentList::AddBiketoList()
	기능	  : 전달받은 자전거를 memRentList에 저장함
	전달 인자 : curBike -> 저장할 BikeInfo 객체를 가르키는 포인터
	반환값    : 없음
*/
void RentList::AddBiketoList(BikeInfo* curBike)
{
	memRentList[numList++] = curBike;	// memRentList의 numList 위치에 curBike를 저장하고 numList를 증가시킴
}

/*
	함수 이름 : RentList::GetSortedRentBikeInfos()
	기능	  : memRentList에 저장된 BikeInfo 객체에서 id와 name을 가져와, 벡터에 저장한 뒤 id를 기준으로 정렬하여 반환함
	전달 인자 : 없음
	반환값    : vector<pair<string, string>> -> 자전거의 ID와 제품명을 담고 있는 벡터
*/
vector<pair<string, string>> RentList::GetSortedRentBikeInfos()
{
	vector<pair<string, string>> result;		// 리턴용 벡터 선언

	for (int i = 0; i < numList; i++) {			// 저장된 모든 BikeInfo를 살펴봄
		string id, name;
		id = memRentList[i]->GetBikeId();		// 빌린 자전거의 ID 가져오기
		name = memRentList[i]->GetBikeName();	// 빌린 자전거의 제품명 가져오기
		result.push_back({ id,name });			// { ID, 제품명 } 쌍 벡터에 넣기
	}
	sort(result.begin(), result.end());			// 자전거 ID가 앞에 있으므로 자전거 ID를 1순위로 정렬

	return result;								// 벡터 반환
}
