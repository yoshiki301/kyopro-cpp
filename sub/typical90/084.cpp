// https://atcoder.jp/contests/typical90/tasks/typical90_cf

#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	string s;
	cin >> n;
	cin >> s;

	// 累積的に計算, ランレングス圧縮でもできるらしい
	// 最後に現れるo, xの位置を記録してO(n)でとく
	int o_left = -1, x_left = -1;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			if (x_left >= 0) {
				res += x_left + 1;
			}
			o_left = i;
		} else {
			if (o_left >= 0) {
				res += o_left + 1;
			}
			x_left = i;
		}
	}

	cout << res << endl;
}