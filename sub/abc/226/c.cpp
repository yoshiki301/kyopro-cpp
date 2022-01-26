// https://atcoder.jp/contests/abc226/tasks/abc226_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int k;
    vector<long long> t(n);
    vector<vector<long long>> a(n);
    long long a_buff;
    bool seen[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> k;
        for (int j = 0; j < k; j++) {
            cin >> a_buff;
            a[i].push_back(a_buff-1);
        }
        seen[i] = false;
    }

    long long res = 0;
    priority_queue<int> que;
    que.push(n-1);
    seen[n-1] = true;
    while (!que.empty()) {
        int i = que.top();
        que.pop();
        res += t[i];
        for (const auto& ai : a[i]) {
            if (!seen[ai]) {
                que.push(ai);
                seen[ai] = true;
            }
        }
    }

    cout << res << endl;
}