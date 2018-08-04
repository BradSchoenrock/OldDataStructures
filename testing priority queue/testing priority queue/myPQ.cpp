// Priority Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

template <typename zeek,typename dodge>
class Heap
{
public:
	zeek *data;
	dodge *priority;
	int howmany;
	int size;
	
	Heap()
	{
		size=8;
		data=new zeek[size];
		priority=new dodge[size];
		howmany=0;
	}
	Heap(zeek toadd[],dodge pr[],int size1,int size2)
	{
		howmany=0;
		size=8;
		data=new zeek[size];
		priority=new dodge[size];
		assert(size1=size2);
		buildheap(toadd,pr,size1,size2);
	}
	
private:

	void grow()
	{
		zeek *temp=data;
		zeek *tempy=new zeek[size*2];
		for(int q=0;q<size;q++)
		{
			tempy[q]=data[q];
		}
		data=tempy;
		delete temp;

		dodge *t=priority;
		dodge *tempz=new dodge[size*2];
		for(int q=0;q<size;q++)
		{
			tempz[q]=priority[q];
		}
		priority=tempz;
		delete t;

		size=size*2;
		//cout<<"I Grew! "<<'\n'<<'\n';
	}
	void shrink()
	{
		zeek *temp=data;
		zeek *tempy=new zeek[size/2];
		for(int q=0;q<size/2;q++)
		{
			tempy[q]=data[q];
		}
		data=tempy;
		delete temp;

		dodge *t=priority;
		dodge *tempz=new dodge[size/2];
		for(int q=0;q<size/2;q++)
		{
			tempz[q]=priority[q];
		}
		priority=tempz;
		delete t;

		size=size/2;

		//cout<<"I shrunk! "<<'\n'<<'\n';
	}

	void heapify(int index)
	{
		if((index+1)*2<howmany)//if it has two "leafs"
		{
			if(priority[index]>priority[index*2+1]||priority[index]>priority[index*2+2])
			{
				if(priority[index*2+1]<priority[index*2+2])
				{
					zeek temp=data[index];
					data[index]=data[index*2+1];
					data[index*2+1]=temp;
					
					dodge tempy=priority[index];
					priority[index]=priority[index*2+1];
					priority[index*2+1]=tempy;
						
					heapify(index*2+1);
				}
				else
				{
					zeek temp=data[index];
					data[index]=data[index*2+2];
					data[index*2+2]=temp;
						
					dodge tempy=priority[index];
					priority[index]=priority[index*2+2];
					priority[index*2+2]=tempy;
						
					heapify(index*2+2);
				}
			}
		}
		if((index+1)*2==howmany)//if there is only one "leaf"
		{
			if(priority[index]>priority[index*2+1])
			{
				zeek temp=data[index];
				data[index]=data[index*2+1];
				data[index*2+1]=temp;
				
				dodge tempy=priority[index];
				priority[index]=priority[index*2+1];
				priority[index*2+1]=tempy;
			}
		}
	}

	void reverseheapify(int index)
	{
		if(priority[(index-1)/2]>priority[index])
		{
			zeek temp=data[index];
			data[index]=data[(index-1)/2];
			data[(index-1)/2]=temp;
			
			dodge tempy=priority[index];
			priority[index]=priority[(index-1)/2];
			priority[(index-1)/2]=tempy;

			reverseheapify((index-1)/2);
		}
	}
public:

	zeek findmin()
	{
		return data[0];
	}
	zeek findminpriority()
	{
		return priority[0];
	}


	void deletemin()
	{
		if(howmany==0)
			return;
		data[0]=data[howmany];
		priority[0]=priority[--howmany];
		heapify(0);
		if(size>4&&4*howmany<size)//i don't want it to be smaller than 4 ever
			shrink();
	}


	void heigtenpriority(zeek tohighten,dodge newpr)//reassigns the first instance of an identifier ***O(n*lgn)***
	{									//newpr means new priority
		for(int k=0;k<howmany;k++)
			if(data[k]==tohighten)
			{
				priority[k]=newpr;
				reverseheapify(k);
				break;
			}
	}

	void buildheap(zeek toadd[],dodge pr[],int size1,int size2)// *** O(n*lgn) ***
	{
		assert(size1==size2);
		int temps=howmany;
		for(int k=howmany;k<size1+temps;k++)
		{
			insert(toadd[k],pr[k]);
		}
	}

	void insert(zeek toadd,dodge pr)//pr is for priority
	{
		if(howmany==size)
		{
			grow();
		}
		data[howmany]=toadd;
		priority[howmany]=pr;
		reverseheapify(howmany++);

	}

	void printheap()
	{
		for(int y=0;y<howmany;y++)
		{
			cout<<data[y]<<" and "<<priority[y]<<'\n';
		}
		cout<<'\n';
	
	}




};
