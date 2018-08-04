// linked list two.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool sorted;
int numitems;

class Node
{
public:
	//each node has a word to hold called data and a pointer to the next node
	int data;
	Node *next;

	//constructs a node with null pointer and null data
	Node()
	{
		next=0;
		data=0;
	}
	//constructs a node with data in it but doesnt point anywhere
	Node(int value)
	{
		next=0;
		data=value;
	}
	//costructs a node with data in it and points to some specified place
	//which can be null if that's what you pass it
	//usefull for adding to the middle of the list (in order)
	Node(int value,Node *n)
	{
		next=n;
		data=value;
	}

	bool search(int isit)
	{
		if(data==isit)
			return true;
		if(next==0)
			return false;
		else
			return next->search(isit);
	}
	
	int count(int n)
	{
		return n;
	}
	//all these methods return a Node* tail to readjust my tail pointer
	Node* addback(int toadd,Node *t)
	{
		sorted=false;
		numitems++;
		return t->next=new Node(toadd);
	}

	Node* addfront(int toadd,Node *t)
	{
		if(next==0)
			return next=new Node(toadd);
		else
			next=new Node(toadd,next);
			return t;
	}

	Node* addInOrder(int toadd,Node *t)
	{
		if (!sorted)
			return addback(toadd,t);
		if(next==0)
		{
			numitems++;
			return next=new Node(toadd);
		}
		if(toadd<=(next->data))
		{
			next=new Node(toadd,next);
			numitems++;
			return t;
		}
		if(toadd>(next->data))
		{
			return next->addInOrder(toadd,t);
		}
	}

	void printTheList()
	{
		if(data!=-987654321)
			cout<<data<<'\n';
		if(next!=0)
			next->printTheList();
	}

	Node* remove(int togo,Node* t,Node* h)
	{
		if(next==0)
			return t;
		if(next->next==0)
		{
			if(next->data==togo)
			{
				numitems--;
				delete next;
				next=0;
				return h;
			}
			else if(next->data!=togo)
				return next;
		}
		if(next->next->next==0)
		{
			if(next->next->data==togo)
			{
				numitems--;
				delete next->next;
				next->next=0;
				return next;
			}
		}
		if(next->data==togo)
		{
			numitems--;
			Node *temp=next->next;
			next->next=0;
			delete next;
			next=temp;
			return t;
		}
		else
			return next->remove(togo,t,h);
	}

	void bubbleSort(int ni) 
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
					int temp = next->data;
					next->data = next->next->data;
					next->next->data = temp;
				}
				next->bubbleSort(ni);
			}
		}
		else
			;
		sorted=true;
	}
};

int main(int argc, _TCHAR* argv[])
{
	Node *head=new Node(-987654321);
	Node *tail=head;
	numitems=0;
	sorted=true;

	tail=head->addback(12,tail);
	tail=head->addInOrder(23,tail);
	tail=head->addfront(34,tail);
	tail=head->addback(56,tail);
	tail=head->addInOrder(45,tail);
	tail=head->addInOrder(67,tail);
	tail=head->addback(89,tail);
	tail=head->addback(78,tail);

	cout<<'\n'<<"here's the list"<<'\n'<<'\n';
	head->printTheList();
	cout<<'\n';
	cout<<"there are "<<head->count(numitems)<<" items in the list"<<'\n'<<'\n';
	cout<<"the tail->data is "<<tail->data<<'\n';
	
	cout<<'\n'<<"now i remove an element from the list "<<'\n';
	tail=head->remove(89,tail,head);

	cout<<'\n';
	head->printTheList();
	cout<<'\n';
	cout<<"there are "<<head->count(numitems)<<" items in the list"<<'\n'<<'\n';
	cout<<"the tail->data is "<<tail->data<<'\n';

	cout<<'\n'<<"now i sort the list "<<'\n';
	head->bubbleSort(numitems);

	cout<<'\n';
	head->printTheList();
	cout<<'\n';
	cout<<"there are "<<head->count(numitems)<<" items in the list"<<'\n'<<'\n';
	cout<<"the tail->data is "<<tail->data<<'\n';

	int seek=89;
	if(head->search(seek))
		cout<<'\n'<<seek<<" is in the list"<<'\n';
	else
		cout<<'\n'<<seek<<" is not in the list"<<'\n';

	if (sorted)
		cout<<'\n'<<"the list is sorted"<<'\n';
	else
		cout<<'\n'<<"the list is not sorted"<<'\n';

	cout << '\n';
}