#pragma once

class BikeInfo;
class ListRentBikeUI;

class RentList {
private:
	BikeInfo* memRentList[50];
	int numList = 0;

public:
	RentList();
	void AddBiketoList(BikeInfo* curBike);
	void PrintAllBikeInfos(ListRentBikeUI* refUI);
};