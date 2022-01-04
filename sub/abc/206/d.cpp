#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> _parent, _size;

    UnionFind (int n) : _parent(n, -1), _size(n, 1) {}

    int root (int x) {
        if (_parent[x] == -1) return x;
        else return _parent[x] = root(_parent[x]);
    }

    bool issanme(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) return false;

        if (_size[x] < _size[y]) swap(x, y);

        _parent[y] = x;
        _size[x] += _size[y];
        return true;
    }

    int size(int x) {
        return _size[root(x)];
    }
};

const int MAX_N = 2 * (1e5);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 置換するべき値のグループをunionfindで保持
    // unionfindの各sizeから1引いた値の和が最小の置換回数
    UnionFind uf(MAX_N);
    for (int i = 0; i < n/2; i++) {
        if (a[i] != a[n-i-1]) {
            uf.unite(a[i] - 1, a[n-i-1] - 1);
        }
    }

    set<int> parents;
    for (int i = 0; i < n/2; i++) {
        parents.insert(uf.root(a[i] - 1));
    }

    int res = 0;
    for (const auto& parent : parents) {
        res += uf.size(parent) - 1;
    }

    cout << res << endl;
}