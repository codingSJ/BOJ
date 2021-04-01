// base setting
#include <iostream>
#include <vector>


using namespace std;
using ll = long long;

int N, K, M, P;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K >> M;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (2 * K <= a)
            v.push_back(a - 2 * K);
        else if (K < a)
            v.push_back(a - K);
    }


    int l = 1;
    int r = 1000000000;
    P = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int tmp: v)
            cnt += tmp / mid;

        if (M <= cnt) {
            P = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << P;
}