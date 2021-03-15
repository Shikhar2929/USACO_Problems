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
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;

#define MAXL 100001
#define MDL 1000000007

// sort by X and Y, and be able to lookup a specific X and Y in O(1) time

/*
map<int, pii> arr;
vector <pii> Xarr;
vector <pii> Yarr;
*/

map<int, vector<int>> Xarr;
map<int, vector<int>> Yarr;
map<pii, int> seen; // key = {x,y}

int N, startX, startY, endX, endY;
struct node {
	int value; // number of mirrors taken to get to this node
	int x; 
	int y;
	int direction; //0=Horizontal 1=Vertical 
};

struct CompareHeight {
	bool operator()(node const& p1, node const& p2)
	{
		// return "true" if "p1" is ordered 
		// before "p2", for example:
		return p1.value > p2.value;
	}
};

int BFS()
{
	using T = node; priority_queue<T, vector<T>, CompareHeight> q;
	q.push({ 0,startX,startY,0 });
	q.push({ 0,startX,startY,1 });

	int answer = 0;
	while(q.size())
	{ 
		int val = q.top().value;
		int x = q.top().x;
		int y = q.top().y;
		int d = q.top().direction;
		q.pop();
		if (x == endX || y == endY)
			return val;
		if (d)
		{
			for (auto n : Yarr[y])
			{
				if(n==x)
					continue;
				if (seen[{n, y}] <= val && seen[{n, y}])
					break;
				seen[{n, y}] = val+1;
				q.push({ val + 1,n,y, 0});
			}
		}
		else
		{
			for (auto n : Xarr[x])
			{
				if (n == y)
					continue;
				if (seen[{x, n}] <= val && seen[{x, n}])
					break;
				seen[{x, n}] = val + 1;
				q.push({ val + 1,x,n, 1 });
			}
		}
	
	}
	return -1;
}
int main()
{
	ifstream fin("lasers.in");
	ofstream fout("lasers.out");
	fin >> N >> startX >> startY >> endX >> endY;
	for (int i = 1;i <= N;i++)
	{
		int tempX,tempY;
		fin >> tempX >> tempY;

		Xarr[tempX].push_back(tempY);
		Yarr[tempY].push_back(tempX);
	}
	fout<<BFS();
	//cout << "end" << endl;
}
