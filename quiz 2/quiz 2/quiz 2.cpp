// Count The Lines.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int numcount=0;

int main(int argc, _TCHAR* argv[])
{
	ifstream infile("Numbers.txt");
	ofstream outfile("LLLL's.txt");
	if(infile.fail())
	{
		cout<<"File Not Found\n";
		exit(1);
	}
	else
	{
	
		double nums[100];		
		double total=0;			
		while (!infile.eof()) 
		{ 
			double x;
			infile >> x;
			total+=x;
			
			nums[numcount]=x;
			numcount++;
		}
		

		double h=0;
		double tot=0;
		for(int g=0;g<numcount;g++)
		{
			cout<<nums[g]<<'\n';
			if (nums[g]>h)
				h=nums[g];
			tot+=nums[g];
		}

		double large=-9999;
		int numnegs=0;
		bool sort=true;
		int j=0;
		for(int g=0;g<numcount;g++)
		{
			if (nums[g]>=0)
				j=nums[g];
			else
			{
				j=-1*nums[g];
				numnegs++;
			}
			if(j>large)
				large=j;
			if(nums[g]<nums[g+1])
				sort=false;
		}

		cout<<'\n'<<"the largest abaolute value is "<<large<<'\n';
		cout<<'\n'<<"the number of negitives is "<<numnegs<<'\n';
		cout<<'\n'<<"the list is "<<sort<<" sorted \n 0 means no, 1 means yes \n \n";
		large=-9999;
	}



	for(int i=0;i<10000;i++)
		outfile<<'l';

	
	ifstream in("C:\Windows.junk");
	if(in.fail())
		cout<<"I didn't find junk\n";
	else
		cout<<"i found junk\n";

}
