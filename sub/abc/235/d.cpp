// https://atcoder.jp/contests/abc235/tasks/abc235_d

include <bits/stdc++.h>
using namespace std;

constexpr long long MAX_N = 1e6;

int main () {
	long long a, n;
	cin >> a >> n;

	vector<long long> min_count(MAX_N, MAX_N);
	queue<long long> que;
	min_count[1] = 0;
	que.push(1);

	while (!que.empty()) {
		long long x = que.front();
		que.pop();

		if (x >= 10 && x % 10 != 0) {
			long long next = (x / 10) + (int)pow(10, (int)log10(x)) * (x % 10);
			if (min_count[next] > min_count[x] + 1) {
				min_count[next] = min_count[x] + 1;
				que.push(next);
			}
		}
		if (x*a < MAX_N) {
			if (min_count[x*a] > min_count[x] + 1) {
				min_count[x*a] = min_count[x] + 1;
				que.push(x*a);
			}
		}
		if (min_count[n] < MAX_N) {
			cout << min_count[n] << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}