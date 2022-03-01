// https://atcoder.jp/contests/typical90/tasks/typical90_ah

#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	// setで要素の種類数を管理しmultisetで実際の個数を管理, それぞれ対数時間で検索できる
	// 個数管理はmapの方が簡単かも
	set<int> s;
	multiset<int> ms;
	// しゃくとりでなるべく長い部分列を見つける
	int l = 0, r = 0;

	int res = 0;
	while (r < n) {
		auto it_s = s.find(a[r]);
		if ((int)s.size() == k && it_s == s.end()) {
			ms.erase(ms.find(a[l]));
			auto it_ms = ms.find(a[l]);
			// multisetで個数が0になったときのみsetからも削除する
			if (it_ms == ms.end()) s.erase(a[l]);
			l += 1;
		} else {
			ms.insert(a[r]);
			s.insert(a[r]);
			r += 1;
		}
		res = max(res, (int)ms.size());
	}
	cout << res << endl;
}