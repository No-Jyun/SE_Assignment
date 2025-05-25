//
// BikeInfo 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "BikeInfo.h"

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
