#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//#define div 1000000000
using namespace std;
using ll = long long;

int n, k;
vector<int> c;
int dp[10001] = {0};    //dp[i]: 동전을 조합해 i원을 만들 수 있는 경우의 수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    int i, j, a;
    for (i = 0; i < n; i++) {
        cin >> a;
        c.push_back(a);
    }

    sort(c.begin(), c.end());

    dp[0] = 1;

    for (i = 0; i < n; i++) {
        for (j = c[i]; j <= k; j++) {
            dp[j] += (dp[j - c[i]]);
        }
    }

    cout << dp[k];
}