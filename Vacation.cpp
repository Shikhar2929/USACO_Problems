#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n, m, k;
#define MAXL 100001

//first index = power of 2 for this transformation 
int xform[MAXL];
int arr[MAXL];
int copyarr[MAXL];

void swa(int x, int y)
{
	for (int i = x, j = y;i < j; i++, j--)
		swap(xform[i], xform[j]);
}

void calculate(int newarr[], int oldarr[], int reference[])
{
	for (int i = 1;i <= n;i++)
		newarr[i] = oldarr[reference[i]];

	copy(newarr, newarr + n + 1, oldarr); //src start, src end, destination
}

int main()
{
	ifstream fin("swap.in");
	ofstream fout("swap.out");
	fin >> n;
	fin >> m >> k;
	int x, y;
	for (int i = 1;i <= n;i++)
	{
		xform[i] = i;
		arr[i] = i;
	}

	for (int i = 0;i < m;i++)
	{
		fin >> x >> y;
		swa(x, y);
	}
	
	for (int p = 1; p <= k; p <<= 1) // for each power of 2 that exists for this number, apply the transformation
	{
		if (p & k)
			calculate(copyarr, arr, xform);

		calculate(copyarr, xform, xform);
	}

	for (int i = 1;i <= n;i++)
		fout << arr[i] << endl;
}
