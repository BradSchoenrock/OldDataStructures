// test.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <assert.h>
using namespace std;

void wait()
{
	string z;
	cout<<'\n'<<"waiting..."<<'\n';
	cin>>z;
}

int main(array<System::String ^> ^args)
{
	double y;
    int z;
	double n=3;
	double d=2;
	y=n/d;
	z=n/d;
	cout<<y<<"   "<<z<<'\n';
	wait();

	n=6;
	d=5;
	y=n/d;
	z=n/d;
	cout<<y<<"   "<<z<<'\n';
	wait();

	n=5;
	d=6;
	y=n/d;
	z=n/d;
	cout<<y<<"   "<<z<<'\n';
	wait();

}
