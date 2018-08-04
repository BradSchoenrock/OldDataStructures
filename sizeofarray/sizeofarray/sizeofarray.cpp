// sizeofarray.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
      int arr[] = { 1, 2, 3, 4, 5, 6 };
      int size = sizeof( arr ) / sizeof( arr[0] );
      cout << size << endl;
}

