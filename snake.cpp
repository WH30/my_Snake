#include<iostream>
#include"snake.h"



using namespace std;

Snake::Snake()
{
	lenth = 2;
	head = new Node;
	tail = new Node;
	Node *p = new Node;
	p->set(2, 2);
	p->next = nullptr;
	p->dec = RIGHT;
	tail = p;
	head->next = p;
	head->dec = RIGHT;
	head->set(3, 2);
}

Snake::~Snake()
{
	for (int i = 0; i < lenth-1; i++)
	{
		Node *p = new Node;
		p= head;
		head = head->next;
		free(p);
	}
}

void Snake::move()
{
	extern void  gotoxy(int, int);
	if (!is_collosion())
	{
		switch (head->dec)
		{
		case UP:
		{
			Node *p = new Node;
			p->next = head;
			p->dec = head->dec;
			p->set(head->x, head->y-1);
			head = p;
			for (int i = 0; i < lenth - 1; i++)
				p = p->next;
			Node *q = new Node;
			q = p->next;
			p->next = nullptr;
			tail = p;
			gotoxy(q->x, q->y);
			cout << ' ';
			free(q);
			break;
		}
		case DOWN:
		{
			Node *p = new Node;
			p->next = head;
			p->dec = head->dec;
			p->set(head->x, head->y + 1);
			head = p;
			for (int i = 0; i < lenth - 1; i++)
				p = p->next;
			Node *q = new Node;
			q = p->next;
			p->next = nullptr;
			tail = p;
			gotoxy(q->x, q->y);
			cout << ' ';
			free(q);
			break;
		}
		case LEFT:
		{
			Node *p = new Node;
			p->next = head;
			p->dec = head->dec;
			p->set(head->x-1, head->y );
			head = p;
			for (int i = 0; i < lenth - 1; i++)
				p = p->next;
			Node *q = new Node;
			q = p->next;
			p->next = nullptr;
			tail = p;
			gotoxy(q->x, q->y);
			cout << ' ';
			free(q);
			break;
		}
		case RIGHT:
		{
			Node *p = new Node;
			p->next = head;
			p->dec = head->dec;
			p->set(head->x+1, head->y);
			head = p;
			for (int i = 0; i < lenth - 1; i++)
				p = p->next;
			Node *q = new Node;
			q = p->next;
			p->next = nullptr;
			tail = p;
			gotoxy(q->x, q->y);
			cout << ' ';
			
			break;
		}

		}
	}

}

void Snake::add_tail()
{
	//Node *p = head;
	//for (int i = 0; i < lenth - 1; i++)
		//p = p->next;
	Node *q = new Node;
	q->next = nullptr;
	q->dec = tail->dec;
	switch (tail->dec)
	{
	case UP:q->set(tail->x, tail->y + 1); break;
	case DOWN:q->set(tail->x, tail->y - 1); break;
	case LEFT:q->set(tail->x+1, tail->y); break;
	case RIGHT:q->set(tail->x-1, tail->y); break;
	}
	tail->next = q;
	tail = q;
	//free(q);
	lenth++;
}

bool Snake::hit_body()
{
	Node *p = new Node;
	p = head;
	for (int i = 0; i < lenth-1; i++)
	{
		p = p->next;
		if (p->x == head->x&&p->y == head->y)
		{
			return true;
		}
	}
	return false;
}

bool Snake::is_collosion()
{
	if (head->x == 1 || head->x == Width  || head->y == 1 || head->y == Height )
		return true;
	else if (hit_body())
		return true;
	else
		return false;
}

void Snake::draw()
{
	extern void gotoxy(int, int);
	Node *p = new Node ;
	p = head;
	for (int i = 0; i < lenth ; i++)
	{
		gotoxy(p->x, p->y);
		cout << '@';
		p = p->next;
	}
}

void Snake::keyboardHit()
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case 'W':
		case 'w':
			if (head->dec == DOWN)
				break;
			else
				head->dec = UP; break;
		case 'S':
		case 's':
			if (head->dec == UP)
				break;
			else
				head->dec = DOWN; break;
		case 'A':
		case 'a':
			if (head->dec == RIGHT)
				break;
			else
				head->dec = LEFT; break;
		case 'D':
		case 'd':
			if (head->dec == LEFT)
				break;
			else
				head->dec = RIGHT; break;
		case 'o':
		case 'O':
			speed_up(); break;
		case 'p':
		case 'P':
			speed_down(); break;
		}
	}
}

