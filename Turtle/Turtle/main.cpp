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
	CORRECTION = 0, // 교정
	EXERCISE,		// 운동 치료
	PHYSIOTHERAPY,  // 물리 치료
	MEDICATION,		// 약물 치료
	OPERATION,		// 수술
};

enum class KEY {
	UP,
	DOWN,
	SPACEBAR,
};

void Init();
void printMoney(__int64 number);
void render(__int64 money, int age, int level);
bool SaveData(__int64 money, int age, int level);
bool LoadData(__int64& money, int& age, int& level);
int MenuDraw();
int KeyController();
int GetCursorXPos();
int GetCursorYPos();

void Init() {
	system("mode con:cols=33 lines=32");
	SetConsoleTitle(TEXT("강산이 강산강산"));
}

int GetCursorYPos()
{
	POINT pt = {};
	GetCursorPos(&pt);

	return pt.y;
}

int GetCursorXPos()
{
	POINT pt = {};
	GetCursorPos(&pt);

	return pt.x;
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
	system("cls");
	Go2XY(0, 0);

	SetColor((int)COLOR::RED, (int)COLOR::WHITE);

	cout << "                                 \n";
	cout << "                                 \n";
	cout << "                                 \n";
	Go2XY(0, 0);
	cout << "MONEY : ";
	printMoney(money);
	cout << "\n";
	cout << "AGE   : " << age << "\n";
	cout << "LEVEL : " << level + 1 << "\n\n";

	SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
	int iCurmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░▄█▀▀▀░░░░░░░░░░▀▀█▄░░░░" << endl;
	wcout << L"░░░▄▀▀▀▀▀██░░░░░░░░░░░░░░░░░▀█▄░░" << endl;
	wcout << L"░░█░▀░▀░░░▀██▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀█░░" << endl;
	wcout << L"░░▀█▄▄▄▄▄▀▀█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▀░░" << endl;
	wcout << L"░░░░░░░░░░░░░█▄▄█▀░░░░░▀█▄▄▄██░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << endl;
	int iChangemode = _setmode(_fileno(stdout), iCurmode);
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}

void DrawTitle() {

	/*
	.---..-..-..---. .---..-.   .---.
	`| |'| || || |-< `| |'| |__ | |-
	 `-' `----'`-'`-' `-' `----'`---'
	*/
	SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
	cout << ".---..-..-..---. .---..-.   .---.";
	cout << "`| |'| || || |-< `| |'| |__ | |- ";
	cout << " `-' `----'`-'`-' `-' `----'`---'";
	SetColor((int)COLOR::RED , (int)COLOR::WHITE);
	cout << "비정상적으로 앱 종료시 파일이 사라질 수 있습니다.";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	
}

int MenuDraw()
{
	DrawTitle();
	int x = 5;
	int y = 8;
	int posY = y;
	Go2XY(x, y);
	cout << "게임 시작";
	Go2XY(x, y + 1);
	cout << "게임 종료";

	Go2XY(x - 1, y);
	// 키 입력에 따라 > 이놈을 이동시킬겁니다
	while (true)
	{
		int iKey = KeyController();
		switch (iKey)
		{
		case  (int)KEY::DOWN:
		{
			if (posY > y) continue;
			posY++;
			cout << "\b" << " ";
			Go2XY(x - 1, posY);
			cout << "\b" << ">";
		}
		break;
		case (int)KEY::UP: {
			if (posY <= y) continue;
			posY--;
			cout << "\b" << " ";
			Go2XY(x - 1, posY);
			cout << "\b" << ">";
		}break;
		case (int)KEY::SPACEBAR: {
			return posY - y;
		}break;
		}
		Sleep(100); // 잘래용
	}
	return 0;
}


int KeyController()
{
	int iInput = _getch();
	if (iInput == 224)
	{
		iInput = _getch();

		switch (iInput)
		{
		case 72:
			return (int)KEY::UP;
		case 80:
			return (int)KEY::DOWN;
		default:
			break;
		}
	}
	else if (iInput == 32)
	{
		return (int)KEY::SPACEBAR;
	}
	return -1;
}

bool SaveData(__int64 money, int age, int level) {
	ofstream outputFile("data.txt");

	if (outputFile.is_open()) {

		outputFile << money << endl;
		outputFile << age << endl;
		outputFile << level << endl;

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
	ifstream inputFile("data.txt");

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
		cout << "로드되었습니다." << endl;
	}
	else {
		cout << "파일을 열 수 없습니다." << endl;
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
#pragma region LevelExplain

	// 1. 자세 교정
	// 2. 운동 치료
	// 3. 물리 치료
	// 4. 약물 치료
	// 5. 수술 (중 사망)

#pragma endregion
	LoadData(money, age, level);
	int tqe;
	while (true)
	{
		int iMenu = MenuDraw();
		if (iMenu == 0) {
			break;
		}
		else if (iMenu == 1) {
			cout << "게임을 종료합니다." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << '\r' << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
		}
	}


	render(money, age, level);
	//while (true)
	//{
	//	render();
	//}

	SaveData(money, age, level);
	cin >> tqe;
	cout << "게임이 종료되었습니다.";
}