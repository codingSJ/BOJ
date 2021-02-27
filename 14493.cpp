#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i;
    int res = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    res = v[0].second + 1;
    for (i = 1; i < n; i++) {
        int div = v[i].first + v[i].second;
        if (v[i].second <= res % div && res % div < div) {
            res++;
        }
        else{
            res += v[i].second-res % div;
            res++;
        }
    }
    cout << res;
}