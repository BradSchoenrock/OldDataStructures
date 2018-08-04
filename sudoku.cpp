// sudoku.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <assert.h>
using namespace std;


void printsudoku(int puzzle[9][9])//prints out the puzzles current state for debugging. 
{
	for(int i=0; i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(j%3==0)
				cout<<" ";
			cout<<puzzle[i][j];
		}
		if(i%3==2)
			cout<<'\n';
		cout<<'\n';
	}
}

void wait() // function used to read in a puzzle. 
{
	string z;
	cout<<'\n'<<"paused..."<<'\n';
	cin>>z;
}

void wait(int puzzle[9][9])
{
	string z;
	printsudoku(puzzle);
	cout<<'\n'<<"paused..."<<'\n';
	cin>>z;
}

bool check(int puzzle[9][9]) // checks to make sure the puzzle is still valid. In principle this should do nothing. 
{
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{	
			if(puzzle[i][j]!=0)
			{
				for(int n=0;n<9;n++)
				{
					if(n!=i)//checks row for duplicates
					{
						if(puzzle[i][j]==puzzle[n][j])
							return false;
					}
					if(n!=j)//checks collumn for duplicates
					{
						if(puzzle[i][j]==puzzle[i][n])
							return false;
					}

				}
				//begins checking the nine boxes***********************

				if(i<3)//on the top
				{
					if(j<3)//on the left
					{
						for(int n=0;n<3;n++)
						{
							for(int m=0;m<3;m++)
							{
								if(i!=n||j!=m)
								{
									if(puzzle[i][j]==puzzle[n][m])
										return false;
								}
							}
						}
					}
					else if(j>5)//on the right
					{
						for(int n=0;n<3;n++)
						{
							for(int m=6;m<9;m++)
							{
								if(i!=n||j!=m)
								{
									if(puzzle[i][j]==puzzle[n][m])
										return false;
								}
							}
						}
					}
					else//in the middle
					{
						for(int n=0;n<3;n++)
						{
							for(int m=3;m<6;m++)
							{
								if(i!=n||j!=m)
								{
									if(puzzle[i][j]==puzzle[n][m])
										return false;
								}
							}
						}
					}
				}
				else if(i>5)//on the bottom
				{
					if(j<3)//on the left
					{
						for(int n=6;n<9;n++)
						{
							for(int m=0;m<3;m++)
							{
								if(i!=n||j!=m)
								{
									if(puzzle[i][j]==puzzle[n][m])
										return false;
								}
							}
						}
					}
					else if(j>5)//on the right
					{
						for(int n=6;n<9;n++)
						{
							for(int m=6;m<9;m++)
							{
								if(i!=n||j!=m)
								{
									if(puzzle[i][j]==puzzle[n][m])
										return false;
								}
							}
						}
					}
					else//in the middle
					{
						for(int n=6;n<9;n++)
						{
							for(int m=3;m<6;m++)
							{
								if(i!=n||j!=m)
								{
									if(puzzle[i][j]==puzzle[n][m])
										return false;
								}
							}
						}
					}
				}
				else//in the middle
				{
					if(j<3)//on the left
					{
						for(int n=3;n<6;n++)
						{
							for(int m=0;m<3;m++)
							{
								if(i!=n||j!=m)
								{
									if(puzzle[i][j]==puzzle[n][m])
										return false;
								}
							}
						}
					}
					else if(j>5)//on the right
					{
						for(int n=3;n<6;n++)
						{
							for(int m=6;m<9;m++)
							{
								if(i!=n||j!=m)
								{
									if(puzzle[i][j]==puzzle[n][m])
										return false;
								}
							}
						}
					}
					else//in the middle
					{
						for(int n=3;n<6;n++)
						{
							for(int m=3;m<6;m++)
							{
								if(i!=n||j!=m)
								{
									if(puzzle[i][j]==puzzle[n][m])
										return false;
								}
							}
						}
					}
				}
				//end box checking **************


			}
		}
	}
	return true;
}
//if there is only one place to put a number it puts it there
void lookrows(int puzzle[9][9]) 
{
	bool needs[10];
	for (int i=0;i<9;i++)//i= row number we are looking at
	{
		for (int y=1;y<10;y++)//y=number it needs
		{
			needs[y]=true;
			for(int j=0;j<9;j++)//j=collumn number
			{
				if(puzzle[i][j]==y)
					needs[y]=false;
			}
		}
		for(int w=1;w<10;w++)//if there is only one place for a number, then place it there
		{
			if(needs[w])
			{
				int numplace=0;
				int place =-1;
				for(int j=0;j<9;j++)
				{
					if(puzzle[i][j]==0)//i don't want to cover up something usefull...
					{
						int test[9][9];
						for (int a=0;a<9;a++)
						{
							for (int b=0;b<9;b++)
							{
								test[a][b]=puzzle[a][b];
							}
						}
						test[i][j]=w;
						if(check(test))
						{
							numplace++;
							place=j;
						}
					}
				}
				if(numplace==0)
				{
					cout<<"error in row "<<i<<" no place for a "<<w<<'\n';
					wait(puzzle);
					return;
				}
				else if(numplace==1)
				{
					puzzle[i][place]=w;
					check(puzzle);
				}
			}
		}
	}
}
//if there is only one place to put a number it puts it there
void lookcollumns(int puzzle[9][9])
{
	bool needs[10];
	for (int j=0;j<9;j++)//j= collumn number we are looking at
	{
		for (int y=1;y<10;y++)//y=number it needs
		{
			needs[y]=true;
			for(int i=0;i<9;i++)//i=row number
			{
				if(puzzle[i][j]==y)
					needs[y]=false;
			}
		}
		for(int w=1;w<10;w++)//if there is only one place for a number, then place it there
		{
			if(needs[w])
			{
				int numplace=0;
				int place =-1;
				for(int i=0;i<9;i++)
				{
					if(puzzle[i][j]==0)//i don't want to cover up something usefull...
					{
						int test[9][9];
						for (int a=0;a<9;a++)
						{
							for (int b=0;b<9;b++)
							{
								test[a][b]=puzzle[a][b];
							}
						}
						test[i][j]=w;
						if(check(test))
						{
							numplace++;
							place=i;
						}
					}
				}
				if(numplace==0)
				{
					cout<<"error in row "<<j<<" no place for a "<<w<<'\n';
					wait(puzzle);
					return;
				}
				else if(numplace==1)
					puzzle[place][j]=w;
				check(puzzle);
			}
		}
	}
}
//if there is only one place to put a number it puts it there
void lookboxes(int puzzle[9][9])
{
	//looks at boxes in this order
	// 0 1 2
	// 3 4 5
	// 6 7 8 
	bool needs[10];
	for (int z=0;z<9;z++)//z= which box we are on
	{
		for(int k=1;k<10;k++)//checks what i need in the zth box
		{
			needs[k]=true;
			for(int i=3*(z%3);i<(3*(z%3)+3);i++)
			{
				for(int j=3*(z/3);j<(3*(z/3)+3);j++)
				{
					if(puzzle[i][j]==k)
					{
						needs[k]=false;
					}
				}
			}
		}

		for(int w=1;w<10;w++)//if there is only one place for a number, then place it there
		{
			if(needs[w])
			{
				int numplace=0;
				int placei =-1;
				int placej =-1;
				for(int i=3*(z%3);i<(3*(z%3)+3);i++)
				{
					for(int j=3*(z/3);j<(3*(z/3)+3);j++)
					{
						if(puzzle[i][j]==0)//i don't want to cover up something usefull...
						{
							int test[9][9];
							for (int a=0;a<9;a++)
							{
								for (int b=0;b<9;b++)
								{
									test[a][b]=puzzle[a][b];
								}
							}
							test[i][j]=w;

							if(check(test))
							{
								numplace++;
								placei=i;
								placej=j;
							}
						}
					}
				}
				if(numplace==0)
				{
					cout<<"error in box "<<z<<" no place for a "<<w<<'\n';
					wait(puzzle);
					return;
				}
				else if(numplace==1)
					puzzle[placei][placej]=w;
				if(!check(puzzle))
					cout<<"there is a mistake with lookbox\n";
			}
		}
	}
}
//if a square can only have one value it puts it there
void looksquares(int puzzle[9][9])//checks each of the 91 boxes individually, and if there is only one possibility it puts it there
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(puzzle[i][j]==0)
			{
				int numpos=0;
				int num=0;
				for(int v=1;v<10;v++)
				{
					int temp[9][9];
					for(int n=0;n<9;n++)
					{
						for(int m=0;m<9;m++)
						{
							temp[n][m]=puzzle[n][m];
						}
					}
					temp[i][j]=v;
					if(check(temp))
					{
						numpos++;
						num=v;
					}
				}
				if(numpos==0)
				{
					cout<<"error in square["<<i<<"]["<<j<<"] \nno possible values"<<'\n';
					wait(puzzle);
					return;
				}
				else if(numpos==1)
				{
					puzzle[i][j]=num;
				}
			}
		}
	}
}

