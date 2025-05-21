#pragma once
#include <string>
using namespace std;

class UserDB;
class MemberInfo;
class RentList;
class BikeInfo;

class UserDB 
{
private:
	MemberInfo* memberList[50];
	int numList = 0;
	string adminId = "admin";
	string adminPwd = "admin";

public:
	UserDB();
	void RegisterUser(string id, string pwd, string pn);
	MemberInfo* GetThisMember(string id, string pwd);
	bool IsAdmin(string id, string pwd);
};

class MemberInfo
{
private:
	string id;
	string pwd;
	string pn;
	RentList* rentBikeList;

public:
	MemberInfo(string id, string pwd, string pn);
	string GetMemberId();
	string GetMemberPwd();
	void AddBiketoList(BikeInfo* curBike);
	RentList* GetRentList();
};
