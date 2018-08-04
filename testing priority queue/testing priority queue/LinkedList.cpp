// templated linked list.cpp : Defines the entry point for the console application.
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
	
	//all these methods return a Node* tail to readjust my tail pointer
	Node* addFront(zeek toadd,Node* t)
	{
		if(next==0)
			return next=new Node(toadd,next);
		else
			next=new Node(toadd,next);
			return t;
	}
	Node* addBack(zeek toadd,Node *t)
	{
		return t->next=new Node(toadd);
	}

	Node* addInOrder(zeek toadd,Node *t,bool sorted)
	{
		if (!sorted)
			return addBack(toadd,t);
		if(next==0)
		{
			return next=new Node(toadd);
		}
		if(toadd<=(next->data))
		{
			next=new Node(toadd,next);
			return t;
		}
		else //if(toadd>(next->data))
		{
			return next->addInOrder(toadd,t,sorted);
		}
	}

	Node* remove(zeek togo,Node* t,Node* h)
	{
		//if next==0 then this will never be called
		if(next->next==0) //next->next must be the data because it has to be somewhere 
			// by virtue that we got here so this is the only case
		{
			delete next;
			next=0;
			return h;
		}
		if(next->next->next==0)
		{
			if(next->next->data==togo)
			{
				delete next->next;
				next->next=0;
				return next;
			}
		}
		if(next->data==togo)
		{
			Node *temp=next->next;
			next->next=0;
			delete next;
			next=temp;
			return t;
		}
		else
			return next->remove(togo,t,h);
	}

	void bubbleSort(int ni,bool sorted) //ni=numitems
	{
		if(!sorted)
		{
			for(int c=ni;c>0;c--)
			{
				if(next==0)
					return;
				if(next->next==0)
					return;
				if (next->next->data < next->data) 
				{
					zeek temp = next->data;
					next->data = next->next->data;
					next->next->data = temp;
				}
				next->bubbleSort(ni,sorted);
			}
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

template<typename zeek>
class LinkedList
{
public:
	Node<zeek>* head;
	Node<zeek> *tail;
	int numitems;
	bool sorted;
	LinkedList(zeek dumdata)
	{
		head=new Node<zeek>(dumdata);
		tail=head;
		numitems=0;
		sorted=true;
	}
	bool search(zeek isit)
	{
		return head->search(isit);
	}
	int count()
	{
		return numitems;
	}
	void addFront(zeek data)
	{
		sorted=false;
		numitems++;
		tail=head->addFront(data,tail);
	}
	int getHead() 
	{
		return (numitems > 0) ? head->next->data : head->data;
	}
	void addBack(zeek data)
	{
		sorted=false;
		numitems++;
		tail=head->addBack(data,tail);
	}
	void addInOrder(zeek data)
	{
		numitems++;
		tail=head->addInOrder(data,tail,sorted);
	}
	void remove(zeek torem)
	{
		if(search(torem))
			if(torem!=head->data)
			{
				tail=head->remove(torem,tail,head);
				numitems--;
			}
	}
	void bubbleSort()
	{
		head->bubbleSort(numitems,sorted);
		sorted=true;
	}
	void printTheList()
	{
		head->printTheList(head->data);
	}



};

