// https://atcoder.jp/contests/abc212/tasks/abc212_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    // query2で加算された分をaddで管理
    long long add = 0;
    long long p, x;
    priority_queue<long long> pq;
    vector<long long> res;
    for (int i = 0; i < q; i++) {
        cin >> p;
        if (p == 1){
            cin >> x;
            pq.push(-(x - add));
        } else if (p == 2) {
            cin >> x;
            add += x;
        } else {
            res.push_back(-(pq.top()) + add);
            pq.pop();
        }
    }

    for (const auto& r: res) {
        cout << r << endl;
    }
}