int zeros(int puzzle[9][9])
{
	int count=0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(puzzle[i][j]==0)
				count++;
		}
	}
	return count;
}
//the nakedpairs algorithm applied to possible
void nakedpairsrow(int puzzle[9][9], bool possible[9][9][10])
{
	for(int i=0;i<9;i++)//i=row number
	{
		for(int n=1;n<10;n++)
		{
			for(int m=n+1;m<10;m++)
			{
				bool samemask=true;
				int j=0;
				//needs to check that it only matches in two places... 
				int matchpos=0;
				while(j<9&&samemask)
				{
					if(possible[i][j][n]!=possible[i][j][m])
						samemask=false;
					else if(possible[i][j][n]==possible[i][j][m]&&possible[i][j][n])
						matchpos++;
					j++;
				}
				if(samemask&&matchpos==2)
				{
					for(int j=0;j<9;j++)
					{
						if(possible[i][j][n])
						{
							for(int b=1;b<10;b++)
							{
								if(b!=n&&b!=m)
								{
									possible[i][j][b]=false;
								}
							}
						}
					}
				}
			}
		}
	}
}

void nakedpairscollumn(int puzzle[9][9], bool possible[9][9][10])
{
	for(int j=0;j<9;j++)//i=row number
	{
		for(int n=1;n<10;n++)
		{
			for(int m=n+1;m<10;m++)
			{
				bool samemask=true;
				int i=0;
				int matchpos=0;
				while(i<9&&samemask)
				{
					if(possible[i][j][n]!=possible[i][j][m])
						samemask=false;
					else if(possible[i][j][n]==possible[i][j][m]&&possible[i][j][n])
						matchpos++;
					i++;
				}
				if(samemask&&matchpos==2)
				{
					for(int i=0;i<9;i++)
					{
						if(possible[i][j][n])
						{
							for(int b=1;b<10;b++)
							{
								if(b!=n&&b!=m)
								{
									possible[i][j][b]=false;
								}
							}
						}
					}
				}
			}
		}
	}
}

