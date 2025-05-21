#include "ListRentBike.h"
#include "LoginMember.h"
#include "UserDB.h"
#include "RentList.h"

ListRentBike::ListRentBike(LoginMember* refLoginMem)
{
	refLoginMember = refLoginMem;
	refListRentBikeUI = nullptr;
	curMember = nullptr;
	curRentList = nullptr;
}

void ListRentBike::StartListRentBike(ofstream* out_fp, ifstream* in_fp)
{
	refListRentBikeUI = new ListRentBikeUI(this, out_fp, in_fp);

	curMember = refLoginMember->GetLoginMember();
	if (curMember == nullptr) return;

	curRentList = curMember->GetRentList();
	if (curRentList == nullptr) return;

	curRentList->PrintAllBikeInfos(refListRentBikeUI);
}




ListRentBikeUI::ListRentBikeUI(ListRentBike* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refListRentBike = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
	isFirstPrint = true;
}

void ListRentBikeUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	// 출력 하기
	if (isFirstPrint == true) {
		*out_fp << "5.1. 자전거 대여 리스트" << endl;
		isFirstPrint = false;
	}

	*out_fp << info << endl;
}
