// Count The Lines.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	ifstream infile("Count The Lines.cpp");
	ofstream outfile("CountLines.cpp");
	if(infile.fail())
	{
		cout<<"File Not Found\n";
		exit(1);
	}
	else
	{
		int n=1;
		while(!infile.eof())
		{
			char letter;
			letter=infile.get();
			if (outfile.is_open())
				outfile<<letter;
			if(letter=='\n')
				n++;
		}
		outfile.close();
		cout<<n<<'\n';
	}
}