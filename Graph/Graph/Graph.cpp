// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Node.cpp"
#include "templated linked list.cpp"
#include "Que.cpp"
#include "Stack.cpp"
using namespace std;

class Graph
{
	LinkedList<int> ** myArray;
	int numnodes;
	int numedges;
public:
	Graph(int n/*number of nodes*/,int** edges,int e/*number of edges*/)
	{
		if(n>0)
		{
			myArray=new LinkedList<int> *[n];
			
			for(int t=0;t<n;t++)
			{
				myArray[t]=new LinkedList<int>(-987654321);
			}
			
			for(int y=0;y<e;y++)
			{
				myArray[edges[y][0]]->addInOrder(edges[y][1]);
				myArray[edges[y][1]]->addInOrder(edges[y][0]);
			}
		}
		numnodes=n;
		numedges=e;
	}

	int *bfs(int start, int& sl)
	{
		if(numnodes>0)
		{
			int *visited=new int[numnodes];
			sl=0;
			Que<int> *q=new Que<int>(-98765);
			q->Qu(start);
			bool *reached=new bool[numnodes];
			for(int h=0;h<numnodes;h++)
				reached[h]=false;

			while(!(q->isEmpty()))
			{
				if(!reached[q->head->next->data])
				{
					visited[sl]=q->DQu();
					start=visited[sl];
					reached[start]=true;
					int kk=0; // kk will be the number of conections of start because toArray method takes it as pass by reference	
					int *anArray=new int[];//anArray is a temporary array that holds the connections of start
					anArray=myArray[start]->toArray(kk);
					for(int now=0;now<kk;now++) // i needed a temperary variable now so i called it now
					{
						//if(anArray[now] /*isn't in visited*/ )
						q->Qu(anArray[now]);
					}
					delete anArray;
					sl++;
				}
				else
					q->DQu();
			}
			return visited;
		}
		else
			return 0;

		
	}
	int *dfs(int start, int& sl)
	{
		if(numnodes>0)
		{
			sl=0;
			int *visited=new int[numnodes];
			Stack<int> *stak=new Stack<int>(-98765);
			stak->push(start);
			bool *reached=new bool[numnodes];
			for(int h=0;h<numnodes;h++)
				reached[h]=false;

			while(!(stak->isEmpty()))
			{
				if(!reached[stak->head->next->data])
				{
					visited[sl]=stak->pop();
					start=visited[sl];
					reached[start]=true;
					int kk=0; // kk will be the number of conections of start because toArray method takes it as pass by reference	
					int *anArray=new int[];//anArray is a temporary array that holds the connections of start
					anArray=myArray[start]->toArray(kk);
					for(int now=0;now<kk;now++) // i needed a temperary variable now so i called it now
					{
						//if(anArray[now] /*isn't in visited*/ )
						stak->push(anArray[now]);
					}
					delete anArray;
					sl++;
				}
				else
					stak->pop();
			}
			return visited;
		}
		else
			return 0;
	}

	void print()
	{
		if(numnodes>0)
		{
			for(int z=0;z<numnodes;z++)
			{
				cout<<"the neighbors of vertex "<<z<<" : ";
				myArray[z]->printTheList();
				cout<<'\n';
			}
		}

	
	}


};

void main() 

{
	const int nn=10; //number of nodes in my test graph
	const int ne=10; //number of connections must be greater than 0!
	const int start=1;

	int** edges = new int*[ne];

	for(int i = 0; i < ne; i++) 
	{
		edges[i] = new int[2];
		if(nn>0)
		{
			edges[i][0]=rand()%nn;
			edges[i][1]=rand()%nn;
		}
	}
//	edges[0][0] = 2;
//	edges[0][1] = 3;
//	edges[1][0] = 3;
//	edges[1][1] = 1;
//	edges[2][0] = 1;
//	edges[2][1] = 0;
//	edges[3][0] = 3;
//	edges[3][1] = 7;

	Graph g = Graph(nn, edges, ne); //testing graph constructor
	g.print(); //testing graph print method

	cout<<'\n';

	//Testing depth first search.
	int searchLength;
	int* search = g.dfs(start, searchLength);
	for(int i = 0; i < searchLength; i++) 
	{
		cout << search[i] << endl;
	}
	delete [] search;
	cout << endl;

	//Testing breadth first search.
	search = g.bfs(start, searchLength);
	for(int i = 0; i < searchLength; i++) 
	{
		cout << search[i] << endl;
	}
	delete [] search;
	cout << endl;



	//Testing the toArray method
	LinkedList<int> list;
	list.addFront(3);
	list.addFront(1);
	list.addFront(5);
	list.addFront(9);
	list.remove(5);
	list.remove(1);

	int aLength;
	int* a = list.toArray(aLength);
	for(int i = 0; i < aLength; i++) 
	{
		cout << a[i] << endl;
	}
	delete [] a;
}