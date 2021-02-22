#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//#define div 1000000000
using namespace std;
using ll = long long;

int N;
vector<int> v;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i, j, a;
    int maxV;
    cin >> N;
    int dp[N];

    for (i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
        dp[i] = 0;
    }

    //기본값
    dp[0] = 1;
    for (i = 1; i < N; i++) {
        maxV = 0;
        for (j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                if (maxV < dp[j])
                    maxV = dp[j];
            }
        }
        dp[i] = maxV + 1;
    }

    maxV = dp[0];
    for (i = 1; i < N; i++) {
        if (maxV < dp[i])
            maxV = dp[i];
    }

    cout << maxV;
}