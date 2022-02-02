// https://atcoder.jp/contests/abc231/tasks/abc231_d

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

    vector<int> degree(n, 0);
    UnionFind uf(n);
    int a, b;
    bool ok = true;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        degree[a-1] += 1;
        degree[b-1] += 1;
        if (degree[a-1] > 2 || degree[b-1] > 2 || uf.issanme(a-1, b-1)) {
            ok = false;
        }
        uf.unite(a-1, b-1);
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
}