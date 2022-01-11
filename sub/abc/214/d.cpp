// https://atcoder.jp/contests/abc214/tasks/abc214_d

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

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> edge(n-1);
    for (auto& [w, u, v] : edge) {
        cin >> u >> v >> w;
        u -= 1;
        v -= 1;
    }
    sort(edge.begin(), edge.end());

    UnionFind uf(n);
    long long res = 0;
    for (const auto& [w, u, v] : edge) {
        res += (long long) w * uf.size(u) * uf.size(v);
        uf.unite(u, v);
    }

    cout << res << endl;
}