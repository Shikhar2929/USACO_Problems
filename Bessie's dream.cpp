// Bessie's dream.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
int N, M;
int arr[1001][1001];
int seen[1001][1001][2][4];
struct node {
	int i;
	int j;
	int orientation;
	int smell;
	int depth;

};
int main()
{
	ifstream fin("dream.in");
	ofstream fout("dream.out");
	fin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
			fin >> arr[i][j];

	}
	queue <node> Q;
	Q.push({ 0,0,0,0,0 });
	seen[0][0][0][0] = 1;
	while (!Q.empty())
	{
		node temp = Q.front();
		Q.pop();
		if (arr[temp.i][temp.j] != 4)
		{
			if (temp.i + 1 != N)
			{
				if (arr[temp.i + 1][temp.j] == 3 && temp.smell == 1)
				{
					if (seen[temp.i + 1][temp.j][temp.smell][0] < temp.depth + 1 && seen[temp.i + 1][temp.j][temp.smell][0]!=0)
					{
						Q.push({ temp.i + 1,temp.j,temp.orientation, temp.depth + 1 });
						seen[temp.i + 1][temp.j][temp.smell][0] = temp.depth+1;
					}

				}
				else if (arr[temp.i + 1][temp.j] != 3 && arr[temp.i + 1][temp.j] != 0)
				{
					if (arr[temp.i + 1][temp.j] == 4)
						temp.orientation = 1;
					else
						temp.orientation = 0;
					if (seen[temp.i + 1][temp.j][temp.smell][temp.orientation] < temp.depth + 1 && seen[temp.i + 1][temp.j][temp.smell][temp.orientation] != 0)
					{
						Q.push({ temp.i + 1,temp.j,temp.orientation, temp.depth + 1 });
						seen[temp.i + 1][temp.j][temp.smell][temp.orientation] = temp.depth+1;
					}
				}
			}
			if (temp.j + 1 != N)
			{
				if (arr[temp.i][temp.j+1] == 3 && temp.smell == 1)
				{

					if (seen[temp.i][temp.j+1][temp.smell][0] < temp.depth + 1 && seen[temp.i][temp.j+1][temp.smell][0] != 0)
					{
						Q.push({ temp.i,temp.j+1,temp.orientation, temp.depth + 1 });
						seen[temp.i][temp.j+1][temp.smell][0] = temp.depth+1;
					}

				}
				else if (arr[temp.i][temp.j+1] != 3 && arr[temp.i][temp.j+1] != 0)
				{
					if (arr[temp.i][temp.j + 1] == 4)
						temp.orientation = 2;
					else
						temp.orientation = 0;
					if (seen[temp.i][temp.j+1][temp.smell][temp.orientation] < temp.depth + 1 && seen[temp.i][temp.j+1][temp.smell][temp.orientation] != 0)
					{
						Q.push({ temp.i ,temp.j+1,temp.orientation, temp.depth + 1 });
						seen[temp.i][temp.j+1][temp.smell][temp.orientation] = temp.depth+1;
					}
				}
			}
			if (temp.j - 1 != -1)
			{
				if (arr[temp.i][temp.j + 1] == 3 && temp.smell == 1)
				{
					if (seen[temp.i][temp.j - 1][temp.smell][0] < temp.depth + 1 && seen[temp.i][temp.j - 1][temp.smell][0] != 0)
					{
						Q.push({ temp.i,temp.j - 1,temp.orientation, temp.depth + 1 });
						seen[temp.i][temp.j - 1][temp.smell][0] = temp.depth + 1;
					}

				}
				else if (arr[temp.i][temp.j - 1] != 3 && arr[temp.i][temp.j-1] != 0)
				{
					if (arr[temp.i][temp.j - 1] == 4)
						temp.orientation = 3;
					else
						temp.orientation = 0;
					if (seen[temp.i][temp.j - 1][temp.smell][temp.orientation] < temp.depth + 1 && seen[temp.i][temp.j-1][temp.smell][temp.orientation] != 0)
					{
						Q.push({ temp.i ,temp.j - 1,temp.orientation, temp.depth + 1 });
						seen[temp.i][temp.j - 1][temp.smell][0] = temp.depth + 1;
					}
				}
			}
			if (temp.i - 1 != -1)
			{
				if (arr[temp.i-1][temp.j] == 3 && temp.smell == 1)
				{
					if (seen[temp.i-1][temp.j][temp.smell][0] < temp.depth + 1 && seen[temp.i-1][temp.j][temp.smell][0] != 0)
					{
						Q.push({ temp.i-1 ,temp.j,temp.orientation, temp.depth + 1 });
						seen[temp.i-1][temp.j][temp.smell][0] = temp.depth + 1;
					}

				}
				else if (arr[temp.i-1][temp.j] != 3 && arr[temp.i -1][temp.j] != 0)
				{
					if (arr[temp.i - 1][temp.j] == 4)
						temp.orientation = 4;
					else
						temp.orientation = 0;
					if (seen[temp.i-1][temp.j][temp.smell][temp.orientation] < temp.depth + 1 && seen[temp.i-1][temp.j][temp.smell][temp.orientation] != 0)
					{
						
						Q.push({ temp.i-1 ,temp.j,temp.orientation, temp.depth+1 });
						seen[temp.i-1][temp.j][temp.smell][temp.orientation] = temp.depth + 1;
					}
				}
				else
				{
					if (temp.orientation == 1)
					{
						if (arr[temp.i + 1][temp.j])
						

					}



				}




			}
		}


	}
}