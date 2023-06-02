#pragma once
#include <windows.h>

enum class COLOR {
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VIOLET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE
};
void FullScreen();
void Go2XY(int, int);
BOOL Go2XYTest(int, int);
void CursorSet(bool, DWORD);
void SetColor(int, int);
int GetColor();
int GetbgColor();