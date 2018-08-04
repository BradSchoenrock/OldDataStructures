// linkedlist.cpp : Defines the entry point for the console application.
//
// Add add them up
// insert at end
// count them
// count the positives

#include "stdafx.h"
#include <iostream>
using namespace std;

class node 
{
  public:
	  node(double item) 
	  {
		  next = 0;
		  data = item;
	  }
	  double data;
	  node *next;

	  bool has(double isit)
	{
		if(data==isit)
			return true;
		if(next==0)
			return false;
		else
			return next->has(isit);
	}


	  void addlast(double toadd)
	  {
		if(next==0)
			next=new node(toadd);
		else
			next->addlast(toadd);
	  }

	  int count(double num)
	{
		if(data==num)
		{
			if(next==0)
				return 1;
			else
				return 1+next->count(num);
		}

		else
		{
			if(next==0)
				return 0;
			else
				return next->count(num);
		}
	}

	  bool isInOrder()
	  {
		if(next==0)
			return true;
		else if(next->data>data)
			return next->isInOrder();
	  }

};




int main(int argc, _TCHAR* argv[])
{
	// Make the list
	node *head = new node(2);
	head->next = new node(3);
	head->next->next = new node(4);
	head->next->next->next = new node(5);
	head->next->next->next->next = new node(6);
	head->next->next->next->next->next = new node(2);


	//
	// POINT!
	// Write a method for the node that searches
	// the list.  Make this code below work.
	//
	if (head->has(6))
		cout << "There is a 6 in the list\n";
	else
		cout << "You got this wrong\n";
	cout<<'\n';


	//
	// POINT!
	// Write a method for the node that says if the list is in order
	// Make this code below work.
	//
	if (head->isInOrder())
		cout << "You got this wrong.\n";
	else
		cout << "The list is not in order.\n";
	cout<<'\n';


	//
	// POINT!
	// Write me a method counts the number of items found in the list.
	// Make this code below work.
	//
	 int count = head->count(2);
	 cout << "You said " << count << ". You should have said 2.\n";
	 cout<<'\n';



	//
	// POINT
	// Insert a 1 at the begining of the list
	//

	 node *newhead = new node(1);
	 newhead->next=head;
	 head=newhead;
	

	// Print the list
	cout << "Should print 1 2 3 4 5 6 2\n";
	for(node *ptr = head; ptr != 0; ptr=ptr->next)
		cout << ptr -> data << " ";
	cout << '\n';
	cout<<'\n';


	//
	// POINT
	// Write me code that adds a 11 to the end of the list.
	// You may not go "next->next->next->next->next ... etc".
	// Instead you must use a loop or recursion.
	//
	head->addlast(11);


	// Print the list
	cout << "Should print 1 2 3 4 5 6 2 11\n";
	for(node *ptr = head; ptr != 0; ptr=ptr->next)
		cout << ptr -> data << " ";
	cout << '\n'<<'\n';


	
}



