// https://atcoder.jp/contests/abc217/tasks/abc217_e

#include <bits/stdc++.h>
using namespace std;

int main () {
    int Q;
    cin >> Q;

    // queueとpriority_queueを併用することで償却計算量がO(QlogQ)
    queue<long long> q;
    priority_queue<long long> pq;
    vector<long long> res;
    long long c, x;
    for (int i = 0; i < Q; i++) {
        cin >> c;
        if (c == 1) {
            cin >> x;
            q.push(x);
        } else if (c == 2) {
            if (pq.empty()) {
                res.push_back(q.front());
                q.pop();
            } else {
                res.push_back(-pq.top());
                pq.pop();
            }
        } else {
            while (!q.empty()) {
                pq.push(-q.front());
                q.pop();
            }
        }
    }

    for (const auto& r : res) cout << r << endl;
}