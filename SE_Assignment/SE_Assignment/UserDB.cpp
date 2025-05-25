//
// UserDB 클래스 구현 위한 소스 파일
// Copyright Reserved
//

#include "UserDB.h"
#include "MemberInfo.h"

/*
	함수 이름 : UserDB::UserDB()
	기능	  : UserDB의 디폴트 생성자로, memberList 포인터 배열을 초기화함
	전달 인자 : 없음
	반환값    : 없음
*/
UserDB::UserDB() 
{
	for (int i = 0; i < 50; i++) {
		memberList[i] = nullptr;
	}
}

/*
	함수 이름 : UserDB::RegisterUser()
	기능	  : 전달받은 정보로 새로운 멤버를 만들고 memberList에 저장함
	전달 인자 : id -> 멤버 ID, pwd -> 멤버 비밀번호, pn -> 멤버 전화번호
	반환값    : 없음
*/
void UserDB::RegisterUser(string id, string pwd, string pn) 
{	
	// 새로운 MemberInfo 객체를 생성하고 memberList의 numList 위치에 포인터를 저장하고 numList를 증가시킴
	memberList[numList++] = new MemberInfo(id, pwd, pn);
}

/*
	함수 이름 : UserDB::GetThisMember()
	기능	  : 전달받은 id와 pwd가 일치하는 멤버를 반환함
	전달 인자 : id -> 멤버 ID, pwd -> 멤버 비밀번호
	반환값    : MemberInfo* -> 일치하는 MemberInfo 포인터
*/
MemberInfo* UserDB::GetThisMember(string id, string pwd)
{
	for (int i = 0; i < numList; i++) {						// 저장된 모든 MemberInfo를 살펴봄
		string curId = memberList[i]->GetMemberId();		// 멤버 ID 가져옴

		if (id == curId) {									// 전달받은 ID와 같다면
			string curPwd = memberList[i]->GetMemberPwd();	// 멤버 비밀번호를 가져옴

			if (pwd == curPwd) {							// 전달받은 비밀번호도 같다면
				return memberList[i];						// 해당 멤버를 가리키는 포인터 반환
			}
		}
	}
	return nullptr;
}

/*
	함수 이름 : UserDB::IsAdmin()
	기능	  : 전달받은 ID와 비밀번호를 관리자 ID와 비밀번호와 비교하여 일치여부를 전달함
	전달 인자 : id -> 멤버 ID, pwd -> 멤버 비밀번호
	반환값    : bool -> 관리자 O : true, 관리자 X : false
*/
bool UserDB::IsAdmin(string id, string pwd)
{
	if (id == adminId && pwd == adminPwd) {		// 전달받은 ID와 비밀번호가 관리자용 ID와 비밀번호가 일치한다면
		return true;
	}
	else 
	{
		return false;
	}
}
