// CowCrosstheRoad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>	
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
#define MAXN 100005
int BIT[100002];
int arr[50002];
int n;
int query(int index)
{
	int sum = 0;
	while (index > 0)
	{
		sum += BIT[index];
		index -= index & -index;
	}
	return sum;
}
void update(int index, int change) {
	while (index <= 2*n) {
		BIT[index] += change;
		index += index & -index;
	}
}

int main()
{
	ifstream fin;
	fin.open("circlecross.in");
	ofstream fout;
	fout.open("circlecross.out");
	fin >> n;
	int ans = 0;
	for (int i = 1;i <= 2 * n;i++)
	{
		int temp;
		fin >> temp;
		if (!arr[temp])
		{
			arr[temp] = i;
			update(i, 1);
		}
		else
		{
			update(arr[temp], -1);
			ans+=(query(i+1)-query(arr[temp]));
		}
	}
	fout << ans;
}

