// https://atcoder.jp/contests/abc226/tasks/abc226_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> coords(n);
    long long x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coords[i] = make_pair(x, y);
    }

    set<pair<long long, long long>> magics;
    long long dx, dy, g;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            auto coord1 = coords[i], coord2 = coords[j];
            dx = coord1.first - coord2.first;
            dy = coord1.second - coord2.second;
            g = gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;
            magics.insert(make_pair(dx, dy));
            magics.insert(make_pair(-dx, -dy));
        }
    }

    cout << magics.size() << endl;
}