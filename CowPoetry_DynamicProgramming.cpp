// CowPoetry.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
typedef pair<long long, long long> pii;
#define MODULO(x) (x)%1000000007
#define MOD 1000000007
long long N, M, K;
long long w_Syll[5001];
long long w_R[5001];
long long patterns[27];
long long dp[50001];
long long rhymes[5001];
long long R = 0;
map<long long, long long> syll; // syllable length, frequency 
vector<pii> rhymeArr; // rhyme class, syllable length
long long groups[5002];
void knapsack()
{
	for (map <long long, long long>::iterator it = syll.begin();it != syll.end();it++)
		dp[it->first] = it->second;

	for (int i = 0;i <= K;i++)
	{
		for (map <long long,long long>::iterator it=syll.begin();it!=syll.end();it++)
		{
			if ((i - it->first) < 0)
				break;
			dp[i] += MODULO((dp[i - it->first] * it->second)) ;
			dp[i] = MODULO(dp[i]);
		}
	}

}
int cmp(pair <long long, long long> A, pair<long long, long long> B) {
	if (A.first == B.first)
		return A.second < B.second;
	else
		return A.first < B.first;
}
long long exp(int base, int power) {
	if (power == 0) return 1;
	if (power == 1) return (base + MOD) % MOD;
	long long ans = exp(base, power / 2);
	ans = (ans * ans + MOD) % MOD;
	if (power % 2 == 1) ans = (ans * base + MOD) % MOD;
	return (ans + MOD) % MOD;
}
int main()
{
	ifstream fin;
	fin.open("7.in");
	ofstream fout;
	fout.open("poetry.out");
	fin >> N >> M >> K;
	for (int i = 0;i < N;i++)
	{
		fin >> w_Syll[i] >> w_R[i];
		rhymes[w_R[i]]++;
		rhymeArr.push_back(make_pair(w_R[i], w_Syll[i]));

		if (syll.find(w_Syll[i])!=syll.end())
			syll[w_Syll[i]]++;
		else
			syll[w_Syll[i]] = 1;
	}

	sort(rhymeArr.begin(), rhymeArr.end(), cmp);
	for (int i = 0;i < M;i++)
	{
		char c;
		fin >> c;
		patterns[(int) c - 'A']++;
	}
	knapsack();
	for (int i = 0;i < rhymeArr.size();i++) {
		long long x = MODULO(dp[K - rhymeArr[i].second]);

		groups[rhymeArr[i].first] += x;

		groups[rhymeArr[i].first] = MODULO(groups[rhymeArr[i].first]);
	}
	long long answer = 1;
	for (int j = 0;j < 27;j++)
	{
		if (!patterns[j])
			continue;
		long long temp = 0;
		for (int i=1;i<=N;i++)
		{
			if (!groups[i])
				continue;
			long long x;
			x = exp(groups[i], patterns[j]);
			temp += MODULO(x);
			temp = MODULO(temp);
		}
		answer = MODULO(answer* temp);
	}
	cout << answer;
	
}
