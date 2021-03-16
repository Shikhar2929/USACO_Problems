// UnionFind.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
int parent[100001];
int siz[100001];
int find(int A)
{
	if (A == parent[A])
		return A;
	return parent[A] = find(parent[A]);
}
int merge(int A, int B)
{
	int temp = find(A);
	int temp2 = find(B);
	if (temp == temp2)
		return siz[temp];
	parent[temp] = temp2;
	siz[temp2] += siz[temp];
	return siz[temp2];
}
int main()
{
   
}
