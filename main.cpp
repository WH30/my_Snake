#include<iostream>
#include"food.h"
#include"background.h"
#include<Windows.h>


extern const int  Width=40;
extern const int  Height=20;
using namespace std;


int main()
{
	extern void gotoxy(int, int);           
	int tot = 0;                                    //总得分tot
	extern void Hide();
	Hide();
	background();                     //绘制背景
	Snake s;    
	s.draw();
	food fd;
	fd.reset(s);
	fd.draw();
	while (!s.is_collosion())             //没碰撞时循环
	{
		s.keyboardHit();                   //输入方向
		s.move();                           //移动
		if (fd.is_eat(s))               //食物被吃掉时循环
		{
			s.add_tail();             //加尾巴 
			fd.reset(s);              //更新食物
			fd.draw();               //画出食物
			tot++;                   //总分加一
			gotoxy(56, 10);
			cout << tot;
		}
		s.draw();                  //画蛇身

		Sleep(s.get_speed());
	}
	gotoxy(20, 10);
	cout << "** game over **";
	_getch();
	gotoxy(100, 100);
	return 0;
}

