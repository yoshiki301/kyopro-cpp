#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_DIST = 1e6;

int main () {
	int h, w, rs, cs, rt, ct;
	cin >> h >> w;
	cin >> rs >> cs;
	cin >> rt >> ct;

	vector<string> s(h);
	for (int i = 0; i < h; i++) cin >> s[i];

	vector<vector<pair<int, int>>> direct_count(h, vector<pair<int, int>>(w, make_pair(0b0000, MAX_DIST)));
	direct_count[rs-1][cs-1] = make_pair(0b0000, -1);
	queue<pair<int, int>> coord;
	coord.push(make_pair(rs-1, cs-1));

	while (!coord.empty()) {
		auto c = coord.front();
		coord.pop();
		int x = c.first, y = c.second;
		int direct = direct_count[x][y].first;
		int count = direct_count[x][y].second;

		int next_count;
		if (x > 0) {
			next_count = count + ((direct & 0b0001) ? 0 : 1);
			if (direct_count[x-1][y].second >= next_count && s[x-1][y] == '.') {
				direct_count[x-1][y].first |= 0b0001;
				direct_count[x-1][y].second = next_count;
				coord.push(make_pair(x-1, y));
			}
		}
		if (x < h-1) {
			next_count = count + ((direct & 0b0010) ? 0 : 1);
			if (direct_count[x+1][y].second >= next_count  && s[x+1][y] == '.') {
				direct_count[x+1][y].first |= 0b0010;
				direct_count[x+1][y].second = next_count;
				coord.push(make_pair(x+1, y));
			}
		}
		if (y > 0) {
			next_count = count + ((direct & 0b0100) ? 0 : 1);
			if (direct_count[x][y-1].second >= next_count  && s[x][y-1] == '.') {
				direct_count[x][y-1].first |= 0b0100;
				direct_count[x][y-1].second = next_count;
				coord.push(make_pair(x, y-1));
			}
		}
		if (y < w-1) {
			next_count = count + ((direct & 0b1000) ? 0 : 1);
			if (direct_count[x][y+1].second >= next_count  && s[x][y+1] == '.') {
				direct_count[x][y+1].first |= 0b1000;
				direct_count[x][y+1].second = next_count;
				coord.push(make_pair(x, y+1));
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << direct_count[i][j].second << " ";
		}
		cout << endl;
	}
}