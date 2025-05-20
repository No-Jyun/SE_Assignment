#include "BikeRegister.h"
#include "BikeDB.h"

BikeRegister::BikeRegister(BikeDB* refDB)
{
	refBikeDB = refDB;
	refBikeRegisterUI = nullptr;
}

void BikeRegister::RegisterBike(string id, string name)
{
	refBikeDB->RegisterBike(id, name);

	string output = "> " + id + " " + name;
	refBikeRegisterUI->PrintMessage(output);
}

void BikeRegister::StartBikeRegister(ofstream* out_fp, ifstream* in_fp)
{
	refBikeRegisterUI = new BikeRegisterUI(this, out_fp, in_fp);
	refBikeRegisterUI->HandleInputUI();
}




BikeRegisterUI::BikeRegisterUI(BikeRegister* refControl, ofstream* out_fp, ifstream* in_fp)
{
	refBIkeRegister = refControl;
	this->out_fp = out_fp;
	this->in_fp = in_fp;
}

void BikeRegisterUI::InputBikeInfo(string id, string name)
{
	refBIkeRegister->RegisterBike(id, name);
}

void BikeRegisterUI::HandleInputUI()
{
	if (in_fp == nullptr) {
		return;
	}

	string id, name;
	*in_fp >> id >> name;

	InputBikeInfo(id, name);
}

void BikeRegisterUI::PrintMessage(string info)
{
	if (out_fp == nullptr) {
		return;
	}

	*out_fp << "3.1. 자전거 등록" << endl;
	*out_fp << info << endl;
}
