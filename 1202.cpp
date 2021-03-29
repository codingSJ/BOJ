// base setting
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;


int N, K;
ll ret;
vector<pair<int, int>> v;
vector<int> c;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    ret = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        c.push_back(a);
    }

    sort(v.begin(), v.end());
    sort(c.begin(), c.end());

    int idx = 0;
    for (int i = 0; i < K; i++) {
        while (idx < N) {
            if (v[idx].first <= c[i]) {
                pq.push(v[idx].second);
                idx++;
            } else
                break;
        }

        if (!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret;
}