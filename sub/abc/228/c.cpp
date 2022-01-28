// https://atcoder.jp/contests/abc228/tasks/abc228_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    int p_val[n];
    int p1, p2, p3;
    for (int i = 0; i < n; i++) {
        cin >> p1 >> p2 >> p3;
        p[i] = p1 + p2 + p3;
        p_val[i] = p1 + p2 + p3;
    }
    sort(p.begin(), p.end(), greater<>());
    int p_k = p[k-1];

    for (int i = 0; i < n; i++) {
        if (p_val[i] + 300 >= p_k) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}