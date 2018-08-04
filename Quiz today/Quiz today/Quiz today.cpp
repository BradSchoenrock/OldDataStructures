// Count The Lines.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int numcount=0;// number of numbers in the overall list



int main(int argc, _TCHAR* argv[])
{
	ifstream infile("Numbers.txt");
	ofstream outfile("answers.txt");
	if(infile.fail())//checks to see if dictionary.txt exists
	{
		cout<<"File Not Found\n";
		exit(1);
	}
	else
	{
		char letter;//holds the letter we are at
		//char word[100];// this holds the letters that compose the word
		double nums[100];//holds all the numbers in the list
		
		int length=0;
		double total=0;
		
		//while (!infile.eof())

	
		while (!infile.eof()) 
		{ 
			double x;
			infile >> x;
			//letter=infile.get();
			//cout<<x<<'\n';
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
			//outfile<<nums[g]<<'\n';
			
		}

		cout<<"the max number is "<<h<<'\n';
		cout<<"the total is "<<total<<'\n';




		//begin sorting
		double large=-9999;//holds the largest value
		while(numcount>0)
		{
			int j=0;
			for(int g=0;g<numcount+1;g++)
			{
				//cout<<nums[g]<<'\n';
				if (nums[g]>large)
					
				{
					large=nums[g];
					j=g;
				}
				//tot+=nums[g];
				
				
			}
			//print as sorted
			nums[j]=nums[numcount];
			nums[numcount]=large;
			outfile<<nums[numcount]<<'\n';
			numcount--;
			large=-9999;

		}





	}
}
