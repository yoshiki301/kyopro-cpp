//https://atcoder.jp/contests/typical90/tasks/typical90_l

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> _parent, _size;

    UnionFind (int n) : _parent(n, -1), _size(n, 1) {}

    int root (int x) {
        if (_parent[x] == -1) return x;
        else return _parent[x] = root(_parent[x]);
    }

    bool issanme (int x, int y) {
        return root(x) == root(y);
    }

    bool unite (int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) return false;

        if (_size[x] < _size[y]) swap(x, y);

        _parent[y] = x;
        _size[x] += _size[y];
        return true;
    }

    int size (int x) {
        return _size[root(x)];
    }
};

int coord_to_id (int x, int y, int h) {
	return x + y * h;
}

int main () {
    int h, w, q;
	cin >> h >> w;
	cin >> q;

    // 赤いマスで到達可能なマス同士をUnionFindで記録
	vector<vector<bool>> is_red(h, vector<bool>(w, false));
	UnionFind uf(h*w);

	int t, r1, c1, r2, c2;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> r1 >> c1;
			r1--; c1--;
			is_red[r1][c1] = true;
			if (r1 > 0) {
				if (is_red[r1-1][c1]) uf.unite(coord_to_id(r1, c1, h), coord_to_id(r1-1, c1, h));
			}
			if (r1 < h-1) {
				if (is_red[r1+1][c1]) uf.unite(coord_to_id(r1, c1, h), coord_to_id(r1+1, c1, h));
			}
			if (c1 > 0) {
				if (is_red[r1][c1-1]) uf.unite(coord_to_id(r1, c1, h), coord_to_id(r1, c1-1, h));
			}
			if (c1 < w-1) {
				if (is_red[r1][c1+1]) uf.unite(coord_to_id(r1, c1, h), coord_to_id(r1, c1+1, h));
			}
		} else {
			cin >> r1 >> c1 >> r2 >> c2;
			r1--; c1--; r2--; c2--;
			if (uf.issanme(coord_to_id(r1, c1, h), coord_to_id(r2, c2, h)) && is_red[r1][c1] && is_red[r2][c2]) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}