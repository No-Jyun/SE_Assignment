#include "UserDB.h"
#include "RentList.h"
#include "BikeDB.h"

UserDB::UserDB() {
	for (int i = 0; i < 50; i++) {
		memberList[i] = nullptr;
	}
}

void UserDB::RegisterUser(string id, string pwd, string pn) {
	memberList[numList++] = new MemberInfo(id, pwd, pn);
}

MemberInfo* UserDB::GetThisMember(string id, string pwd)
{
	for (int i = 0; i < numList; i++) {
		string curId = memberList[i]->GetMemberId();

		if (id == curId) {
			string curPwd = memberList[i]->GetMemberPwd();

			if (pwd == curPwd) {
				return memberList[i];
			}
		}
	}
	return nullptr;
}

bool UserDB::IsAdmin(string id, string pwd)
{
	if (id == adminId && pwd == adminPwd) {
		return true;
	}
	else {
		return false;
	}
}




MemberInfo::MemberInfo(string id, string pwd, string pn) {
	this->id = id;
	this->pwd = pwd;
	this->pn = pn;

	rentBikeList = new RentList();
}

string MemberInfo::GetMemberId()
{
	return id;
}

string MemberInfo::GetMemberPwd()
{
	return pwd;
}

void MemberInfo::AddBiketoList(BikeInfo* curBike) {
	rentBikeList->AddBiketoList(curBike);
}

RentList* MemberInfo::GetRentList()
{
	return rentBikeList;
}

