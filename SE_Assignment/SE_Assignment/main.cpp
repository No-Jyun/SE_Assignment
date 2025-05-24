// ��� ����
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <iostream>

// User Entity ���� Ŭ����
#include "UserDB.h"
#include "LoginMember.h"

// Bike Entity ���� Ŭ����
#include "BikeDB.h"

// Usecase �� ��Ʈ��, �ٿ���� Ŭ���� 
#include "UserRegister.h"
#include "Login.h"
#include "Logout.h"
#include "BikeRegister.h"
#include "ListRentBike.h"
#include "BikeRent.h"

using namespace std;

// ��� ����
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();
void program_exit();

// ���� ����
ofstream out_fp;
ifstream in_fp;

// Entity Class ���� ���� �� �ʱ�ȭ
UserDB* userDB = new UserDB();
LoginMember* loginMember = new LoginMember();
BikeDB* bikeDB = new BikeDB();

// Control Class ���� ����
UserRegister* userRegister = nullptr;
Login* login = nullptr;
Logout* logout = nullptr;
BikeRegister* bikeRegister = nullptr;
ListRentBike* listRentBike = nullptr;
BikeRent* bikeRent = nullptr;

int main()
{
	// ���� ������� ���� �ʱ�ȭ
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);

	if (in_fp.is_open()) {
		doTask();			// ���� ������ �뿩 �ý��� ����
	}

	// ���� �ݱ�
	out_fp.close();
	in_fp.close();

	return 0;
}

void doTask()
{
	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		// �Է����Ͽ��� �޴� ���� 2���� �б�
		in_fp >> menu_level_1 >> menu_level_2;

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1:   // "1.1. ȸ������" �޴� �κ�
				if (userRegister == nullptr) {
					userRegister = new UserRegister(userDB);
				}
				// ȸ������ UseCase ����
				userRegister->StartUserRegister(&out_fp, &in_fp);

				break;
			}
			break;

		case 2:
			switch (menu_level_2)
			{
			case 1:   // "2.1 �α���" �޴� �κ�
				if (login == nullptr) {
					login = new Login(userDB, loginMember);
				}
				// �α��� UseCase ����
				login->StartLogin(&out_fp, &in_fp);

				break;
			case 2:		// "2.2 �α׾ƿ�" �޴� �κ�
				if (logout == nullptr) {
					logout = new Logout(loginMember);
				}
				// �α׾ƿ� UseCase ����
				logout->StartLogout(&out_fp, &in_fp);

				break;
			}
			break;

		case 3:
			switch (menu_level_2)
			{
			case 1:   // "3.1. ������ ���" �޴� �κ�
				if (bikeRegister == nullptr) {
					bikeRegister = new BikeRegister(bikeDB);
				}
				// ������ ��� UseCase ����
				bikeRegister->StartBikeRegister(&out_fp, &in_fp);

				break;
			}
			break;

		case 4:
			switch (menu_level_2)
			{
			case 1:   // "4.1. ������ �뿩" �޴� �κ�
				if (bikeRent == nullptr) {
					bikeRent = new BikeRent(loginMember, bikeDB);
				}
				// ������ �뿩 UseCase ����
				bikeRent->StartBikeRent(&out_fp, &in_fp);

				break;
			}
			break;

		case 5:
			switch (menu_level_2)
			{
			case 1:   // "5.1. ������ �뿩 ����Ʈ" �޴� �κ�
				if (listRentBike == nullptr) {
					listRentBike = new ListRentBike(loginMember);
				}
				// ������ �뿩 ����Ʈ UseCase ����
				listRentBike->StartListRentBike(&out_fp, &in_fp);

				break;
			}
			break;

		case 6:
			switch (menu_level_2)
			{
			case 1:   // "6.1. ����" �޴� �κ�
				program_exit();
				is_program_exit = 1;
				break;
			}
			break;
		}
		out_fp <<  endl;
	}
}

// ���� �޴� ó���� �Լ�
void program_exit()
{
	out_fp << "6.1. ����";
}
