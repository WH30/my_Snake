#include<iostream>
#include<conio.h>
extern const int  Width ;
extern const int  Height ;

using namespace std;

enum Directon
{
	UP, DOWN, LEFT, RIGHT
};

class  Node                                   //定义蛇身节点
{
public:
//	enum Directon
	//{
		//UP, DOWM, LFET, RIGHT
	//};
	//定义4个方向
	
	Directon dec;     //运动方向
	int x;
	int y;
    Node *next;
	void set(int a, int b) { x = a, y = b; };
	Directon get_dir() { return dec; }         //取运动方向
	void set_dec(Directon de) { dec = de; }     //设置运动方向
};


class Snake                                         
{
public:
	friend Node;
private:
	Node *head;        //头结点
	Node *tail;       //尾节点
	int lenth;        //总长度
	int speed=300;      //速度
public:
	Snake();
	~Snake();
	void speed_up() { speed = speed - 20; }
	void speed_down(){ speed = speed + 20; }
	int get_speed() { return speed; }
	void move();                                //往前移动一格
	bool is_collosion();                        //判断是否发生碰撞
	bool hit_body();                            //判断是否与自身碰撞
	void add_tail();                           //在蛇尾长度加一
	void draw();                               //绘制蛇
	void keyboardHit();                        //键盘输入
	friend class food;

};
