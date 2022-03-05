// https://atcoder.jp/contests/typical90/tasks/typical90_bk

#include <bits/stdc++.h>
using namespace std;

int main () {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> p(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cin >> p[i][j];
	}

    // hは小さいため全探索可能
    // どの行を選ぶか決めたとき, すべて同じ値になっている列の値で一番多いものを探す
	int res = 0;
	for (int i = 1; i < (1<<h); i++) {
		vector<int> check;
		int bit = 1, index = 0;
		int row_num = 0;
		while (bit < (1<<h)) {
			if (bit & i) {
				row_num += 1;
				if (check.size() == 0) check = p[index];
				else {
					for (int j = 0; j < w; j++) {
						if (check[j] != p[index][j]) check[j] = -1;
					}
				}
			}
			bit <<= 1;
			index += 1;
		}

		int count_max = 0;
		map<int, int> count;
		for (const int c : check) {
			if (c != -1) {
				count[c] += 1;
				count_max = max(count[c], count_max);
			}
		}
		res = max(count_max * row_num, res);
	}

	cout << res << endl;
}