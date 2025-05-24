//
// BikeDB 클래스와 BikeInfo 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "BikeDB.h"

/*
	함수 이름 : BikeDB::BikeDB()
	기능	  : BikeDB 디폴트 생성자로 bikeList 포인터 배열을 초기화함
	전달 인자 : 없음
	반환값    : 없음
*/
BikeDB::BikeDB()
{
	for (int i = 0; i < 50; i++) {
		bikeList[i] = nullptr;
	}
}

/*
	함수 이름 : BikeDB::RegisterBike()
	기능	  : 전달받은 정보로 새로운 자전거를 만들고 bikeList에 저장함
	전달 인자 : id -> 등록할 자전거 ID, name -> 등록할 자전거 비밀번호
	반환값    : 없음
	*/
void BikeDB::RegisterBike(string id, string name)
{
	// 새로운 BikeInfo 객체를 생성하고 bikeList의 numList 위치에 포인터를 저장하고 numList를 증가시킴
	bikeList[numList++] = new BikeInfo(id, name);	
}

/*
	함수 이름 : BikeDB::GetBike()
	기능	  : 전달받은 id가 일치하는 자전거를 반환함
	전달 인자 : id -> 찾는 자전거의 ID
	반환값    : BikeInfo* -> 일치하는 BikeInfo 객체를 가르키는 포인터
*/
BikeInfo* BikeDB::GetBike(string id)
{
	for (int i = 0; i < numList; i++) {				// 저장된 모든 BikeInfo를 살펴봄
		string curId = bikeList[i]->GetBikeId();	// 자전거 ID를 가져옴

		if (id == curId) {							// 전달받은 ID와 같다면
			return bikeList[i];						// 해당 자전거를 가리키는 포인터 반환
		}
	}
	return nullptr;
}




/*
	함수 이름 : BikeInfo::BikeInfo()
	기능	  : BikeInfo의 생성자로, 전달받은 정보로 멤버변수를 초기화함
	전달 인자 : id -> 자전거 ID, name -> 자전거 제품명
	반환값    : 없음
*/
BikeInfo::BikeInfo(string id, string name)
{
	this->id = id;
	this->name = name;
}

/* 
	함수 이름 : BikeInfo::GetBikeId()
	기능	  : 자전거 ID를 반환함
	전달 인자 : 없음
	반환값    : string -> 자전거 ID 문자열
*/
string BikeInfo::GetBikeId()
{
	return this->id;
}

/*
	함수 이름 : BikeInfo::GetBikeName()
	기능	  : 자전거 제품명을 반환함
	전달 인자 : 없음
	반환값    : string -> 자전거 제품명 문자열
*/
string BikeInfo::GetBikeName()
{
	return this->name;
}
