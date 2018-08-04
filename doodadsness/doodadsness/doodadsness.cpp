#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std; 


double f(double x)
{
	return x*x*x-x*x;
}

int main(int argc, char *argv[]) 
{ 
	double lo=0;
	double hi=50000;
	double guess;
	while((hi-lo)>0.000000001)
	{
		guess=(hi-lo)/2;
		if((guess*guess-4)<0)
			lo=guess;
		else if((guess*guess-4)>0)
			hi=guess;
		cout<<guess<<'\n';
	}
	cout<<guess<<'\n';
} 

