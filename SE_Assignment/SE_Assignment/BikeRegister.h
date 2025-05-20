#pragma once
#include <string>
#include <fstream>

#include "BaseUI.h"
using namespace std;

class BikeRegister;
class BikeRegisterUI;
class BikeDB;

class BikeRegister 
{
private:
	BikeDB* refBikeDB;
	BikeRegisterUI* refBikeRegisterUI;

public:
	BikeRegister(BikeDB* refDB);
	void RegisterBike(string id, string name);
	void StartBikeRegister(ofstream* out_fp, ifstream* in_fp);
};

class BikeRegisterUI : public BaseUI
{
private:
	BikeRegister* refBIkeRegister;

public:
	BikeRegisterUI(BikeRegister* refControl, ofstream* out_fp, ifstream* in_fp);
	void InputBikeInfo(string id, string name);
	void HandleInputUI();
	void PrintMessage(string info) override;
};