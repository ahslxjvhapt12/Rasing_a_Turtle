#include "console.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

// POINT pt = {};
// GetCursorPos(&pt)
enum class CURE_LEVEL
{
	CORRECTION = 0,
	EXERCISE,
	PHYSIOTHERAPY,
	MEDICATION,
	OPERATION,
};


void Init();
void printMoney(__int64 number);
void render(__int64 money, int age, int level);
bool SaveData(__int64 money, int age, int level);
bool LoadData(__int64& money, int& age, int& level);



void Init() {
	system("mode con:cols=32 lines=32");
	SetConsoleTitle(TEXT("강산한테 거북목 치료비 삥뜯기는 게임"));
}

void printMoney(__int64 number) {
	int cnt = 0;

	stack<string> s1;
	while (true)
	{
		if (number == 0) {
			break;
		}
		if (cnt == 3) {
			cnt = 0;
			s1.push(",");
		}
		s1.push(to_string((number % 10)));
		number /= 10;
		cnt++;
	}

	while (!s1.empty())
	{
		cout << s1.top();
		s1.pop();
	}
}

void render(__int64 money, int age, int level) {
	cout << "MONEY : ";
	printMoney(money);
	cout << "\n";
	cout << "AGE   : " << age << "\n";
	cout << "LEVEL : " << level + 1 << "\n";
	Go2XY(0, 3);
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

bool SaveData(__int64 money, int age, int level) {
	std::ofstream outputFile("data.txt");

	if (outputFile.is_open()) {
		// 숫자 쓰기
		int number = 123;
		outputFile << number << endl;

		// 문자열 쓰기
		string text = "Hello, World!";
		outputFile << text << endl;

		// 파일 닫기
		outputFile.close();
		cout << "저장되었습니다." << endl;
	}
	else {
		cout << "파일을 열 수 없습니다." << endl;
	}

	return 0;
}

bool LoadData(__int64& money, int& age, int& level) {

	// 파일을 읽기 모드로 열기
	std::ifstream inputFile("data.txt");

	if (inputFile.is_open()) {
		// 숫자 읽기
		int number;
		inputFile >> money;
		//std::cout << "숫자: " << number << std::endl;

		//// 문자열 읽기
		//string text;
		//getline(inputFile, text);
		//cout << "문자열: " << text << std::endl;

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
	//unsigned long long 은 자료형이 너무 못생겼어
	__int64 money = 1;
	// 거북이 나이
	int age = 1;
	// 치료 단계
	int level = static_cast<int>(CURE_LEVEL::CORRECTION);
	// 1. 자세 교정
	// 2. 운동 치료
	// 3. 물리 치료
	// 4. 약물 치료
	// 5. 수술 (중 사망)

	LoadData(money, age, level);
	render(money, age, level);
	//while (true)
	//{
	//	render();
	//}

	SaveData(money, age, level);
	cout << "게임이 종료되었습니다.";
}