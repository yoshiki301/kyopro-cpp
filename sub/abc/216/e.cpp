// https://atcoder.jp/contests/abc216/tasks/abc216_e

#include <bits/stdc++.h>
using namespace std;

vector<long long> a;

bool is_lower(long long b, long long k) {
    long long sum = 0;
    for (const auto& ai : a) {
        sum += max(ai - b, 0LL);
    }
    if (sum < k) {
        return true;
    } else {
        return false;
    }
}

long long binary_search(long long l, long long r, long long k) {
    long long left = l, right = r;

    while (right - left > 0) {
        long long mid = left + (right - left) / 2;
        if (is_lower(mid, k)) right = mid;
        else left = mid;
    }
    return right;
}

int main () {
    long long n, k;
    cin >> n >> k;
    
    a.resize(n);
    long long a_max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_max = max(a_max, a[i]);
    }
    long long boundary = binary_search(0, a_max, k);

    long long res = 0;
    for (const auto& ai : a) {
        if (k == 0) break;
        else if (boundary > ai) continue;
        else {
            long long count = min(ai - boundary, k);
            res += ai * count - count * (count - 1) / 2;
            k -= count;
        }
    }

    cout << res << endl;
}