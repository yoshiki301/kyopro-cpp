// https://atcoder.jp/contests/abc218/tasks/abc218_e

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

int main () {
    int n, m;
    cin >> n >> m;
    vector<tuple<long long, int, int>> cab(m);
    int a, b;
    long long c;
    for (int i = 0; i< m; i++) {
        cin >> a >> b >> c;
        cab[i] = make_tuple(c, a, b);
    }
    sort(cab.begin(), cab.end());

    // unionfindで最小全域木を構築する
    // 負の辺はコストに関係なく加える
    long long res = 0;
    UnionFind uf(n);
    for (const auto& [c, a, b] : cab) {
        if (c < 0) {
            uf.unite(a-1, b-1);
        } else if (uf.issanme(a-1, b-1)) {
            res += c;
        } else {
            uf.unite(a-1, b-1);
        }
    }
    cout << res << endl;
}