// Count The Lines.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string allwords[100000]; //holds the words
int wordlen[100000];//holds the length of each word
string allpals[100000];//holds just the palandromes
int pallen[100000];//holds the length of the palandrome in that position

bool palandromity(string st,int length)//checks for palandromeness
{
	if(st[0]<='Z')
	{
		for(int n=0;n<=length/2;n++)
		{
			if(tolower(st[n])!=tolower(st[length-n-1]))
				return false;
		}
		return true;
	}

}

int main(int argc, _TCHAR* argv[])
{
	ifstream infile("dictionary.txt");
	if(infile.fail())//checks to see if dictionary.txt exists
	{
		cout<<"File Not Found\n";
		exit(1);
	}
	else
	{
		char letter;//holds the letter we are at
		char word[100];// this holds the letters that compose the word
		int palandromes=0; // holds the number of palandromes
		int wordcount=0;// number of words in the overall list
		int length=0;//length of word in question we are working with

		string worded;
	
		while (!infile.eof()) 
		{ 			
				getline(infile,allwords[wordcount]);
				wordlen[wordcount]=allwords[wordcount].length();
				wordcount++;
		}
		

		for(int g=0;g<wordcount;g++)//moves the word to allpals if it is a palandrome and saves it's length
		{
			if(palandromity(allwords[g],wordlen[g]))
			{
				allpals[palandromes]=allwords[g];
				pallen[palandromes]=wordlen[g];
				palandromes++;
			}
		}


		int maxpallen=0;//holds the length of the longest palandrome
		for(int q=0;q<palandromes;q++)//prints out all palandromes in alphabetical order and finds maxpallen
		{
			cout<<allpals[q]<<'\n';
			if(pallen[q]>maxpallen)
				maxpallen=pallen[q];
		}

		cout<<'\n'<<'\n';
		for(int s=1;s<=maxpallen;s++)//prints out all palandromes in order of length
		{
			for(int r=0;r<palandromes;r++)
				if(pallen[r]==s)
				{
					cout<<allpals[r]<<'\n';
				}
		}
		cout<<'\n';
		cout<<"the longest palandrome is of length "<<maxpallen<<'\n'<<'\n';
		cout<<"the number of words read was "<<wordcount<<'\n';
		cout<<"the number of palandromes in that list is "<<palandromes<<'\n';
	}
}
