#include<iostream>
#include<process.h>

extern const int Width;
extern const int Height;

extern void gotoxy(int , int );

void background()                                //设置背景
{
	for (int i = 1; i <= Height; i++)
	{
		gotoxy(1,i);
		cout << '|';
		gotoxy( Width,i);
		cout << '|';
	}
	for (int j = 1; j <= Width; j++)
	{
		gotoxy( j,1);
		cout << '-';
		gotoxy( j,Height);
		cout << '-';
	}
	gotoxy(1, 1); cout << '+';
	gotoxy(Width,1); cout << '+';
	gotoxy(1,Height); cout << '+';
	gotoxy( Width,Height); cout << '+';      

	gotoxy(50, 10 );
	cout << "总分：0";
	gotoxy(50, 12);
	cout << "Press o to speed up ";
	gotoxy(50, 14);
	cout << "Press p to speed down ";
}



