#include "RentList.h"
#include "BikeDB.h"

RentList::RentList()
{
	for (int i = 0; i < 50; i++) {
		memRentList[i] = nullptr;
	}
}

void RentList::AddBiketoList(BikeInfo* curBike)
{
	memRentList[numList++] = curBike;
}

void RentList::PrintAllBikeInfos(ListRentBikeUI* refUI)
{
	for (int i = 0; i < numList; i++) {
		memRentList[i]->PrintBikeInfo(refUI);
	}
}
