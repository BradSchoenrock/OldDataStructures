// Sieve_of_Erathmuseus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	const int howmany=1000;
	int poss[howmany];
	
	int n=0;
	while(n<howmany)
	{
		poss[n]=n++;
	}


	for(int k=2;k<howmany;k++)
		if(poss[k]>0)
			for(int f=k+k;f<howmany;f=f+k)
				poss[f]=-1;


	for(int i=2;i<howmany;i++)
	{
		if(poss[i]>0)
			cout<<poss[i]<<"\n";
	}
}

