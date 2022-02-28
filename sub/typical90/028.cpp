// https://atcoder.jp/contests/typical90/tasks/typical90_ab

#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_INDEX = 1001;

int main () {
	int n;
	cin >> n;

    // 2次元imos法
	vector<vector<int>> overlay(MAX_INDEX + 1, vector<int>(MAX_INDEX + 1, 0));
	map<int, int> overlay_count;
	int lx, ly, rx, ry;
	for (int i = 0; i < n; i++) {
		cin >> lx >> ly >> rx >> ry;
		overlay[lx][ly] += 1;
		overlay[lx][ry] -= 1;
		overlay[rx][ly] -= 1;
		overlay[rx][ry] += 1;
		overlay_count[i+1] = 0;
	}

	for (int i = 0; i <= MAX_INDEX; i++) {
		for (int j = 1; j <= MAX_INDEX; j++) {
			overlay[i][j] += overlay[i][j-1];
		}
	}
	for (int j = 0; j <= MAX_INDEX; j++) {
		for (int i = 1; i <= MAX_INDEX; i++) {
			overlay[i][j] += overlay[i-1][j];
		}
	}
	for (int i = 0; i < MAX_INDEX; i++) {
		for (int j = 0; j < MAX_INDEX; j++) {
			if (0 < overlay[i][j]) overlay_count[overlay[i][j]] += 1;
		}
	}

	for (int i = 1; i <= n; i++) cout << overlay_count[i] << endl;
}