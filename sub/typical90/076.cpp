// https://atcoder.jp/contests/typical90/tasks/typical90_bx

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
	cin >> n;
    // 円環は2つ分用意する
	vector<long long> a(2*n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i+n] = a[i];
	}

	long long sum_a = 0;
	for (int i = 0; i < n; i++) sum_a += a[i];

	if (sum_a % 10 != 0) {
		cout << "No" << endl;
		return 0;
	}

	long long ten = sum_a / 10;
    // しゃくとりでやる
	int l = 0, r = 0;
	long long check_sum = a[0];
	while (l != 2*n-1) {
		if (check_sum == ten) {
			cout << "Yes" << endl;
			return  0;
		}
		else if (r == 2*n-1) {
			check_sum -= a[l];
			l += 1;
		}
		else if (l == r) {
			r += 1;
			check_sum += a[r];
		} else {
			if (check_sum < ten) {
				r += 1;
				check_sum += a[r];
			} else {
				check_sum -= a[l];
				l += 1;
			}
		}
	}

	cout << "No" << endl;
}