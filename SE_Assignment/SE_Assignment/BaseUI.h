#pragma once
#include <fstream>
using namespace std;

class BaseUI 
{
protected:
	ofstream* out_fp;
	ifstream* in_fp;
	
public:
	virtual void PrintMessage(string info) = 0;
};