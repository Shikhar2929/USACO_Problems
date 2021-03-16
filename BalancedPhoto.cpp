// BalancedPhoto.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
int N;
//int sortArr[100002];
int BIT[100002];
vector <pair<int, int>> sortArr;
int cmp(pair <int, int> A, pair<int, int> B)
{
	return A.first > B.first;
}
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
	while (index <= N) {
		BIT[index] += change;
		index += index & -index;
	}
}

int main()
{
	ifstream fin;
	fin.open("bphoto.in");
	ofstream fout;
	fout.open("bphoto.out");
	fin >> N;
	for (int i = 1;i <= N;i++)
	{
		int temp;
		fin >> temp;
		sortArr.push_back(make_pair(temp, i));
	}
	sort(sortArr.begin(), sortArr.end(), cmp);
	int answer = 0;
	int seen = 0;
	for (int i = 0;i < N;i++)
	{
		int LHS, RHS;
		LHS = query(sortArr[i].second);
		RHS = seen - LHS;
		seen++;
		if (max(LHS, RHS) > 2 * min(LHS, RHS))
			answer++;
		update(sortArr[i].second, 1);
	}
	fout << answer;
}
