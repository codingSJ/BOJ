#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> v;
int dp[101][100001] = {0};  //dp[n][weight]: n번 째 아이템을 넣은 경우 무게 weight 내에서 가질 수 있는 최대 가치


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i, j, k, weight, value;
    int maxValue;
    cin >> N >> K;

    for (i = 0; i < N; i++) {
        cin >> weight >> value;
        v.push_back({weight, value});
    }

    //무게의 오름차순으로 정렬
    sort(v.begin(), v.end());

    //dp 기본 값. 0번 째 아이템을 넣은 후
    for (i = v[0].first; i < K + 1; i++)
        dp[0][i] = v[0].second;

    //dp
    for (i = 1; i < N; i++) {
        for (j = 0; j < K + 1; j++) {
            //i번째 아이템을 넣을 수 있는 경우
            if (j >= v[i].first) {
                //i번째 아이템을 넣을 경우(dp[i - 1][j - v[i].first] + v[i].second)와
                //i번째 아이템을 넣지 않을 경우(dp[i-1][j])를 비교 후 큰 값으로 갱신
                dp[i][j] = dp[i - 1][j - v[i].first] + v[i].second > dp[i - 1][j]
                           ? dp[i - 1][j - v[i].first] + v[i].second
                           : dp[i - 1][j];
            }
                //i번째 아이템을 넣지 못하는 경우
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N - 1][K];
}