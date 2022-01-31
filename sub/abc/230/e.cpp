// https://atcoder.jp/contests/abc230/tasks/abc230_e

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long k, res = 0;
	for (long long i = 1; i <= n; i++) {
		if (i*i <= n) k = i;
		else break;
	}
	for (long long i = 1; i <= k; i++) res += ((n / i) - (n / (i + 1)))*i;
	for (long long i = 1; i <= n / (k + 1); i++) res += (n / i);
	
	cout << res << endl;
}