void nakedpairsbox(int puzzle[9][9], bool possible[9][9][10])
{
	//looks at boxes in this order
	// 0 1 2
	// 3 4 5
	// 6 7 8 

	for(int z=0;z<9;z++)//z= box number
	{
		for(int n=1;n<10;n++)
		{
			for(int m=n+1;m<10;m++)
			{
				bool samemask=true;
				int i=0;
				int matchpos=0;
				for(int i=3*(z%3);i<(3*(z%3)+3);i++)
				{
					for(int j=3*(z/3);j<(3*(z/3)+3);j++)
					{
						if(samemask)
						{
							if(possible[i][j][n]!=possible[i][j][m])
								samemask=false;
							else if(possible[i][j][n]==possible[i][j][m]&&possible[i][j][n])
								matchpos++;
						}
					}
				}
				if(samemask&&matchpos==2)
				{
					for(int i=3*(z%3);i<(3*(z%3)+3);i++)
					{
						for(int j=3*(z/3);j<(3*(z/3)+3);j++)
						{
							if(puzzle[i][j]==0)
							{
								if(possible[i][j][n])
								{
									for(int b=1;b<10;b++)
									{
										if(b!=n&&b!=m)
										{
											//cout<<"eliminating "<<b<<" from "<<i<<" "<<j<<'\n';
											possible[i][j][b]=false;
											//wait(puzzle);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
//the hidden pairs algorithm applied to possible
void hiddenpairsrow(int puzzle[9][9], bool possible[9][9][10])
{}

void hiddenpairscollumn(int puzzle[9][9], bool possible[9][9][10])
{}

void hiddenpairsbox(int puzzle[9][9], bool possible[9][9][10])
{}

//if we take into account possible then if there is only one place to put a number put it there
void lookconstrainrow(int puzzle[9][9], bool possible[9][9][10])
{
	for(int i=0;i<9;i++)//i is the row number
	{
		bool needs[10];
		for(int z=1;z<10;z++)//z is the number we are trying to place
		{
			needs[z]=true;
			for(int j=0;j<9;j++)
			{
				if(puzzle[i][j]==z)
					needs[z]=false;
			}
		}
		for(int w=1;w<10;w++)
		{
			if(needs[w])
			{
				int numplace=0;
				int place =-1;
				for(int j=0;j<9;j++)
				{
					if(puzzle[i][j]==0)
					{
						if(possible[i][j][w])
						{
							numplace++;
							place=j;
						}
					}
				}
				if(numplace==0)
				{
					cout<<"error in row "<<i<<" no place for a "<<w<<'\n';
					wait(puzzle);
					return;
				}
				else if(numplace==1)
				{
					puzzle[i][place]=w;
					check(puzzle);
				}
			}
		}
	}
}

void lookconstraincollumn(int puzzle[9][9], bool possible[9][9][10])
{
	for(int j=0;j<9;j++)
	{
		bool needs[10];
		for(int z=1;z<10;z++)//z is the number we are trying to place
		{
			needs[z]=true;
			for(int i=0;i<9;i++)
			{
				if(puzzle[i][j]==z)
					needs[z]=false;
			}
		}
		for(int w=1;w<10;w++)
		{
			if(needs[w])
			{
				int numplace=0;
				int place =-1;
				for(int i=0;i<9;i++)
				{
					if(puzzle[i][j]==0)
					{
						if(possible[i][j][w])
						{
							numplace++;
							place=i;
						}
					}
				}
				if(numplace==0)
				{
					cout<<"error in row "<<j<<" no place for a "<<w<<'\n';
					wait(puzzle);
					return;
				}
				else if(numplace==1)
				{
					puzzle[place][j]=w;
					check(puzzle);
				}
			}
		}
	}
}

void lookconstrainbox(int puzzle[9][9], bool possible[9][9][10])
{
	//looks at boxes in this order
	// 0 1 2
	// 3 4 5
	// 6 7 8 
	bool needs[10];
	for (int z=0;z<9;z++)//z= which box we are on
	{
		for(int k=1;k<10;k++)//checks what i need in the zth box
		{
			needs[k]=true;
			for(int i=3*(z%3);i<(3*(z%3)+3);i++)
			{
				for(int j=3*(z/3);j<(3*(z/3)+3);j++)
				{
					if(puzzle[i][j]==k)
					{
						needs[k]=false;
					}
				}
			}
		}

		for(int w=1;w<10;w++)//if there is only one place for a number, then place it there
		{
			if(needs[w])
			{
				int numplace=0;
				int placei =-1;
				int placej =-1;
				for(int i=3*(z%3);i<(3*(z%3)+3);i++)
				{
					for(int j=3*(z/3);j<(3*(z/3)+3);j++)
					{
						if(puzzle[i][j]==0)//i don't want to cover up something usefull...
						{
							if(possible[i][j][w])
							{
								numplace++;
								placei=i;
								placej=j;
							}
						}
					}
				}
				if(numplace==0)
				{
					cout<<"error in box "<<z<<" no place for a "<<w<<'\n';
					wait(puzzle);
					return;
				}
				else if(numplace==1)
					puzzle[placei][placej]=w;
				if(!check(puzzle))
					cout<<"there is a mistake with lookconstrainbox\n";
			}
		}
	}
}

void lookconstrainsquare(int puzzle[9][9],bool possible[9][9][10])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(puzzle[i][j]==0)
			{
				int numposs=0;
				int value=0;
				for(int z=1;z<10;z++)
				{
					if(possible[i][j][z])
					{
						numposs++;
						value=z;
					}
				}
				if(numposs==0)
				{
					cout<<"error no possible move in "<<i<<" "<<j<<'\n';
					wait(puzzle);
					return;
				}
				else if(numposs==1)
				{
				//	cout<<"placing "<<value<<" in row "<<i<<" and collumn "<<j<<'\n';
					puzzle[i][j]=value;
				//	wait(puzzle);
				}
			}
		}
	}
}
//performs the spearing operation on possible aka pointing pairs or pointing tripples
void rowspearing(int puzzle[9][9],bool possible[9][9][10])
{
	for(int i=0;i<9;i++)
	{
		bool needs[10];
		for(int z=1;z<10;z++)
		{
			needs[z]=true;
			for(int j=0;j<9;j++)
			{
				if(puzzle[i][j]==z)
					needs[z]=false;
			}
		}
		for(int w=1;w<10;w++)
		{
			if(needs[w])
			{
				int places=-1;
				bool samebox=true;
				for(int j=0;j<9;j++)
				{
					if(puzzle[i][j]==0&&possible[i][j][w])
					{
						if(places==-1)
							places=j;
						else if(places/3!=j/3)
							samebox=false;
					}
				}
				if(samebox)
				{
					for(int n=3*(i/3);n<3*(i/3)+3;n++)
					{
						for(int m=3*(places/3);m<3*(places/3)+3;m++)
						{
							if(puzzle[n][m]==0&&n!=i&&possible[n][m][w])
							{
								possible[n][m][w]=false;
							}
						}
					}
				}
			}
		}
	}
}//can only spear boxes

void collumnspearing(int puzzle[9][9],bool possible[9][9][10])
{
	for(int j=0;j<9;j++)
	{
		bool needs[10];
		for(int z=1;z<10;z++)
		{
			needs[z]=true;
			for(int i=0;i<9;i++)
			{
				if(puzzle[i][j]==z)
					needs[z]=false;
			}
		}
		for(int w=1;w<10;w++)
		{
			if(needs[w])
			{
				int places=-1;
				bool samebox=true;
				for(int i=0;i<9;i++)
				{
					if(puzzle[i][j]==0&&possible[i][j][w])
					{
						if(places==-1)
							places=i;
						else if(places/3!=i/3)
							samebox=false;
					}
				}
				if(samebox)
				{
					for(int m=3*(j/3);m<3*(j/3)+3;m++)
					{
						for(int n=3*(places/3);n<3*(places/3)+3;n++)
						{
							if(m!=j)
							{
								possible[n][m][w]=false;
							}
						}
					}
				}
			}
		}
	}
}//can only spear boxes

void boxspearing(int puzzle[9][9],bool possible[9][9][10])
{
	for(int z=0;z<9;z++)//z is box number
	{
		//looks at boxes in this order
		// 0 1 2
		// 3 4 5
		// 6 7 8 
		bool needs[10];
		for(int w=1;w<10;w++)
		{
			needs[w]=true;
			for(int i=3*(z/3);i<3*(z/3)+3;i++)
			{
				for(int j=3*(z%3);j<3*(z%3)+3;j++)
				{
					if(puzzle[i][j]==w)
						needs[w]=false;
				}
			}
		}
		for(int w=1;w<10;w++)
		{
			if(needs[w])
			{
				int placei=-1;
				int placej=-1;
				bool samerow=true;
				bool samecol=true;
				for(int i=3*(z/3);i<3*(z/3)+3;i++)
				{
					for(int j=3*(z%3);j<3*(z%3)+3;j++)
					{
						if(puzzle[i][j]==0 && possible[i][j][w])
						{
							if(placei==-1)
							{
								placei=i;
								placej=j;
							}
							else if(placei!=i&&placej!=j)
							{
								samerow=false;
								samecol=false;
							}
							else if(placei!=i)
								samerow=false;
							else if(placej!=j)
								samecol=false;
						}
					}
				}
				if(samerow)
				{
					for(int m=0;m<9;m++)
					{
						if(m<3*(z%3) || m>3*(z%3)+2)
						{
							if(possible[placei][m][w])
								possible[placei][m][w]=false;
						}
					}
				}
				if(samecol)
				{
					for(int n=0;n<9;n++)
					{
						if(n<3*(z/3) || n>3*(z/3)+2)
						{
							if(possible[n][placej][w])
								possible[n][placej][w]=false;
						}
					}
				}
			}
		}
	}
}
//checks the simplist algorithms
void simplealgorithms(int sudoku[9][9])
{
	if(!check(sudoku))
		return;
	bool changed=true;
	int numzeros=zeros(sudoku);
	while(numzeros!=0&&changed)
	{
		int before[9][9];//sets up to make sure something changes
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				before[i][j]=sudoku[i][j];
			}
		}
		lookrows(sudoku);
		lookcollumns(sudoku);
		lookboxes(sudoku);

		numzeros=zeros(sudoku);
		if(numzeros==0)
			return;//the puzzle is done anyway...

		changed=false;//this checks if anything changed this time around... if not we break the loop and need to try something else.
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(before[i][j]!=sudoku[i][j])
				{
					changed=true;
				}
			}
		}
	}
}
//does some more intermediate algorithms
void intermediatealgorithms(int sudoku[9][9])
{
	if(!check(sudoku))
		return;
	bool changed=true;
	int numzeros=zeros(sudoku);
	while(numzeros!=0&&changed)
	{
		int before[9][9];//sets up to make sure something changes
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				before[i][j]=sudoku[i][j];
			}
		}

		looksquares(sudoku);

		numzeros=zeros(sudoku);
		if(numzeros==0)
			return;//the puzzle is done anyway...

		changed=false;//this checks if anything changed this time around... if not we break the loop and need to try something else.
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(before[i][j]!=sudoku[i][j])
				{
					changed=true;
				}
			}
		}
	}
}
//updates the possibility space
void calcpossibilities(int sudoku[9][9],bool possible[9][9][10])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			int test[9][9];
			for(int n=0;n<9;n++)
			{
				for(int m=0;m<9;m++)
				{
					test[n][m]=sudoku[n][m];
				}
			}
			if(sudoku[i][j]==0)
			{
				for(int z=1;z<10;z++)
				{
					test[i][j]=z;
					if(check(test))
						possible[i][j][z]=true;
					else
						possible[i][j][z]=false;
				}
			}
			else
			{
				for(int z=1;z<10;z++)
				{
					if(sudoku[i][j]==z)
						possible[i][j][z]=true;
					else
						possible[i][j][z]=false;
				}
			}
		}
	}

	/*
	//print possibilities

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(sudoku[i][j]==0)
			{
				for(int z=1;z<10;z++)
				{
					if(possible[i][j][z])
						cout<<"square "<<i<<" "<<j<<" can be a "<<z<<'\n';
				}
				cout<<'\n';
			}
		}
	}
	cout<<'\n';
	wait(sudoku);
	*/
}
//checks to see if more algorithms are needed. 
void advancedalgorithms(int sudoku[9][9],bool possible[9][9][10])
{
	if(!check(sudoku))
		return;
	//calculate possibilities
	calcpossibilities(sudoku,possible);
	
	bool changed=true;
	int numzeros=zeros(sudoku);
	while(numzeros!=0&&changed)
	{
		int puzzlebefore[9][9];//sets up to make sure something changes
		bool possiblebefore[9][9][10];
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				puzzlebefore[i][j]=sudoku[i][j];
				if(sudoku[i][j]==0)
					for(int z=1;z<10;z++)
						possiblebefore[i][j][z]=possible[i][j][z];
			}
		}
		


		nakedpairsrow(sudoku,possible);
		nakedpairscollumn(sudoku,possible);
		nakedpairsbox(sudoku,possible);
	
	
		rowspearing(sudoku,possible);
		collumnspearing(sudoku,possible);
		//wait(sudoku);
		boxspearing(sudoku,possible);


		lookconstrainrow(sudoku,possible);
		lookconstraincollumn(sudoku,possible);
		lookconstrainbox(sudoku,possible);
		lookconstrainsquare(sudoku,possible);

		numzeros=zeros(sudoku);
		if(numzeros==0)
			return;//the puzzle is done anyway...

		changed=false;//this checks if anything changed this time around... if not we break the loop and need to try something else.
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(puzzlebefore[i][j]!=sudoku[i][j])
					changed=true;
				if(sudoku[i][j]==0)
				{
					for(int z=1;z<10;z++)
					{
						if(possiblebefore[i][j][z]!=possible[i][j][z])
						{
							changed=true;
						}
					}
				}
			}
		}
	}
	//print possibilities
	/*
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(sudoku[i][j]==0)
			{
				for(int z=1;z<10;z++)
				{
					if(possible[i][j][z])
						cout<<"square "<<i<<" "<<j<<" can be a "<<z<<'\n';
				}
				cout<<'\n';
			}
		}
	}
	cout<<'\n';
	wait(sudoku);
	*/
}
//wrapper class to solve the puzzle. 
void solve(int sudoku[9][9],bool possible[9][9][10])
{
	if(!check(sudoku))
		return;
	bool changed=true;
	int numzeros=zeros(sudoku);
	while(changed)
	{
		int before[9][9];//sets up to make sure something changes
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				before[i][j]=sudoku[i][j];
			}
		}
		//begins simple algorithms
		if(!check(sudoku))
			return;
		bool changed1=true;
		while(changed1)
		{
			int before1[9][9];//sets up to make sure something changes
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					before1[i][j]=sudoku[i][j];
				}
			}
			simplealgorithms(sudoku);
			numzeros=zeros(sudoku);
			if(numzeros==0)
			{
				return;//the puzzle is done anyway...
			}
			changed1=false;//this checks if anything changed this time around... if not we break the loop and need to try something else.
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if(before1[i][j]!=sudoku[i][j])
					{
						changed1=true;
					}
				}
			}
		}

		//begins medium algorithms
		if(!check(sudoku))
			return;
		bool changed2=true;
		while(changed2)
		{
			int before2[9][9];//sets up to make sure something changes
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					before2[i][j]=sudoku[i][j];
				}
			}
			intermediatealgorithms(sudoku);
			numzeros=zeros(sudoku);
			if(numzeros==0)
			{
				return;//the puzzle is done anyway...
			}
			changed2=false;//this checks if anything changed this time around... if not we break the loop and need to try something else.
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if(before2[i][j]!=sudoku[i][j])
					{
						changed2=true;
					}
				}
			}
		}
		//begins advanced algorithms
		if(!check(sudoku))
			return;
		bool changed3=true;
		while(changed3)
		{
			int before3[9][9];//sets up to make sure something changes
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					before3[i][j]=sudoku[i][j];
				}
			}
			//wait(sudoku);
			advancedalgorithms(sudoku,possible);
			numzeros=zeros(sudoku);
			if(numzeros==0)
			{
				return;//the puzzle is done anyway...
			}
			changed3=false;//this checks if anything changed this time around... if not we break the loop and need to try something else.
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if(before3[i][j]!=sudoku[i][j])
					{
						changed3=true;
					}
				}
			}
		}
		//checks if any of the levels did anything... 
		changed=false;//this checks if anything changed this time around... if not we break the loop and need to try something else.
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(before[i][j]!=sudoku[i][j])
				{
					changed=true;
				}
			}
		}
	}
}

