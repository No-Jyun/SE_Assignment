#include "BikeRent.h"
#include "LoginMember.h"
#include "BikeDB.h"
#include "UserDB.h"

BikeRent::BikeRent(LoginMember* refLoginMem, BikeDB* refDB)
{
	refLoginMember = refLoginMem;
	refBikeDB = refDB;
	refBikeRentUI = nullptr;
	curMember = nullptr;
	curBike = nullptr;
}

void BikeRent::RentBike(string id)
{
	curMember = refLoginMember->GetLoginMember();
	if (curMember == nullptr) return;

	curBike = refBikeDB->GetBike(id);
	if (curBike == nullptr)return;

	curMember->AddBiketoList(curBike);

	string name = curBike->GetBikeName();
	string output = "> " + id + " " + name;
	refBikeRentUI->PrintMessage(output);
}

void BikeRent::StartBikeRent(ofstream* out_fp, ifstream* in_fp)
{
	refBikeRentUI = new BikeRentUI(this, out_fp, in_fp);
	refBikeRentUI->HandleInputUI();
}




BikeRentUI::BikeRentUI(BikeRent* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refBikeRent = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

void BikeRentUI::InputBikeInfo(string id)
{
	refBikeRent->RentBike(id);
}

void BikeRentUI::HandleInputUI()
{
	// �Է� �ޱ�
	if (in_fp == nullptr) {
		return;
	}

	string id;
	*in_fp >> id;

	InputBikeInfo(id);
}

void BikeRentUI::PrintMessage(string info)
{
	// ����ϱ�
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "4.1. ������ �뿩" << endl;
	*out_fp << info << endl;
}
