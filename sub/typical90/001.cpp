#include <bits/stdc++.h>
using namespace std;

bool can_divide (vector<int> a, int k, int m) {
	// 長さm以上のk+1個以上のピースに分解可能か判定
	// O(a.size()) = O(n)で判定
	int length = 0;
	int count = 0;
	for (int i = 0; i < (int)a.size() - 1; i++) {
		length += a[i+1] - a[i];
		if (length >= m) {
			count += 1;
			length = 0;
		}
	}
	if (count >= k) return true;
	else return false;
}

int main () {
	int n, l;
	cin >> n >> l;
	int k;
	cin >> k;
	vector<int> a(n+2);
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = 0;
	a[n+1] = l;

	// 二分探索がうまくいかず
	int left = 0, right = l;
	while (left != right) {
		int mid = (left + right) / 2;
		cout << left << " " << right << endl;
		cout << mid << endl;
		if (can_divide(a, k, mid)) {
			left = mid;
		} else {
			right = mid - 1;
		}
	}
	cout << left << endl;
}