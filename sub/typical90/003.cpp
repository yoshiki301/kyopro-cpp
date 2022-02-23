// https://atcoder.jp/contests/typical90/tasks/typical90_c

#include <bits/stdc++.h>
using namespace std;

constexpr int DIST_MAX = 1e6;

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

    // 距離計算を1回を行い, 木の頂点を見つける
	vector<int> dist(n, DIST_MAX);
	dist[0] = 0;
	queue<int> que;
	que.push(0);
	while (!que.empty()) {
		int current = que.front();
		que.pop();
		for (const auto& neighbor : g[current]) {
			if (dist[neighbor] > dist[current] + 1) {
				dist[neighbor] = dist[current] + 1;
				que.push(neighbor);
			}
		}
	}

	int max_dist = 0, max_dist_index = 0;
	for (int i = 0; i < n; i++) {
		if (max_dist < dist[i]) {
			max_dist = dist[i];
			max_dist_index = i;
		}
	}

    // 頂点を起点に再度距離計算を行い, 最長距離を求める
	int path_dist_max = 0;
	vector<int> dist_second(n, DIST_MAX);
	dist_second[max_dist_index] = 0;
	que.push(max_dist_index);
	while (!que.empty()) {
		int current = que.front();
		que.pop();
		for (const auto& neighbor : g[current]) {
			if (dist_second[neighbor] > dist_second[current] + 1) {
				dist_second[neighbor] = dist_second[current] + 1;
				que.push(neighbor);
				path_dist_max = max(path_dist_max, dist_second[neighbor]);
			}
		}
	}

	cout << path_dist_max + 1 << endl;
}