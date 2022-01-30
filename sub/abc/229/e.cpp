// https://atcoder.jp/contests/abc229/tasks/abc229_e

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

    int a, b;
    map<int, vector<int>> a_to_b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a_to_b[a-1].push_back(b-1);
    }

    // 頂点を取り除く手順を逆から行って連結成分数を数える
    // i = n, ..., 1の順でUnionFind木に頂点を追加し, rootの変化数を数える
    UnionFind uf(n);
    vector<int> res(n);
    res[n-1] = 0;
    for (int i = n-1; i > 0; i--) {
        set<int> removal, additional;
        for (const auto& neighbor : a_to_b[i]) {
            removal.insert(uf.root(neighbor));
        }
        for (const auto& neighbor : a_to_b[i]) {
            uf.unite(i, neighbor);
        }
        additional.insert(uf.root(i));
        for (const auto& neighbor : a_to_b[i]) {
            additional.insert(uf.root(neighbor));
        }
        res[i-1] = res[i] - removal.size() + additional.size();
    }

    for (int i = 0; i < n; i++) cout << res[i] << endl;
}