// Que.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename zeek>
class Que
{
public:
	Node<zeek>* head;
	Node<zeek>* tail;

	Que(zeek dumdata)
	{
		head=new Node<zeek>(dumdata);
		tail=head;
	}

	void Qu(zeek topush)
	{
		tail=head->addBack(topush,tail);
	}
	zeek DQu()
	{
		if(head->next!=0)
			if(head->next->next==0)
				tail=head;
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

