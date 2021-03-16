// Moocast.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
int position[1001][2];
int parent[1001];
int siz[1001];
struct edge {
	int distance;
	int start;
	int end;
};
int cmp(edge A, edge B) { return A.distance < B.distance; }
int find(int A)
{
	if (A == parent[A])
		return A;
	return parent[A] = find(parent[A]);
}
int forcemerge(int A, int B)
{
	int temp = find(A);
	int temp2 = find(B);
	if (temp == temp2)
		return siz[temp];
	parent[temp] = temp2;
	siz[temp2] += siz[temp];
	return siz[temp2];
}
vector <struct edge> edges;
int main()
{
	ifstream fin;
	fin.open("moocast.in");
	ofstream fout;
	fout.open("moocast.out");
	fin >> N;
	for (int i = 0;i < N;i++)
	{
		fin >> position[i][0] >> position[i][1];
		parent[i] = i;
		siz[i] = 1;
	}
	for (int i = 0;i < N;i++)
		for (int j = i+1;j < N;j++)
		{
			int dist = (position[i][0] - position[j][0]) * ((position[i][0] - position[j][0]));
			dist += abs(position[i][1] - position[j][1]) * abs(position[i][1] - position[j][1]);
			edge E = { dist,i,j };
			edges.push_back(E);
		}
	sort(edges.begin(), edges.end(),cmp);
	int answer=0;
	for (int i = 0;i < edges.size();i++)
	{
		if (forcemerge(edges[i].start, edges[i].end) == N)
		{
			answer = edges[i].distance;
			break;
		}
	}
	fout << answer;
}


