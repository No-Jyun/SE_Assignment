//
// BaseUI 클래스 정의 위한 헤더 파일
// Copyright Reserved
//

#pragma once
#include <fstream>
using namespace std;

// 모든 바운더리 클래스의 공통 변수와 함수를 선언한 Super 클래스인 BaseUI 추상 클래스 정의
class BaseUI 
{
protected:
	ofstream* out_fp;		// 파일 출력용 포인터
	ifstream* in_fp;		// 파일 입력용 포인터
	
public:
	virtual void PrintMessage(string info) = 0;		// 출력 파일에 출력을 위한 순수 가상 함수
};