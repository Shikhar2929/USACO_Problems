#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, C;
int cities[1001];
vector <int> edges[2001];
int dp[1001][1001]; //First element is city, second element is number of days
queue <pair<int,pii>> q; //City Number, Amount Collected, Time 
int main()
{
	ifstream fin;
	fin.open("time.in");
	ofstream fout;
	fout.open("time.out");
	fin >> N >> M >> C;
	for (int i = 1;i <= N;i++)
		fin >> cities[i];
	for (int i = 1;i <= M;i++)
	{
		int x, y;
		fin >> x >> y;
		edges[x].push_back(y);
	}
	
	
	q.push(make_pair(1, make_pair(0, 0)));
	// BFS, don't want to go to far into a bad node 
	int answer = 0;
	while (!q.empty())
	{
		int x = q.front().first; //City number
		int y = q.front().second.first; //Amount collected 
		int days = q.front().second.second;//days
		q.pop();
		if (dp[x][days] >= y &&dp[x][days]!=0)
			continue;
		else
			dp[x][days] = y;
		y += cities[x];
		if (y < C * days * days && C*days*days>1000)
			continue;
		if (days > 1000)
			continue;
		if (x == 1)
			answer = max(answer, y-C*days*days);
		//Add part of c*t^2
		for (auto n : edges[x])
		{
			//q.push(n);
			q.push(make_pair(n, make_pair(y, days + 1)));
		}
	}
	fout << answer;
}
