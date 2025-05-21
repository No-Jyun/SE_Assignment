#include "BikeDB.h"
#include "ListRentBike.h"

BikeDB::BikeDB()
{
	for (int i = 0; i < 50; i++) {
		bikeList[i] = nullptr;
	}
}

void BikeDB::RegisterBike(string id, string name)
{
	bikeList[numList++] = new BikeInfo(id, name);
}

BikeInfo* BikeDB::GetBike(string id)
{
	for (int i = 0; i < numList; i++) {
		string curId = bikeList[i]->GetBikeId();

		if (id == curId) {
			return bikeList[i];
		}
	}
	return nullptr;
}




BikeInfo::BikeInfo(string id, string name)
{
	this->id = id;
	this->name = name;
}

string BikeInfo::GetBikeId()
{
	return this->id;
}

string BikeInfo::GetBikeName()
{
	return this->name;
}

void BikeInfo::PrintBikeInfo(ListRentBikeUI* refUI)
{
	string info = "> " + this->id + " " + this->name;
	refUI->PrintMessage(info);
}
