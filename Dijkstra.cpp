// Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
using ll = long long;
#define pb push_back
#define INTMAX 2147483647
struct pipe {
	int end;
	int cost;
	int flow;
};
double dist[1001];
int N, M;
vector <struct pipe> pipes[1001];
struct d {
	float answer;
	int node;
	int minFlow;
	int cost;
};
struct Compare {
	bool operator() (d const& d1, d const& d2)
	{
		return d1.answer < d2.answer;
	}
};
void dijkstra(int start)
{
	for (int i = 0;i < N;i++)
		dist[i] = 0;
	dist[0] = 0;
	using T = struct d;
	priority_queue < T, vector<T>, Compare> q;
	q.push({0,0,1001,0 });
	while (q.size())
	{
		d temp;
		temp = q.top();
		q.pop();
		int currCost = temp.cost;
		int currNode = temp.node;
		if (temp.answer != dist[currNode])
			continue;
		for (auto n : pipes[currNode])
		{
			int minFlow = min(temp.minFlow, n.flow);
			float newCost = (float)minFlow/( (float) currCost + (float) n.cost);
			if (newCost > dist[n.end])
			{
				dist[n.end] = newCost;
				q.push({newCost,n.end,minFlow,currCost+n.cost});
			}
		}

	}
}
int main()
{
	ifstream fin;
	fin.open("pump.in");
	ofstream fout;
	fout.open("pump.out");
	fin >> N >> M;
	for (int i = 0;i < M;i++)
	{
		int x, y, c, f;
		fin >> x >> y >> c >> f;
		pipe P = { y-1,c,f };
		pipes[x-1].push_back(P);
		pipes[y-1].push_back({ x-1, c, f });
	}
	dijkstra(0);
	fout<<int(dist[N - 1]*1000000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
