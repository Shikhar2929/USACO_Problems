 // Timeline.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
typedef long long LL;
int start[100002];
int N, M, C;
int parents[100002];
vector <pair<int,int>> edges[100002];
int dist[100001];
struct dEdge{
	int distance;
	int node; 
};

struct CompareHeight {
	bool operator()(dEdge const& p1, dEdge const& p2)
	{
		// return "true" if "p1" is ordered 
		// before "p2", for example:
		return p1.distance > p2.distance;
	}
};
using T = dEdge; priority_queue<T, vector<T>, CompareHeight> pq;
void dijkstra() { // Source and destination
	//for (int i = 0; i < N; ++i) dist[i] = 0;
	// Set all distances to infinity
	

	while (pq.size()) {
		int cdist; int node; 
		cdist = pq.top().distance;
		node = pq.top().node;
		pq.pop();
		if (cdist != dist[node]) continue;
		for (auto n: edges[node]) {
			if (!dist[n.first])
				dist[n.first] = max(start[n.first], cdist + n.second);
			else if (dist[n.first] >= cdist + n.second)
				continue;
			else
				dist[n.first] = cdist + n.second;
			pq.push({ dist[n.first],n.first });
		}
	}
}
int main()
{
	ifstream fin;
	fin.open("timeline.in");
	ofstream fout;
	fout.open("timeline.out");
	fin >> N >> M >> C;
	for (int i = 1;i <= N;i++)
		fin >> start[i];
	for (int i = 1;i <= C;i++)
	{
		int start, end, diff;
		fin >> start >> end >> diff;
		edges[start].push_back(make_pair(end, diff));
		parents[end]++;
	}
	
	for (int i = 1;i <= N;i++)
	{
		if (!parents[i])
		{
			pq.push({ start[i],i });
			dist[i] = start[i];
		}
	}
	dijkstra();
	for (int i = 1;i <= N;i++)
		fout << dist[i] << endl;
}

