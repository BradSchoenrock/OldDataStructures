// templated linked list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<typename zeek>
class LinkedList
{
public:
	Node<zeek>* head;
	Node<zeek> *tail;
	int numitems;
	bool sorted;

	LinkedList()
	{
		head=new Node<zeek>();
		tail=head;
		numitems=0;
		sorted=true;
	}
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



	zeek* toArray(int &i)// if count() is zero you get funky results as should be expected
	{
		i=numitems;

		zeek *arr=new zeek[numitems];
		Node <zeek>*temp=head->next;
		for(int k=0;k<numitems;k++)
		{
			arr[k]=temp->data;
			temp=temp->next;
		}
		return arr;
	}



};

/*
int main(int argc, _TCHAR* argv[])
{
	double dumdata=-9.87654321;
	int listlength=-9;
	LinkedList<double> *LL=new LinkedList<double>(dumdata);

	cout<<LL->toArray(listlength)[0]<<'\n';// if count() is zero you get funky results as should be expected
	cout<<"the list length is "<<listlength<<'\n';
	
	double toremove=2.3;
	double seek=8.9;

	LL->addBack(1.2);
	LL->addInOrder(2.3);
	LL->addFront(3.4);
	LL->addBack(5.6);
	LL->addInOrder(4.5);
	LL->addInOrder(6.7);
	LL->addBack(8.9);
	LL->addBack(7.8);

	cout<<'\n'<<"here's the list"<<'\n'<<'\n';
	LL->printTheList();
	cout<<'\n';
	cout<<"there are "<<LL->count()<<" items in the list"<<'\n'<<'\n';
	cout<<"the tail->data is "<<LL->tail->data<<'\n';
	
	cout<<'\n'<<"now i attempt to remove "<<toremove<<" from the list "<<'\n';
	LL->remove(toremove);

	cout<<'\n';
	LL->printTheList();
	cout<<'\n';
	cout<<"there are "<<LL->count()<<" items in the list"<<'\n'<<'\n';
	cout<<"the tail->data is "<<LL->tail->data<<'\n';

	cout<<'\n'<<"now i sort the list "<<'\n';
	LL->bubbleSort();

	cout<<'\n';
	LL->printTheList();
	cout<<'\n';
	cout<<"there are "<<LL->count()<<" items in the list"<<'\n'<<'\n';
	cout<<"the tail->data is "<<LL->tail->data<<'\n';

	
	if(LL->search(seek))
		cout<<'\n'<<seek<<" is in the list"<<'\n';
	else
		cout<<'\n'<<seek<<" is not in the list"<<'\n';

	if (LL->sorted)
		cout<<'\n'<<"the list is sorted"<<'\n';
	else
		cout<<'\n'<<"the list is not sorted"<<'\n';

	cout << '\n';


	double *temp=LL->toArray(listlength);

	cout<<"the list length is "<<listlength<<'\n';
	cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<" "<<temp[3]<<" "<<temp[4]<<" "<<temp[5]<<" "<<temp[6]<<'\n';

}

*/