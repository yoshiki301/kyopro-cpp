// https://atcoder.jp/contests/typical90/tasks/typical90_bz

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
	cin >> n >> m;

	vector<int> lower_count(n, 0);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		int upper = max(a, b) - 1;
		lower_count[upper] += 1;
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (lower_count[i] == 1) res += 1;
	}
	cout << res << endl;
}