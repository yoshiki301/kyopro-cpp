// https://atcoder.jp/contests/typical90/tasks/typical90_br

#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;

	vector<long long> x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    // x, yの中央値を求める
    // nth_elementで入れ替えた後に[n/2]にアクセスすれば良い
	nth_element(x.begin(), x.begin() + n/2, x.end());
	nth_element(y.begin(), y.begin() + n/2, y.end());

	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(x[i] - x[n/2]);
		res += abs(y[i] - y[n/2]);
	}

	cout << res << endl;
}