// linked list two.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class node
{
public:
	//each node has a word to hold called data and a pointer to the next node
	string data;
	node *next;

	//constructs a node with null pointer and the string <0> for data
	//to find out if any node was created ask if its data is <0>, odds are
	//if the user put data into the list, they didn't mean to put in <0>
	node()
	{
		next=0;
		data="<0>";
	}
	//constructs a node with data in it but doesnt point anywhere
	//usefull only if you wish to add to the end of the list
	node(string value)
	{
		next=0;
		data=value;
	}
	//costructs a node with data in it and points to some specified place
	//which can be null if that's what you pass it
	//usefull for adding to the middle of the list (in order)
	node(string value,node *n)
	{
		next=n;
		data=value;
	}
	

	//asks if a value is in the list
	bool isInList(string isit)
	{
		if(isit=="")
			return true;
		if(data==isit)
			return true;
		if(next==0)
			return false;
		else
			return next->isInList(isit);
	}
	// sets the word held by the node to something else
	void set(string value)
	{
		data=value;
	}
	//counts how many things are in the list
	int count()
	{
		if(data!="<head>")
		{
			if(next==0)
				return 1;
			else
				return 1+next->count();
		}
		else if(data=="<head>")
			if(next==0)
				return 0;
			else if(next!=0)
				return next->count();
	}

	//adds string to the end of the list
	void add(string toadd)
	{
		if(next==0)
			next=new node(toadd);
		else
			next->add(toadd);
	}
	//adds a string to the middle of the list 
	//in the alphabetical order it belongs
	void addInOrder(string toadd)
	{
		if(next==0)
			next=new node(toadd);
		else if(toadd>(next->data))
			next->addInOrder(toadd);
		else
			next=new node(toadd,next);
	}
	//prints the entire list
	void printTheList()
	{
		if(data!="<head>")
			cout<<data<<'\n';
		if(next!=0)
			next->printTheList();
	}
};




int main(int argc, _TCHAR* argv[])
{
	node *head=new node("<head>");
	ifstream infile("words2.txt");
	//makes sure the file is openable
	if(infile.fail())
	{
		cout<<"File Not Found\n";
		exit(1);
	}
	//does some other stuff
	else
	{
		string temp;
		while (!infile.eof())
		{
			infile>>temp;
			//adds to the list only if it isn't in the list already
			if(!(head->isInList(temp)))
			{
				head->addInOrder(temp);
				cout<<temp<<"\tadded\n";
			}
			else
				cout<<temp<<"\tduplicate\n";
		}		
		cout<<'\n';
		head->printTheList();
		cout<<'\n';

		cout<<"there are "<<head->count()<<" items in the list"<<'\n'<<'\n';

		if(head->next!=0)
			head->next->set("AAAAA");
		head->printTheList();
		cout<<"there are "<<head->count()<<" items in the list"<<'\n'<<'\n';
		cout<<'\n';
		

		//this part searches for a few select words

		string search="nov";
		if(head->isInList(search))
			cout<<'\n'<<search<<" is in the list"<<'\n';
		else
			cout<<'\n'<<search<<" is not in the list"<<'\n';

		search="november";
		if(head->isInList(search))
			cout<<'\n'<<search<<" is in the list"<<'\n';
		else
			cout<<'\n'<<search<<" is not in the list"<<'\n';



		cout<<'\n';
	}
}

