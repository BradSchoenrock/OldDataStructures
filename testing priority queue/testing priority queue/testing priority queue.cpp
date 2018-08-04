// testing priority queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myPQ.cpp"
#include "LinkedList.cpp"



int main()
{
	// the heap uses doubles as data and ints as priorities
	Heap<double,int> *PQ=new Heap <double,int>();
	LinkedList<int> *LL=new LinkedList<int>(-987654321);
	
	
	
	for(int u=0; u<500000; u++)
	{
		int ap=(int)(rand()%2);
		//cout<<ap<<'\n';
		if(LL->numitems>0&&ap==0)//i make sure you don't remove when there is nothing to remove from the list
		{
			//cout<<"romove"<<'\n';
			if(PQ->findminpriority()!=LL->getHead())
				cout<<"oops"<<'\n';
			PQ->deletemin();
			LL->remove(LL->getHead());
		}
		else
		{
			//cout<<"add"<<'\n';
			int toadd=(int)rand();
			PQ->insert(abs(rand()),toadd);
			LL->addInOrder(toadd);
		}
		

		//PQ->printheap();
		//LL->printTheList();
		//cout<<'\n';
		//cout<<'\n';

	}
}

