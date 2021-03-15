#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;

#define MAXL 100001
#define MDL 1000000007

int arr1[MAXL];
int arr2[MAXL];

int first[MAXL];
int second[MAXL];
int answer[MAXL];

int N, M;
int total;

void displace_second(int old_index)
{
	int old_second_val = arr2[old_index];
	second[old_second_val] = 0;
	total--;
}

void displace_first(int old_index)
{
	// clear out first
	first[arr1[old_index]] = 0;

	int old_second_val = arr2[old_index];

	
	// if there is a prior first or second using this, then nothing to do, decrement total
	if ((first[old_second_val] && first[old_second_val] < old_index) ||
		(second[old_second_val] && second[old_second_val] < old_index)) {
		total--;
		return;
	}
	

	// move to second
	if (second[old_second_val])
		displace_second(second[old_second_val]);
	second[old_second_val] = old_index;

	//If second one has a first, that gets displaced
	if (first[old_second_val]) {
		displace_first(first[old_second_val]);
		first[old_second_val] = 0;
	}
}

int main()
{
	ifstream fin("cereal.in");
	ofstream fout("cereal.out");
	fin >> N >> M;

	int j;

	total = 0;

	for (j = 1; j <= N; j++) {
		fin >> arr1[j] >> arr2[j];
		first[j] = 0;
		second[j] = 0;
	}

	for (j = N; j > 0; j--)
	{
		int first_val = arr1[j];

		if (first[first_val])
			displace_first(first[first_val]);

		if (second[first_val])
			displace_second(second[first_val]);

		first[first_val] = j; total++;

		answer[j] = total;
	}

	for (j = 1; j <= N; j++)
		fout << answer[j] << endl;
}

