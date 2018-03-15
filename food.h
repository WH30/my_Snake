#include<iostream>
#include<stdlib.h>
#include<ctime>
#include"snake.h"
extern const int Width;
extern const int Height;

using namespace std;



class food
{
private:
	int x;
	int y;
public:
	food(){}
	food(int a, int b) { x = a, y = b; }
	~food(){}
	void reset(const  Snake & s);
	bool is_body(const Snake & s ) ;
	int x_val() { return x; }    
	int y_val() { return y; }
	void draw() { extern void gotoxy(int, int); gotoxy(x, y); cout << '*'; }
	bool is_eat(const Snake & s);
	friend class  Snake;
};

