// Operator overloading quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std; 
class Point
{
public:
		int x, y; 
		// You must use the X and Y 

	Point()
	{
		x=0;
		y=0;
	}
	Point(int dol,int pens)
	{
		x=dol;
		y=pens;
	}

	friend ostream &operator<<(ostream &os, const Point v)
	{
		os<<"(";
		os << v.x; 
		os << ","; 
		os << v.y; 
		os<<")";
		return os;
	}

	bool operator<(Point &other)
	{
		if(x<other.x && y<other.y)
			return true;
		return false;
	}

	friend Point &operator*(int a, const Point k)
	{
		Point *f=new Point();
		Point &result=*f;
		f->x=k.x*a;
		f->y=k.y*a;
		return *f;
	}
		
};
int main() 
{ 
	Point p1; 
	cout << "This should print \"(0,0)\". " << p1 << endl; 
	Point p2(1,2); 
	cout << "This should print \"(1,2)\". " << p2 << endl; 
	// Given two points A and B 
	// A < B if A.x < B.x and A.y < B.y 
	if (p1 < p2) 
		cout << "Yea\n"; 
	else 
		cout << "Oops\n"; 
	Point p3; 
	p3 = 5*p2; 
	cout << "This should print \"(5,10)\". " << p3 << endl;
	 
}

