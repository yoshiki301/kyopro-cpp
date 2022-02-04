// https://atcoder.jp/contests/abc233/tasks/abc233_d

#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n), cumsum(n+1, 0);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        cumsum[i+1] = cumsum[i] + a[i];
    }

    map<long long, long long> mem_sum;
    long long res = 0;
    for (long long i = 1; i <= n; i++) {
        mem_sum[cumsum[i-1]] += 1;
        res += mem_sum[cumsum[i] - k];
    }
    cout << res << endl;
}