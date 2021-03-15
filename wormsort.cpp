#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int,int> pii;
pll cows[100001];

#define MAX 100001
//#define MAXP 1001
#define LIM 999999999

struct Edge
{
	int w;
	int c1;
	int c2;
	//int x;
};

struct Edge E[MAX];

int origA[MAX];
int A[MAX];
int W[MAX];


set <int> Vfree; // vertices that need swapping
vector<struct Edge> Efree; 

bool comp(struct Edge a, struct Edge b) {
	return (a.w > b.w);
}
int main()
{

	ifstream fin("wormsort.in");
	ofstream fout("wormsort.out");

	int N, M, c1, c2, w;
	int x;
	set<int>::iterator vit1, vit2;

	fin >> N >> M;

	for (x = 0; x < N; x++) {
		fin >> A[x];
		origA[x] = A[x];
	}

	// find out which cows are not in the right position
	sort(A, A + N);
	for (x = 0; x < N; x++) {
		if (A[x] != origA[x])
			Vfree.insert(origA[x]);
	}

	if (Vfree.size() == 0) {
		fout << -1;
		return 0;
	}

	for (x = 0; x < M; x++) {
		fin >> c1 >> c2 >> w;

		E[x].w = w;
		E[x].c1 = c1;
		E[x].c2 = c2;
		//E[x].x = x;


		/*
		//if both ends are in the Vfree list, add this edge
		vit1 = Vfree.find(c1);
		vit2 = Vfree.find(c2);

		if ((vit1 != Vfree.end()) && (vit2 != Vfree.end())) {
			Efree.push_back(E[x]);
		}
		*/
		Efree.push_back(E[x]);
	}

	//sort in descending order
	sort(Efree.begin(), Efree.end(), comp);

	//Kruskal's to get maximum spanning tree
	//From largest edge, and keep removing its vertices from Vfree if both are present, else discard
	for (auto e : Efree) {
		vit1 = Vfree.find(e.c1);
		if (vit1 != Vfree.end())
			Vfree.erase(vit1);

		vit1 = Vfree.find(e.c2);

		if (vit1 != Vfree.end())
			Vfree.erase(vit1);
		
		if (Vfree.size() == 0)
		{
			fout << e.w;
			return 0;
		}
	}

	fout << -1;
}
