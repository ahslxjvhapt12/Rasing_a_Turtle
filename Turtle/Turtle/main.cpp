#include "console.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

enum class CURE_LEVEL
{
	CORRECTION = 0,
	EXERCISE,
	PHYSIOTHERAPY,
	MEDICATION,
	OPERATION,
};

void Init() {
	system("mode con:cols=32 lines=32");
	SetConsoleTitle(L"강산한테 거북목 치료비 삥뜯기는 게임");
}

void render() {

	int iCurmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░" << endl;
	wcout << L"░░░░░░░░░░▄█▀▀▀░░░░░░░░░░▀▀█▄░░░" << endl;
	wcout << L"░░░▄▀▀▀▀▀██░░░░░░░░░░░░░░░░░▀█▄░" << endl;
	wcout << L"░░█░▀░▀░░░▀██▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀█░" << endl;
	wcout << L"░░▀█▄▄▄▄▄▀▀█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▀░" << endl;
	wcout << L"░░░░░░░░░░░░░█▄▄█▀░░░░░▀█▄▄▄██░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	int iChangemode = _setmode(_fileno(stdout), iCurmode);
}

bool SaveData() {
	std::ofstream outputFile("data.txt");

	if (outputFile.is_open()) {
		// 숫자 쓰기
		int number = 123;
		outputFile << number << std::endl;

		// 문자열 쓰기
		std::string text = "Hello, World!";
		outputFile << text << std::endl;

		// 파일 닫기
		outputFile.close();
		std::cout << "데이터를 파일에 썼습니다." << std::endl;
	}
	else {
		std::cout << "파일을 열 수 없습니다." << std::endl;
	}

	return 0;
}

bool LoadData() {

	// 파일을 읽기 모드로 열기
	std::ifstream inputFile("data.txt");

	if (inputFile.is_open()) {
		// 숫자 읽기
		int number;
		inputFile >> number;
		std::cout << "숫자: " << number << std::endl;

		// 문자열 읽기
		string text;
		getline(inputFile, text);
		cout << "문자열: " << text << std::endl;

		// 파일 닫기
		inputFile.close();
		std::cout << "데이터를 파일에서 읽었습니다." << std::endl;
	}
	else {
		std::cout << "파일을 열 수 없습니다." << std::endl;
	}

	return 0;
}

int main() {

	Init();
	// 돈
	int money = 0;
	// 거북이 나이
	int age = 1;
	// 치료 단계
	int level = static_cast<int>(CURE_LEVEL::CORRECTION);
	// 1. 자세 교정
	// 2. 운동 치료
	// 3. 물리 치료
	// 4. 약물 치료
	// 5. 수술 (중 사망)

	//LoadData();
	render();
	//while (true)
	//{
	//	render();
	//}

	cout << "게임이 종료되었습니다.";
}