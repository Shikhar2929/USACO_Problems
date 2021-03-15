#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD12(x) ((x + 12)%12)

int N;

int rooms[2502];
int seen[2502];

vector<int> edges[2501];



int get_surr_score(int n) {

	int score = 0;

	for (auto c : edges[n]) {
		if (seen[c])
			continue;

		seen[c] = 1;

		int curr, surr;

		curr = rooms[c];
		surr = MOD12(get_surr_score(c));

		score += MOD12(curr - surr);
	}

	return MOD12(score);
}

int main()
{

	ifstream fin("clocktree.in");
	ofstream fout("clocktree.out");

	fin >> N;

	for (int n = 1; n <= N; n++) {
		fin >> rooms[n];
	}

	for (int n = 1; n <= N - 1; n++) {
		int x, y;

		fin >> x >> y;

		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	int cnt = 0;
	int curr, surr;

	for (int n = 1; n <= N; n++) {
		// get current room score
		curr = MOD12(rooms[n]);

		for (int i = 1; i <= 2500; i++)
			seen[i] = 0;
		seen[n] = 1;

		// for each child calculate aggregate score
		surr = get_surr_score(n);

		if ((curr == surr) || (curr == MOD12(surr + 1))) {
			cnt++;
		}
	}

	fout << cnt << endl;

}
