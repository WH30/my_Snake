#include<iostream>
#include"food.h"

using namespace std;

bool food::is_body(const  Snake & s)                  //判断实物是否在蛇身上
{
	Node *p = new Node;
	p = s.head;
	for (int i = 0; i < s.lenth; i++)
	{
		p = p->next;
		if (x == s.head->x&&y == s.head->y)
			return true;
	}
	return false;
}

void food::reset(const  Snake & s)                  //更新食物的位置
{
	do 
	{
		srand(time(0));
		x = rand() % (Width - 2) + 2;
		y = rand() % (Height - 2) + 2;
	} while (is_body(s));
}

bool food::is_eat(const Snake &s)                 //判断食物是否被吃掉
{
	if (x == s.head->x&&y == s.head->y)
	{	
		return true;
	}
	else
		return false;
}
