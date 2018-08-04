// linked list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class node
{
public:

	int data;
	node *next;

	//different arguments will allow different constructers with same names
	node()
	{
		next=0;
		data=0;
	}
	//constructer needs no return type
	node(int value)
	{
		next=0;
		data=value;
	}
	//method must have a return type
	void set(int value)
	{
		data=value;
	}

//	bool hasloop(int target)
//	{
//		for(node *ptr=this)
//			if(target==data)
//				return true;
//		return false;
//	}


	int count()
	{
		if(next==0)
			return 1;
		else
			return 1+next->count();
	}
	int sum()
	{
		if(next==0)
			return data;
		else
			return data+next->sum();
	}
	int countpos()
	{
		if(next==0)
			if(data>0)
				return 1;
			else 
				return 0;
		else
			if(data>0)
				return 1+next->countpos();
			else
				return next->countpos();
	}


	bool find(int target)
	{
		if(data==target)
			return true;
		if(next==0)
			return 0;
		return next->find(target);
	}
	double max()
	{
		if(next==0)
			return data;
		else 
			//double tmp=next->max();
			if(next->max()>data)
				return next->max();
		return data;
			
	}

};

int main(int argc, _TCHAR* argv[])
{
	node *head=new node();
	//head->data=-4;
	//head->set(78);
	head->next = new node(14);
	head->next->next=new node(3);
	head->next->next->next=new node(-3);
	head->next->next->next->next=new node(13);
	head->next->next->next->next->next=new node(42);

	
	for(node *ptr=head;ptr!=0;ptr=ptr->next)
		if(ptr!=head)
		cout<<ptr->data <<endl;

	//cout<<head->data<<endl;
	//cout<<head->next->data<<endl;

	node *temp=head;
	head=head->next;
	delete temp;

	cout<<'\n'<<"the count of the list is "<<head->count()<<'\n';
	cout<<'\n'<<"the sum of the list is "<<head->sum()<<'\n';
	cout<<'\n'<<"the count of the positives is "<<head->countpos()<<'\n';

	if(head->find(83))
		cout<<'\n'<<"i found it "<<'\n';
	else
		cout<<'\n'<<"i didn't find it "<<'\n';
	//if (head->contrains(aword))
	
	//cout<<'\n'<<count<<'\n';
}

