// https://atcoder.jp/contests/typical90/tasks/typical90_ca

#include <bits/stdc++.h>
using namespace std;

int main () {
    int h, w;
	cin >> h >> w;
	vector<vector<int>> diff(h, vector<int>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cin >> diff[i][j];
	}
	int b;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> b;
			diff[i][j] -= b;
		}
	}

	long long res = 0;
	for (int i = 0; i < h-1; i++) {
		for (int j = 0; j < w-1; j++) {
			int manipurate = diff[i][j];
			res += abs(manipurate);
			for (int dx = 0; dx <= 1; dx++) {
				for (int dy = 0; dy <= 1; dy++) {
					diff[i+dx][j+dy] -= manipurate;
				}
			}
		}
		if (diff[i][w-1] != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	for (int j = 0; j < w; j++) {
		if (diff[h-1][j] != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	cout << res << endl;
}