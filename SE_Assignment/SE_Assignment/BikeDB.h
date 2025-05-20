#pragma once
#include <string>
using namespace std;

class BikeDB;
class BikeInfo;
class ListRentBikeUI;

class BikeDB 
{
private:
	BikeInfo* bikeList[50];
	int numList = 0;

public:
	BikeDB();
	void RegisterBike(string id, string name);
	BikeInfo* GetBike(string id);
};

class BikeInfo 
{
private:
	string id;
	string name;

public:
	BikeInfo(string id, string name);
	string GetBikeId();
	string GetBikeName();
	void PrintBikeInfo(ListRentBikeUI* refUI);
};