int main()
{
	int sudoku[9][9];// row, collumn
	for (int i = 0; i<9; i++)
	{
		for (int j=0;j<9;j++)
		{
			sudoku[i][j]=0;
		}
	}
	int a=0;//dummy variable allows me to collapse my comments by blocks 
	a=0;
	//printsudoku(sudoku);
/*
listed solution to 21
945  781  632
613  925  784
827  463  915

136  894  257
594  172  368
278  536  491

781  349  526
469  258  173
352  617  849

listed solution to 22
493  128  657
521  976  348
768  345  921

139  562  874
842  739  516
657  481  293

214  693  785
976  854  132
385  217  469

*/
	a=1;
	//input for fiendish puzzle 22
	a=1;
	/*
	sudoku[0][0]=0;
	sudoku[0][1]=0;
	sudoku[0][2]=0;
	sudoku[0][3]=0;
	sudoku[0][4]=0;
	sudoku[0][5]=8;
	sudoku[0][6]=0;
	sudoku[0][7]=0;
	sudoku[0][8]=0;
	
	sudoku[1][0]=0;
	sudoku[1][1]=0;
	sudoku[1][2]=1;
	sudoku[1][3]=0;
	sudoku[1][4]=0;
	sudoku[1][5]=6;
	sudoku[1][6]=0;
	sudoku[1][7]=4;
	sudoku[1][8]=0;
	
	sudoku[2][0]=7;
	sudoku[2][1]=0;
	sudoku[2][2]=0;
	sudoku[2][3]=0;
	sudoku[2][4]=4;
	sudoku[2][5]=0;
	sudoku[2][6]=9;
	sudoku[2][7]=2;
	sudoku[2][8]=1;
	
	sudoku[3][0]=0;
	sudoku[3][1]=3;
	sudoku[3][2]=0;
	sudoku[3][3]=0;
	sudoku[3][4]=0;
	sudoku[3][5]=0;
	sudoku[3][6]=8;
	sudoku[3][7]=0;
	sudoku[3][8]=0;

	sudoku[4][0]=8;
	sudoku[4][1]=0;
	sudoku[4][2]=2;
	sudoku[4][3]=0;
	sudoku[4][4]=0;
	sudoku[4][5]=0;
	sudoku[4][6]=5;
	sudoku[4][7]=0;
	sudoku[4][8]=6;

	sudoku[5][0]=0;
	sudoku[5][1]=0;
	sudoku[5][2]=7;
	sudoku[5][3]=0;
	sudoku[5][4]=0;
	sudoku[5][5]=0;
	sudoku[5][6]=0;
	sudoku[5][7]=9;
	sudoku[5][8]=0;

	sudoku[6][0]=2;
	sudoku[6][1]=1;
	sudoku[6][2]=4;
	sudoku[6][3]=0;
	sudoku[6][4]=9;
	sudoku[6][5]=0;
	sudoku[6][6]=0;
	sudoku[6][7]=0;
	sudoku[6][8]=5;
	
	sudoku[7][0]=0;
	sudoku[7][1]=7;
	sudoku[7][2]=0;
	sudoku[7][3]=8;
	sudoku[7][4]=0;
	sudoku[7][5]=0;
	sudoku[7][6]=1;
	sudoku[7][7]=0;
	sudoku[7][8]=0;

	sudoku[8][0]=0;
	sudoku[8][1]=0;
	sudoku[8][2]=0;
	sudoku[8][3]=2;
	sudoku[8][4]=0;
	sudoku[8][5]=0;
	sudoku[8][6]=0;
	sudoku[8][7]=0;
	sudoku[8][8]=0;
	*/
	a=1;
	//input for fiendish puzzle 21
	a=1;
	/*
	sudoku[0][0]=0;
	sudoku[0][1]=0;
	sudoku[0][2]=0;
	sudoku[0][3]=0;
	sudoku[0][4]=0;
	sudoku[0][5]=8;
	sudoku[0][6]=0;
	sudoku[0][7]=0;
	sudoku[0][8]=0;
	
	sudoku[1][0]=0;
	sudoku[1][1]=0;
	sudoku[1][2]=1;
	sudoku[1][3]=0;
	sudoku[1][4]=0;
	sudoku[1][5]=6;
	sudoku[1][6]=0;
	sudoku[1][7]=4;
	sudoku[1][8]=0;
	
	sudoku[2][0]=7;
	sudoku[2][1]=0;
	sudoku[2][2]=0;
	sudoku[2][3]=0;
	sudoku[2][4]=4;
	sudoku[2][5]=0;
	sudoku[2][6]=9;
	sudoku[2][7]=2;
	sudoku[2][8]=1;
	
	sudoku[3][0]=0;
	sudoku[3][1]=3;
	sudoku[3][2]=0;
	sudoku[3][3]=0;
	sudoku[3][4]=0;
	sudoku[3][5]=0;
	sudoku[3][6]=8;
	sudoku[3][7]=0;
	sudoku[3][8]=0;

	sudoku[4][0]=8;
	sudoku[4][1]=0;
	sudoku[4][2]=2;
	sudoku[4][3]=0;
	sudoku[4][4]=0;
	sudoku[4][5]=0;
	sudoku[4][6]=5;
	sudoku[4][7]=0;
	sudoku[4][8]=6;

	sudoku[5][0]=0;
	sudoku[5][1]=0;
	sudoku[5][2]=7;
	sudoku[5][3]=0;
	sudoku[5][4]=0;
	sudoku[5][5]=0;
	sudoku[5][6]=0;
	sudoku[5][7]=9;
	sudoku[5][8]=0;

	sudoku[6][0]=2;
	sudoku[6][1]=1;
	sudoku[6][2]=4;
	sudoku[6][3]=0;
	sudoku[6][4]=9;
	sudoku[6][5]=0;
	sudoku[6][6]=0;
	sudoku[6][7]=0;
	sudoku[6][8]=5;
	
	sudoku[7][0]=0;
	sudoku[7][1]=7;
	sudoku[7][2]=0;
	sudoku[7][3]=8;
	sudoku[7][4]=0;
	sudoku[7][5]=0;
	sudoku[7][6]=1;
	sudoku[7][7]=0;
	sudoku[7][8]=0;

	sudoku[8][0]=0;
	sudoku[8][1]=0;
	sudoku[8][2]=0;
	sudoku[8][3]=2;
	sudoku[8][4]=0;
	sudoku[8][5]=0;
	sudoku[8][6]=0;
	sudoku[8][7]=0;
	sudoku[8][8]=0;
	*/
	a=1;
	//input by typing into command prompt
	a=1;
	/*
	string s;
	cout<<"please input the puzzle... (0=unknown)... \n";
	for(int i=0;i<9;i++)
	{
		cout<<"row "<<i+1<<'\n';
		for (int j=0;j<9;j++)
		{
			cin>>sudoku[i][j];
		}
	}
	cout<<'\n';
	
	*/
	a=1;


	ifstream infile("sudokupuzzles.txt");
	ofstream outfile("sudokuoutputs2.txt");
	ofstream outunsolved("sudoku_unsolved.txt");
	if(infile.fail())
	{
		cout<<"File Not Found\n";
		exit(1);
	}
	else
	{
		int puzzlenumber=0;
		int number=0;
		int numbersolved=0;
		while(!infile.eof())
		{
			char letter;
			letter=infile.get();
			if(letter=='\n')
			{
				if(number!=81)
					cout<<"there was a newline before there were 81 inputs..."<<'\n';
				puzzlenumber++;
				number=0;

				for(int i=0;i<9;i++)//forces all squares to be 0-9
				{
					for(int j=0;j<9;j++)
					{
						if(sudoku[i][j]>9||sudoku[i][j]<0)
							sudoku[i][j]=0;
					}
				}

				bool allgood;
				allgood=check(sudoku);
				if(!allgood)
				{
					cout<<"conflicting inputs!!!\n";
					wait(sudoku);
					
				}
				//else
					//cout<<"all is good with inputs!!!\n";

				/*
				string z="ok";
				// re-input procedure
				while(z!="yes")
				{
					cout<<'\n'<<"is this correct?(yes or no)"<<'\n';
					printsudoku(sudoku);
					cin>>z;
					if(z=="no")
					{
						int row;
						int collumn;
						int value;
						cout<<"what row has an error: ";
						cin>>row;
						cout<<"\nwhat collumn has an error: ";
						cin>>collumn;
						cout<<"\nwhat should the box be: ";
						cin>>value;
						cout<<'\n';
						sudoku[row-1][collumn-1]=value;
					}
				}
				*/
	

				int numzeros=81;
				numzeros=zeros(sudoku);

				outfile<<'\n'<<" puzzle # "<<puzzlenumber<<'\n'<<'\n';

				for(int i=0; i<9;i++)//sends the file to outfile
				{
					for(int j=0;j<9;j++)
					{
						if(j%3==0)
							outfile<<" ";
						outfile<<sudoku[i][j];
					}
					if(i%3==2)
						outfile<<'\n';
					outfile<<'\n';
				}
				outfile<<"------------"<<'\n'<<'\n';
				bool possible[9][9][10];

				solve(sudoku,possible);//here's the workhorse of the operation...**************
	
				for(int i=0; i<9;i++)//sends the file to outfile
				{
					for(int j=0;j<9;j++)
					{
						if(j%3==0)
							outfile<<" ";
						outfile<<sudoku[i][j];
					}
					if(i%3==2)
						outfile<<'\n';
					outfile<<'\n';
				}
				outfile<<"********************************"<<'\n';

				numzeros=zeros(sudoku);
				allgood=check(sudoku);

				if(allgood)
				{
					if(numzeros==0)
					{
						numbersolved++;
					}
					else
					{
						outunsolved<<"puzzle number "<<puzzlenumber<<'\n';
						for(int i=0; i<9;i++)//sends the file to outunsolved
						{
							for(int j=0;j<9;j++)
							{
								if(j%3==0)
									outunsolved<<" ";
								outunsolved<<sudoku[i][j];
							}
							if(i%3==2)
								outunsolved<<'\n';
							outunsolved<<'\n';
						}
						for(int i=0;i<9;i++)
						{
							for(int j=0;j<9;j++)
							{
								if(sudoku[i][j]==0)
								{
									for(int z=1;z<10;z++)
									{
										if(possible[i][j][z])
											outunsolved<<"square "<<i<<" "<<j<<" can be a "<<z<<'\n';
									}
									outunsolved<<'\n';
								}
							}
						}
						outunsolved<<'\n';
						outunsolved<<"********************************"<<'\n';
					}
				}
				else
				{
					cout<<"we have a conflict in a solution"<<'\n'<<'\n';
					wait(sudoku);
				}
				double frac=(double)numbersolved/puzzlenumber*100;
				cout<<"we have solved "<<frac<<"	percent and are on puzzle number "<<puzzlenumber<<'\n';
			}
			else if(letter>='0'&&letter<='9')
			{
				int y=number/9;
				int z=number%9;
				sudoku[number/9][number%9]=letter-48;
				number++;
			}
			else
			{
				sudoku[number/9][number%9]=0;
				number++;
			}
		}
		double frac=(double)numbersolved/puzzlenumber*100;
		cout<<"we have solved "<<frac<<"	percent and are on puzzle number "<<puzzlenumber<<'\n';
		outfile<<frac<<" percent of "<<puzzlenumber<<" puzzles were solved.";
		outfile.close();
	}
	wait();
}