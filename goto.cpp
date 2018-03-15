#include<iostream>
#include<Windows.h>
using namespace std;

extern void gotoxy(int x, int y)             //取输入的位置 
{
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

extern void Hide()                            //影藏光标 
{
	CONSOLE_CURSOR_INFO cursorInfo = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
