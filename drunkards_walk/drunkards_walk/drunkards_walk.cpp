// drunkards_walk.cpp : Defines the entry point for the console application.
// Brad Schoenrock

#include "stdafx.h"
#include <iostream>
using namespace std;

const int startxpos=0;//x starting point
const int startypos=0;//y starting point

bool isondock(int x, int y,int docksizeb)//asks if he is on the dock
//x is his x position, y is his y position, docksizeb is how large the dock is for that itteration
{
	if(max(x,y)>(docksizeb-1)/2||min(x,y)<(-1*docksizeb/2))//checks to see if he is still on the dock
		return false;//oops he fell off
	return true;//apparantly he didn't fall off
}
int resetx()//resets him to the starting position
{
	return startxpos;//these reset his position to the starting position
}
int resety()//resets him to the starting position
{
	return startypos;//these reset his position to the starting position
}
void main()
{
	int xpos;//holds the x position of the drunkard
	int ypos;//holds the y position of the drunkard
	int docksize=1;//the initial size of the dock which will be varied by a loop

	float seconds=0;//the amount of time it takes to fall off the dock (one step per second)
	//summed up over many itterations

	for(docksize=1;docksize<50;docksize++) //sets up a loop for varying the boardsize
	{
		int n=0;// n is an indicator of how manty times we have gotten the drunkard wet
		int itterations=10000;// how many times we intend for him to get wet
		while(n<itterations)//sets up the loop to do the same board size many times
		{
			bool ondock=true;//holds if he is on the dock
			xpos=resetx();
			ypos=resety();

			while(isondock(xpos,ypos,docksize))//keeps moving him untill he falls off the dock
			{
				int movex=rand()%3-1;//gives a random number -1 0 or 1 to move in the x direction
				int movey=rand()%3-1;//same for the y direction
				xpos=xpos+movex;//these actually move him
				ypos=ypos+movey;
				seconds++;//adds to the number of steps
			}
			n++;
			xpos=resetx();
			ypos=resety();
		}
		seconds/=itterations;//finds average steps
		cout<<"size "<<docksize<<"    avg "<< seconds <<"\n";
	}
}
