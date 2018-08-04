// Stack.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename zeek>
class Stack
{
public:
	Node<zeek>* head;

	Stack(zeek dumdata)
	{
		head=new Node<zeek>(dumdata);
	}

	void push(zeek topush)
	{
		head->addFront(topush,head);
	}
	zeek pop()
	{
		return head->removeFront();
	}
	void printthelist(zeek d)
	{
		head->printTheList(d);
	}

	bool isEmpty()
	{
		if(head->next==0)
			return true;
		return false;
	}
};