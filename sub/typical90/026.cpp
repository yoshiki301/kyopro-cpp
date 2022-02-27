// https://atcoder.jp/contests/typical90/tasks/typical90_z

#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>());

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}

    // 木は二部グラフなので2彩色できる
	vector<int> color(n, -1);
	queue<int> que;
	color[0] = 0;
	que.push(0);

	map<int, int> color_count;
	color_count[0] = 1;
	color_count[1] = 0;
	while (!que.empty()) {
		int current = que.front();
		que.pop();
		for (int neighbor : g[current]) {
			if (color[neighbor] == -1) {
				color[neighbor] = color[current] ^ 1;
				color_count[color[neighbor]] += 1;
				que.push(neighbor);
			}
		}
	}

	int target_color;
	if (color_count[0] >= color_count[1]) target_color = 0;
	else target_color = 1;

	int print_count = 0;
	for (int i = 0; i < n; i++) {
		if (color[i] == target_color) {
			cout << i+1 << " ";
			print_count += 1;
			if (print_count == n / 2) break;
		}
	}
	cout << endl;
}