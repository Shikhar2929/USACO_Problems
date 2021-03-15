#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define INTMAX  2147483647
#define MAXL 101
#define POINT(i,j) ((i)*N+(j))

/*
struct edge {
	int toNode;
	int cost;
};
*/

int N, T;
int fields[105 * MAXL];
int spCost[105 * MAXL]; // cost of shortest path
priority_queue<pii, vector<pii>, greater<pii>> q;

set<int> edges[105 * MAXL];

void addEdge(int parent, int node)
{
	//struct edge e;
	//e.toNode = node;
	//e.cost = fields[node] + dist * T;
	edges[parent].insert(node);
}

void dfs(int n, int dist, int parent)
{
	if (n < 0)
		return;

	if (dist == 3) // || (dist < 3 && n == POINT(N-1,N-1)))
	{	
		addEdge(parent, n);
		return;
	}

	int i, j;
	i = n / N;
	j = n % N;

	if (POINT(i + 1, j) != parent && i + 1 < N)
		dfs(POINT(i + 1, j), dist + 1, parent);
	if (POINT(i, j + 1) != parent && j + 1 < N)
		dfs(POINT(i, j + 1), dist + 1, parent);
	if (POINT(i - 1 , j) != parent && i - 1 >= 0)
		dfs(POINT(i - 1, j), dist + 1, parent);
	if (POINT(i, j - 1) != parent && j - 1 >= 0)
		dfs(POINT(i, j - 1), dist + 1, parent);
}


void dijkstra(int s)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			spCost[POINT(i,j)] = INTMAX;
		}
	}

	spCost[POINT(0, 0)] = 0;
	q.push(make_pair(0, s));

	while (q.size()) {
		pii p;
		int currCost, currNode;

		p = q.top(); 
		q.pop();

		currCost = p.first;
		currNode = p.second;

		if (currCost != spCost[currNode])
			continue; // avoid repeat processing of this node

		for (auto n : edges[currNode])
		{
			int newCost = currCost + fields[n] + 3 * T;
			if (newCost < spCost[n]) {
				spCost[n] = newCost;
				q.push(make_pair(newCost, n));
			}
		}
	}
}
int dist(int i,int j, int fi, int fj)
{
	return (fj - j) + (fi - i);
}

int main()
{

	ifstream fin("visitfj.in");
	ofstream fout("visitfj.out");
	fin >> N >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fin >> fields[POINT(i,j)];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x = POINT(i, j);
			dfs(x, 0, x); // start, dist, parent
		}
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fout << "==== CURRENT NODE " << i << " : " << j << " ======" << endl;
			for (auto n : edges[POINT(i,j)])
			{
				fout << n / N << ", " << n % N << endl;
			}
		}
	}
	*/

	dijkstra(0);

	int answer = spCost[POINT(N-1, N-1)];

	for (int i = N - 4; i <= N-1; i++)
	{
		for (int j = N - 4; j <= N - 1; j++)
		{
			int d = dist(i, j, N - 1, N - 1);
			if(d<3)
			answer = min(answer, spCost[POINT(i, j)]+T*d);	
		}
	}
	fout << answer;
}
