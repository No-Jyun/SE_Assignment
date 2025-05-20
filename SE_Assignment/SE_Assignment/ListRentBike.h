#pragma once
#include <string>
#include <fstream>

#include "BaseUI.h"
using namespace std;

class ListRentBike;
class ListRentBikeUI;
class LoginMember;
class MemberInfo;
class RentList;

class ListRentBike 
{
private:
	LoginMember* refLoginMember;
	ListRentBikeUI* refListRentBikeUI;
	MemberInfo* curMember;
	RentList* curRentList;

public:
	ListRentBike(LoginMember* refLoginMem);
	void StartListRentBike(ofstream* out_fp, ifstream* in_fp);
};

class ListRentBikeUI : public BaseUI
{
private:
	ListRentBike* refListRentBike;
	bool isFirst = true;

public:
	ListRentBikeUI(ListRentBike* refControl, ofstream* out_fp, ifstream* in_fp);
	void PrintMessage(string info) override;
};