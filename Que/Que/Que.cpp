// Que.cpp : Defines the entry point for the console application.
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

	//all these methods return a Node* tail to readjust my tail pointer
	
	Node* addback(zeek toadd,Node*tail)
	{
		return tail->next=new Node(toadd);
	}

	zeek removefront()
	{
		if(next==0)
			return this->data;
		if(next->next==0)
		{
			zeek tim=next->data; //tim is a temp variable for returning the data in the deleted node
			Node* temp=next;
			next=0;
			delete temp;
			return tim;
		}
		else
		{
			zeek tmmmm=next->data;
			Node* temp=next->next;
			next->next=0;
			delete next;
			next=temp;
			return tmmmm;
		}

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
		tail=head->addback(topush,tail);
	}
	zeek DQu()
	{
		if(head->next!=0)
			if(head->next->next==0)
				tail=head;
		return head->removefront();
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
	Que<char> *Q=new Que<char>(dumdata);

	cout<<Q->isEmpty()<<'\n';

	Q->Qu('a');
	Q->Qu('b');
	Q->Qu('c');
	Q->Qu('d');
	Q->Qu('e');
	Q->Qu('f');
	Q->Qu('g');

	cout<<'\n'<<"here's the list"<<'\n'<<'\n';
	Q->printthelist(dumdata);
	cout<<'\n';

	cout<<"we DeQued "<<Q->DQu()<<'\n';

	cout<<'\n';
	Q->printthelist(dumdata);
	cout<<'\n';

	cout<<"we DeQued "<<Q->DQu()<<'\n';

	cout<<'\n';
	Q->printthelist(dumdata);
	cout<<'\n';

	cout<<"we DeQued "<<Q->DQu()<<'\n';

	cout<<'\n';
	Q->printthelist(dumdata);
	cout<<'\n';

	Q->Qu('h');
	Q->Qu('i');
	Q->Qu('j');
	cout<<"we Qued h i & j "<<'\n';
	cout<<'\n';
	Q->printthelist(dumdata);
	cout<<'\n';

	cout<<"we DeQued "<<Q->DQu()<<'\n';

	cout<<'\n';
	Q->printthelist(dumdata);
	cout<<'\n';

	cout<<Q->isEmpty()<<'\n';

	cout<<'\n';
}