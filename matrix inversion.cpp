// matrix inversion.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <assert.h>
using namespace std;

void printmatrix(double **toprint,int size)
{
	cout<<"*******the size is "<<size<<"**********\n";
	for(int start=0;start<size;start++)
	{
		for(int end=0;end<size;end++)
		{
			cout<<scientific<<toprint[start][end]<<'\t';
		}
		cout<<'\n'<<'\n';
	}
	cout<<'\n'<<'\n'<<'\n'<<'\n';
}
double det(double **big,int size)
{
	
	if(size==2)
	{
		return big[0][0]*big[1][1]-big[0][1]*big[1][0];
	}
	else
	{
		double toreturn=0;
		for(int now=0;now<size;now++)
		{
			double **smaller = 0;									//creating smaller
			smaller = new double*[size-1];
			for(int i = 0; i < size-1; i++)
				smaller[i] = new double[size-1];

			for(int front=0;front<size;front++)
			{
				for(int back=0;back<size-1;back++)
				{
					if(front<now)
						smaller[front][back]=big[front][back];
					else if(front>now)
						smaller[front-1][back]=big[front][back];
				}
			}
			if(now%2==0)
				toreturn=toreturn+big[now][size-1]*det(smaller,size-1);
			else
				toreturn=toreturn-big[now][size-1]*det(smaller,size-1);

			for(int i = 0; i < size-1; i++)						//deleting smaller
				delete[] smaller[i];
			delete[]smaller;
		}
		return toreturn;
	}
	

	/*
	double **touse = 0;									//creating touse
	touse = new double*[size];
	for(int i = 0; i < size; i++)
		touse[i] = new double[size];

	for(int up=0;up<size;up++)
	{
		for(int down=0;down<size;down++)
		{
			touse[up][down]=big[up][down];
		}
	}
	for(int round=0;round<size;round++)
	{
		for(int up=0;up<size;up++)
		{
			for(int down=0;down<size;down++)
			{
				if(up>round)
					touse[up][down]=touse[up][down]-touse[up][0]/touse[round][0]*touse[round][down];
			}
		}
	}
	double toreturn=1;
	for(int why=0;why<size;why++)
		toreturn=toreturn*touse[why][why];

	for(int i = 0; i < size; i++)						// *******deleting touse
		delete[] touse[i];
	delete[]touse;

	return toreturn;
	*/
}

void findInverse(double **cinv,double **C,int size)//finds the inverse of Cinv so as to find the original matrix C
{
	double deter=det(cinv,size);

	double **minors = 0;									//creating minors
	minors = new double*[size];
	for(int i = 0; i < size; i++)
		minors[i] = new double[size];

	double **temp = 0;									//creating temp
	temp = new double*[size-1];
	for(int i = 0; i < size-1;i++)
		temp[i] = new double[size-1];

	for(int in=0;in<size;in++)
	{
		for(int out=0;out<size;out++)
		{
			for(int front=0;front<size;front++)
			{
				for(int back=0;back<size;back++)
				{
					if(front<in&&back<out)
						temp[front][back]=cinv[front][back];
					else if(front<in&&back>out)
						temp[front][back-1]=cinv[front][back];
					else if(front>in&&back<out)
						temp[front-1][back]=cinv[front][back];
					else if(front>in&&back>out)
						temp[front-1][back-1]=cinv[front][back];
				}
			}
			double one=temp[0][0];
			double two=temp[0][1];
			double three=temp[1][0];
			double four=temp[1][1];
			double d=det(temp,size-1);
			minors[in][out]=det(temp,size-1);
		}
	}

	for(int i = 0; i < size-1; i++)						// *******deleting temp
		delete[] temp[i];
	delete[]temp;


	double **adjoint = 0;									//creating adjoint
	adjoint = new double*[size];
	for(int i = 0; i < size; i++)
		adjoint[i] = new double[size];

	for(int one=0;one<size;one++)
	{
		for(int two=0;two<size;two++)
		{
			if((one+two)%2==0)
				adjoint[one][two]=minors[two][one];
			else
				adjoint[one][two]=-minors[two][one];
		}
	}
	for(int i = 0; i < size; i++)						//deleting minors
		delete[] minors[i];
	delete[]minors;

	for(int one=0;one<size;one++)
	{
		for(int two=0;two<size;two++)
		{
			C[one][two]=adjoint[one][two]/deter;
		}
	}

	for(int i = 0; i < size; i++)						//deleting adjoint
		delete[] adjoint[i];
	delete[]adjoint;
}

int main(array<System::String ^> ^args)
{
	double **send = 0;
	send = new double*[3];
	for(int i = 0; i < 3; i++)
		send[i] = new double[3];

	double **take = 0;
	take = new double*[3];
	for(int i = 0; i < 3; i++)
		take[i] = new double[3];

	double b[3];
	double x[3];
	send[0][0]=1;
	send[0][1]=3;
	send[0][2]=-2;
	send[1][0]=3;
	send[1][1]=5;
	send[1][2]=6;
	send[2][0]=2;
	send[2][1]=4;
	send[2][2]=3;
	b[0]=5;
	b[1]=7;
	b[2]=8;
	x[0]=0;
	x[1]=0;
	x[2]=0;

	cout<<det(send,3)<<'\n';
	findInverse(send,take,3);
	printmatrix(send,3);
	printmatrix(take,3);

	for(int y=0;y<3;y++)
		for(int z=0;z<3;z++)
			x[z]=x[z]+take[z][y]*b[y];

	cout<<x[0]<<'\t'<<x[1]<<'\t'<<x[2]<<'\n';
	
	cout<<"press any key, then enter to end...";
	bool end;
	cin>>end;
}
