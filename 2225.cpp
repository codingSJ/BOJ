#include <iostream>
#include <vector>
#include <algorithm>

#define div 1000000000
using namespace std;
using ll = long long;

int N, K;
ll dp[201][201] = {0};  //dp[N][K]: 0~N까지의 정수 K개를 사용해 N을 나타낼 수 있는 경우의 수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    int i, j, k;

    //dp 기본값
    for (i = 0; i < N + 1; i++) {
        dp[i][1] = 1;   //i를 1개의 정수로 나타내는 방법은 1개
    }
    for (i = 1; i < K + 1; i++) {
        dp[0][i] = 1;   //0을 i개의 정수로 나타내는 방법은 1개: 0=0+0+0+...+0
        dp[1][i] = i;   //1을 i개의 정수로 나타내는 방법은 1개의 1과 i-1개의 0의 조합 = iC1
    }

    //dp
    for (i = 2; i < N + 1; i++) {
        for (j = 1; j < K + 1; j++) {
            /*******************************************************************
             * dp[i][j] = dp[i][j-1]    //i를 j-1개의 정수로 표현한 경우에 0을 더한 경우
             *          + dp[i-1][j-1]  //i-1를 j-1개의 정수로 표현한 경우에 1을 더한 경우
             *          + dp[i-2][j-1]  //i-2를 j-1개의 정수로 표현한 경우에 2를 더한 경우
             *          + ...
             *          + dp[0][j-1]    //1
             *******************************************************************/
            ll sum = dp[i][j];
            for (k = 0; k <= i; k++)
                sum += (dp[k][j - 1] % div);
            dp[i][j] = sum % div;
        }
    }

    cout << dp[N][K];
}