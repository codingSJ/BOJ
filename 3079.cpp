#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int m, n, i;   // 친구 m명, 입국심사 n개
    ll start, end, mid, res, cnt;
    ll max = 0;
    cin >> n >> m;
    vector<ll> t(n);
    for (i = 0; i < n; i++) {
        cin >> t[i];
        if (max < t[i])
            max = t[i];
    }

    start = 1;
    end = m * max;  // 최대로 오래 걸릴 시간
    res = end;      // 총 걸린시간 기본값

    while(start<end){
        mid = (start + end) / 2;

        cnt = 0;    // 심사대를 통과한 사람 수
        for (i = 0; i < n; i++)
            cnt += (mid / t[i]);    // mid 동안 통과한 사람 수

        // mid 시간 동안 모두 통과하지 못한 경우
        if(cnt < m){
            start = mid + 1;
        }
        // mid 시간 내에 모두 통과한 경우
        else{
            res = min(res, mid);    // 총 걸린 시간을 갱신
            end = mid;      // 더 짧은 시간에 가능한지 확인
        }
    }
    cout << res;
}