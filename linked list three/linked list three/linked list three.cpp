// linked list two.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

class node
{
public:
	//each node has an int to hold called data and a pointer to the next node
	int data;
	node *next;

	//constructs a node with null pointer and the int -9876 for data
	//to find out if any node was created ask if its data is -9876, because
	//all data in the list is positive this will not be a problem
	//this is the only way to get a value of -1 for data
	node()
	{
		next=0;
		data=-1;
	}
	//constructs a node with data in it but doesnt point anywhere
	//usefull only if you wish to add to the end of the list
	//used for making the head node
	
	node(int value)
	{
		next=0;
		data=value;
	}

	//costructs a node with data in it and points to some specified place
	//which can be null if that's what you pass it
	//usefull for adding to the middle of the list (in order)
	node(int value,node *n)
	{
		next=n;
		data=value;

		string mash="yes...";
		string awesome="yes...";
		assert(mash==awesome);
	}
	

	//asks if a value is in the list
	bool isInList(int isit)
	{
		assert(isit>-1);
		if(data==isit)
		{
			assert(data>-1);
			return true;
		}
		if(next==0)
		{
			assert(data!=isit);
			return false;
		}
		else
		{
			assert(next!=0);
			return next->isInList(isit);
		}
	}

	//counts how many things are in the list
	int count()
	{
		assert(data!=-1);
		if(data!=-9876)
		{
			if(next==0)
			{
				assert(data!=-1);
				return 1;
			}
			else
			{
				assert(next->count()>0);
				return 1+next->count();
			}
		}
		else if(data==-9876)
		{
			if(next==0)
			{
				assert(data!=0);
				return 0;
			}
			else if(next!=0)
			{
				assert(next->count()>0);
				return next->count();
			}
		}
	}

	void addInOrder(int toadd)
	{
		assert(toadd>-1);
		if(next==0)
		{
			next=new node(toadd);
			cout << "Item " << toadd << " added.\n"; 
			assert(next!=0);
			return;
		}
		if(next->data==toadd)
		{
			cout << "Item " << toadd << " already added.\n";
			assert(next->data>-1);
			return;
		}
	
		else if(toadd>(next->data))
		{
			next->addInOrder(toadd); 
			assert(next->data>-1);
			return;
		}
		else if(toadd<(next->data))
		{
			next=new node(toadd,next);
			cout << "Item " << toadd << " added.\n";
			assert(next->data>-1);
			return;
		}
	}
	//prints the entire list
//	void printTheList()
//	{
//		if(data!=-9876)
//			cout<<data<<'\n';
//		if(next!=0)
//			next->printTheList();
//	}

	void del(int todel)
	{
		assert(todel!=-9876);
		if(next==0)
		{
			cout << "Item " << todel << " already deleted.\n"; 
			assert(data!=todel);
			return;
		}
		if(next->data>todel)
		{
			cout << "Item " << todel << " already deleted.\n"; 
			assert(next->data!=todel);
			return;
		}
		if(next->data==todel)
		{
			node *tmp=next;
			//tmp=next;
			next=next->next;
			delete tmp;
			cout << "Item " << todel << " deleted.\n"; 
			assert(data!=todel);
			return;
		}
		assert(next->data<todel);
		next->del(todel);
	}

	int find()
	{
		if(data==-9876)
			if(next!=0)
				if(next->next!=0)
					if(next->next->next!=0)
						return next->find();
					else
						return data;
				else
					return data;
			else 
				return data;
		else
			if(next->next->next!=0)
				return next->find();
			else 
				return data;

	}
//	int find(int count)
//	{
//		if count > 0 && next != 0)
//			next->find(count-1)
//		else
//			return data;
};




int main(int argc, _TCHAR* argv[])
{
	node *head=new node(-9876);


	const int SIZE = 1000; 
	int item; 
	char command; 

	while (cin >> command >> item) 
	{ 
		if (command == 'a') 
			head->addInOrder(item); 
		else if (command == 'd') 
			head->del(item);
	} 

	
	int trip=head->find();
	cout<<"the third from the end is "<<trip<<'\n';
}