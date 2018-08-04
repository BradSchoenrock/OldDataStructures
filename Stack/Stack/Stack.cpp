// Stack.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template <typename zeek>
class Node
{
public:
	//each node has a word to hold called data and a pointer to the next node
	zeek data;
	Node *next;

	//constructs a node with null pointer and null data
	Node()
	{
		next=0;
		data=0;
	}
	//constructs a node with data in it but doesnt point anywhere
	Node(zeek value)
	{
		next=0;
		data=value;
	}
	//costructs a node with data in it and points to some specified place
	//which can be null if that's what you pass it
	//usefull for adding to the middle of the list (in order)
	Node(zeek value,Node *n)
	{
		next=n;
		data=value;
	}

	bool search(zeek isit)
	{
		if(data==isit)
			return true;
		if(next==0)
			return false;
		else
			return next->search(isit);
	}
	
	void addfront(zeek toadd)
	{
		next=new Node(toadd,next);
	}

	zeek remove()
	{
		if(next==0)
			return data;
		zeek t=next->data;
		Node *temp=next;
		next=next->next;
		delete temp;
		return t;

	}
	void printTheList(zeek dumdata)
	{
		if(data!=dumdata)
			cout<<data<<'\n';
		if(next!=0)
			next->printTheList(dumdata);
	}
};



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
		head->addfront(topush);
	}
	zeek pop()
	{
		return head->remove();
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


int main(int argc, _TCHAR* argv[])
{
	char dumdata='*';
	Stack<char> *stak=new Stack<char>(dumdata);

	cout<<stak->isEmpty()<<'\n';

	stak->push('a');
	stak->push('b');
	stak->push('c');
	stak->push('d');
	stak->push('e');
	stak->push('f');
	stak->push('g');

	cout<<'\n'<<"here's the list"<<'\n'<<'\n';
	stak->printthelist(dumdata);
	cout<<'\n';

	cout<<"we poped "<<stak->pop()<<'\n';

	cout<<'\n';
	stak->printthelist(dumdata);
	cout<<'\n';

	cout<<"we poped "<<stak->pop()<<'\n';

	cout<<'\n';
	stak->printthelist(dumdata);
	cout<<'\n';

	cout<<"we poped "<<stak->pop()<<'\n';

	cout<<'\n';
	stak->printthelist(dumdata);
	cout<<'\n';

	stak->push('h');
	stak->push('i');
	stak->push('j');
	cout<<"we pushed h i &j "<<'\n';
	cout<<'\n';
	stak->printthelist(dumdata);
	cout<<'\n';

	cout<<"we poped "<<stak->pop()<<'\n';

	cout<<'\n';
	stak->printthelist(dumdata);
	cout<<'\n';

	cout<<'\n';

	cout<<stak->isEmpty()<<'\n';


}