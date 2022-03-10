// https://atcoder.jp/contests/abc237/tasks/abc237_d

#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> a(n+1);
	int l_count = 0, r_count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			a[n-l_count] = i;
			l_count += 1;
		} else {
			a[r_count] = i;
			r_count += 1;
		}
	}
	a[r_count] = n;

	for (int ai : a) cout << ai << " ";
	cout << endl;

}