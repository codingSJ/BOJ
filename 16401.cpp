#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m, n, i, cnt;            // m: 조카 수, n: 과자 수, cnt: 같은 길이의 과자 조각 수
    /*
     * res: 최종 나눠주는 과자 길이
     * start: 나눌 수 있는 과자 최소 길이
     * mid: 임시로 나눠볼 길이-> (start+end)/2
     * end: 나눌 수 있는 과자 최장 길이
     */
    ll res, start, mid, end;

    cin >> m >> n;

    vector<ll> snack(n);

    end = 0;
    for (i = 0; i < n; i++) {
        cin >> snack[i];
        if (end < snack[i])
            end = snack[i];
    }


    start = 1;    // 나눠줄 수 있는 최소 길이
    res = 0;
    while (start <= end) {
        mid = (start + end) / 2;      // 임시로 나눌 길이

        cnt = 0;
        for (i = 0; i < n; i++) {
            cnt += (snack[i] / mid);
        }

        if (cnt < m) {    // 나뉜 과자 수가 조카 수보다 적어 나눠줄 수 없는 경우
            end = mid - 1;
        } else {       // 나눠는 줄 수 있는 경우
            res = mid;    // 최종적으로 나눠주는 과자 길이 갱신
            start = mid + 1;
        }
    }
    cout << res;
}
