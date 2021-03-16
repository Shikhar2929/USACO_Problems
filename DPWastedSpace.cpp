// DPWastedSpace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

#define MAXL 401
#define LIM 999999999

int N, K;
int Grp[MAXL];
int tots = 0;
int maxall = 0;
int localmax = 0;
int dp[MAXL][MAXL];   // dp[N][K] 

int main()
{
    //std::cout << "Hello World!\n"; 

	ifstream fin("snakes.in");
	ofstream fout("snakes.out");

	fin >> N >> K;

	for (int n = 1; n <= N; n++) {
		fin >> Grp[n];
		tots += Grp[n];

		//running max for case where K = 0
		maxall = max(maxall, Grp[n]);
		dp[n][0] = maxall * n;

		for (int k = 1; k <= K; k++) {
			dp[0][k] = 0;
			dp[n][k] = LIM;
			
			localmax = Grp[n];

			for (int r = n - 1; r >= 0; r--) {
				dp[n][k] = min(dp[n][k], dp[r][k - 1] + (n - r)*localmax);
				localmax = max(localmax, Grp[r]);
			}
		}

	}

	fout << dp[N][K] - tots << '\n';

}
