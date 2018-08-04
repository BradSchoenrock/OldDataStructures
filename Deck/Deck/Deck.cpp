// Deck.cpp : Defines the entry point for the console application.
//


//this program will not match Dr. Appleton's output if an attempt to pop is made when 
//there is nothing in the list

//this program doesn't ever shrink the array


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

class Deck
{
public:
	int *head; //this is the front of the data in the array
	int *tail; //this is the back of the data in the array
	// these should always be within the range from deck to deck+size
	int size; // size of the array created in Deck()
	int *deck; //this is the fron of the array

	Deck()
	{
		size=2;
		deck=new int [size];
		head=deck;
		tail=deck;
	}
	void addFront(int item)//adds to the front of the deque
	{
		assert(tail>=deck);			// these asserts ensure that my head and tail are both
		assert(tail<=deck+size);	// within the boundry of the array and havn't strayed
		assert(head>=deck);			// these asserts are used repeadely
		assert(head<=deck+size);

		if((head-tail+size)%size==1)
		{
			grow();

			assert(head>=deck);
			assert(head<=deck+size);
			assert(tail>=deck);
			assert(tail<=deck+size);

			head=(deck+size-1);
			*head=item;
		}
		else if(head==deck)
		{
			head=deck+size-1;
			*head=item;
		}
		else
		{
			head--;
			*head=item;
		}

	}
	void addBack(int item)//adds to the back of the deque
	{
		assert(tail>=deck);
		assert(tail<=deck+size);
		assert(head>=deck);
		assert(head<=deck+size);

		if((head-tail+size)%size==1)
		{
			grow();

			assert(tail>=deck);
			assert(tail<=deck+size);
			assert(head>=deck);
			assert(head<=deck+size);

			*tail=item;
			tail++;
		}
		else if(tail==deck+size-1)
		{
			*tail=item;
			tail=deck;
		}
		else
		{
			*tail=item;
			tail++;
		}

	}

	int popFront()//removes the front part of the deque
	{
		assert(tail>=deck);
		assert(tail<=deck+size);
		assert(head>=deck);
		assert(head<=deck+size);

		if(head!=tail&&head!=(deck+size-1))
			return *head++;
		if(head==(deck+size-1))
		{
			head=deck;
			return *(deck+size-1);
		}
		else
			return -1234;
	}

	int popBack()//removes the back part of the deque
	{
		assert(tail>=deck);
		assert(tail<=deck+size);
		assert(head>=deck);
		assert(head<=deck+size);
		
		if(head!=tail&&tail!=deck)
			return *(--tail);
		if(tail==deck)
		{
			tail=deck+size-1;
			return *tail;
		}
		else
			return -1234;
	}

	bool contains(int item)//asks if the list contains item
	{
		
		if(head==tail)
			return false;
		int *temp;
		if(head<tail)
		{
			temp=head;
			while(temp<tail)
				if(*temp==item)
					return true;
				else
					temp++;
		}
		else
		{
			temp=deck;
			while(temp<tail)
				if(*temp==item)
					return true;
				else
					temp++;
			temp=head;
			while(temp<deck+size)
				if(*temp==item)
					return true;
				else
					temp++;
		}
		return false;
	}

	int count()
	{
		return ((tail-head+size)%size);
	}


	void grow()//makes the array bigger
	{
		int *temp=deck; //keeping a pointer to the current array
		int *newdeck;//the new array stuff
		int *newhead;
		int *newtail;

		newdeck=new int [size*2];
		newtail=newdeck;

		while(head!=tail)
		{
			*newtail=*head;
			newtail++;
			if(head==deck+size-1)
			{
				head=deck;
			}
			else
			{
				head++;
			}

		}

		head=newdeck;
		tail=newtail;

		delete temp;
		//int *deck;
		deck=newdeck;
		size=size*2;
		//cout<<"I GREW! \n";
	}

	void printall()//prints the entire array for debugging purposes
	{
		for(int i=0;i<size;i++)
			cout<<deck[i]<<'\n';
	}
};

int main() 
{
	int item;
	char command;
	Deck d;
	cout << "Remember:\n a == addFront\nb == addBack\nc == popFront\nd == popBack\ne == contains\n";
	while (!cin.eof()) 
	{
		cin >> command >> item;
		if (command == 'a') 
			d.addFront(item);
		else if (command == 'b') 
			d.addBack(item);
		else if (command == 'c') 
			cout << "Pop front " << d.popFront() << endl;
		else if (command == 'd') 
			cout << "Pop back " << d.popBack() << endl;
		else if (command == 'e')
			if (d.contains(item))
				cout << "Item " << item  << " found.\n";
			else
				cout << "Item " << item << " not found.\n";
		//cout << "There are " << d.count() << " items\n";
		//cout <<'\n';
		//d.printall();
		//cout <<'\n';
	}
}