#pragma once
#include <string>
#include <fstream>

#include "BaseUI.h"
using namespace std;

class BikeRent;
class BikeRentUI;
class LoginMember;
class BikeDB;
class BikeRentUI;
class MemberInfo;
class BikeInfo;

class BikeRent 
{
private:
	LoginMember* refLoginMember;
	BikeDB* refBikeDB;
	BikeRentUI* refBikeRentUI;
	MemberInfo* curMember;
	BikeInfo* curBike;

public:
	BikeRent(LoginMember* refLoginMem, BikeDB* refDB);
	void RentBike(string id);
	void StartBikeRent(ofstream* out_fp, ifstream* in_fp);
};

class BikeRentUI : public BaseUI
{
private:
	BikeRent* refBikeRent;

public:
	BikeRentUI(BikeRent* refControl, ofstream* out_fp, ifstream* in_fp);
	void InputBikeInfo(string id);
	void HandleInputUI();
	void PrintMessage(string info) override;
};