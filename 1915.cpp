#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//#define div 1000000000
using namespace std;
using ll = long long;

int N, M;
int b[1000][1000] = {0};
int dp[1000][1000] = {0};   //dp[i][j]: (i,j)를 우하단 꼭지점으로 갖는, 만들 수 있는 최대 정사각형의 한 변
int maxL = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cin.ignore();

    int i, j;
    string st;
    for (i = 0; i < N; i++) {
        getline(cin, st);
        for (j = 0; j < M; j++) {
            if (st[j] == '0')
                b[i][j] = 0;
            else
                b[i][j] = 1;
        }
    }

    //기본값
    for (i = 0; i < N; i++) {
        if (b[i][0] == 1)
            dp[i][0] = 1;
        if (maxL < dp[i][0])
            maxL = dp[i][0];
    }
    for (j = 0; j < M; j++) {
        if (b[0][j] == 1)
            dp[0][j] = 1;
        if (maxL < dp[0][j])
            maxL = dp[0][j];
    }


    //dp
    for (i = 1; i < N; i++) {
        for (j = 1; j < M; j++) {
            if (b[i][j] == 0)
                dp[i][j] = 0;
            else {
                int min1 = min(dp[i - 1][j], dp[i][j - 1]);
                int min2 = min(min1, dp[i - 1][j - 1]);
                dp[i][j] = min2 + 1;
            }
            if (maxL < dp[i][j])
                maxL = dp[i][j];
        }
    }

    cout << maxL * maxL;
}