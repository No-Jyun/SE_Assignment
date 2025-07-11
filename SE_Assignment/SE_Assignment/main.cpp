// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <iostream>

// User Entity 관련 클래스
#include "UserDB.h"
#include "LoginMember.h"

// Bike Entity 관련 클래스
#include "BikeDB.h"

// Usecase 의 컨트롤, 바운더리 클래스 
#include "UserRegister.h"
#include "Login.h"
#include "Logout.h"
#include "BikeRegister.h"
#include "ListRentBike.h"
#include "BikeRent.h"
#include "ProgramExit.h"

using namespace std;

// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void program_exit();

// 변수 선언
ofstream out_fp;
ifstream in_fp;

// Entity Class 변수 선언 및 초기화
UserDB* userDB = new UserDB();
LoginMember* loginMember = new LoginMember();
BikeDB* bikeDB = new BikeDB();

// Control Class 변수 선언
UserRegister* userRegister = nullptr;
Login* login = nullptr;
Logout* logout = nullptr;
BikeRegister* bikeRegister = nullptr;
ListRentBike* listRentBike = nullptr;
BikeRent* bikeRent = nullptr;
ProgramExit* programExit = nullptr;

int main()
{
	// 파일 입출력을 위한 초기화
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);

	if (in_fp.is_open()) {
		doTask();			// 공유 자전거 대여 시스템 시작
	}

	// 파일 닫기
	out_fp.close();
	in_fp.close();

	return 0;
}

void doTask()
{
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		// 입력파일에서 메뉴 숫자 2개를 읽기
		in_fp >> menu_level_1 >> menu_level_2;

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1:   // "1.1. 회원가입" 메뉴 부분
				if (userRegister == nullptr) {
					// 회원가입 UseCase 컨트롤 클래스 생성
					userRegister = new UserRegister(userDB);
				}
				// 회원가입 UseCase 시작
				userRegister->StartUserRegister(&out_fp, &in_fp);

				break;
			}
			break;

		case 2:
			switch (menu_level_2)
			{
			case 1:   // "2.1 로그인" 메뉴 부분
				if (login == nullptr) {
					// 로그인 UseCase 컨트롤 클래스 생성
					login = new Login(userDB, loginMember);
				}
				// 로그인 UseCase 시작
				login->StartLogin(&out_fp, &in_fp);

				break;
			case 2:		// "2.2 로그아웃" 메뉴 부분
				if (logout == nullptr) {
					// 로그아웃 UseCase 컨트롤 클래스 생성
					logout = new Logout(loginMember);
				}
				// 로그아웃 UseCase 시작
				logout->StartLogout(&out_fp, &in_fp);

				break;
			}
			break;

		case 3:
			switch (menu_level_2)
			{
			case 1:   // "3.1. 자전거 등록" 메뉴 부분
				if (bikeRegister == nullptr) {
					// 자전거 등록 UseCase 컨트롤 클래스 생성
					bikeRegister = new BikeRegister(bikeDB);
				}
				// 자전거 등록 UseCase 시작
				bikeRegister->StartBikeRegister(&out_fp, &in_fp);

				break;
			}
			break;

		case 4:
			switch (menu_level_2)
			{
			case 1:   // "4.1. 자전거 대여" 메뉴 부분
				if (bikeRent == nullptr) {
					// 자전거 대여 UseCase 컨트롤 클래스 생성
					bikeRent = new BikeRent(loginMember, bikeDB);
				}
				// 자전거 대여 UseCase 시작
				bikeRent->StartBikeRent(&out_fp, &in_fp);

				break;
			}
			break;

		case 5:
			switch (menu_level_2)
			{
			case 1:   // "5.1. 자전거 대여 리스트" 메뉴 부분
				if (listRentBike == nullptr) {
					// 자전거 대여 조회 UseCase 컨트롤 클래스 생성
					listRentBike = new ListRentBike(loginMember);
				}
				// 자전거 대여 리스트 UseCase 시작
				listRentBike->StartListRentBike(&out_fp, &in_fp);

				break;
			}
			break;

		case 6:
			switch (menu_level_2)
			{
			case 1:   // "6.1. 종료" 메뉴 부분
				if (programExit == nullptr) {
					// 시스템 종료 컨트롤 클래스 생성
					programExit = new ProgramExit();
				}
				// 시스템 종료 시작
				programExit->StartProgramExit(&out_fp, &in_fp);
				is_program_exit = 1;		// while문 탈출 명시

				break;
			}
			break;
		}
		out_fp <<  endl;
	}
}