	// MoortalCombat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
int N, M, K;
int convert[28][28];
int dp;
int main()
{
	ifstream fin;
	fin.open("cowmbat.in");
	ofstream fout;
	fout.open("cowmbat.out");
	fin >> N >> M >> K;
	string s;
	fin >> s;
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < M;j++)
		{
			fin >> convert[i][j];
		}
	}
	for (int k = 0;k < M;k++)  //Floyd Warshall Algorithm- kij
	{
		for (int i = 0;i < M;i++)
		{
			for (int j = 0;j < M;j++)
				convert[i][j] = min(convert[i][j], convert[i][k] + convert[k][j]);
		}
	}
	// Start with i=k, and rest is a prefix sum 
}
