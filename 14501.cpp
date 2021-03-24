// base setting
#include <iostream>
#include <vector>


using namespace std;
using ll = long long;
#define INT_MAX   __INT_MAX__
#define INT_MIN   (-__INT_MAX__  -1)

int N;
vector<int> T, P;
int dp[15] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int t, p;
        cin >> t >> p;
        T.push_back(t);
        if (i + t <= N)
            P.push_back(p);
        else
            P.push_back(0);
    }


    //dp[i]: i일에 상담할 수 있는 경우 최대 수익
    dp[0] = P[0];
    for (int i = 1; i < N; i++) {
        int tmp = 0;
        for (int j = 0; j < i; j++) {
            if (T[j] + j <= i) {
                if (tmp < dp[j])
                    tmp = dp[j];
            }
        }
        dp[i] = P[i] + tmp;
    }


    int ret = 0;
    for(int i=0;i<N;i++)
        if(ret<dp[i])
            ret = dp[i];

    cout << ret;
}
