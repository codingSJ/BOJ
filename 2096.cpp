#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//#define div 1000000000
using namespace std;
using ll = long long;

int N;
int v[100000][3] = {0}; //입력값
int dpMax1[3] = {0};
int dpMax2[3] = {0};
int dpMin1[3] = {0};
int dpMin2[3] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i, j, a, b, c, tmp;
    int minV, maxV;

    cin >> N;

    for (i = 0; i < N; i++) {
        cin >> a >> b >> c;
        v[i][0] = a;
        v[i][1] = b;
        v[i][2] = c;
    }

    //기본값: 1번쨰 줄
    for (i = 0; i < 3; i++) {
        dpMax2[i] = v[0][i];
        dpMin2[i] = v[0][i];
    }

    //2번째 줄부터 dp 시작
    //dpMax1,dpMin1은 i-1번째 줄을, dpMax2,dpMin2는 i번째 줄을 의미한다.
    for (i = 1; i < N; i++) {
        //i-1, i번 째 줄을 갱신한다.
        for (j = 0; j < 3; j++) {
            dpMax1[j] = dpMax2[j];
            dpMin1[j] = dpMin2[j];
        }

        //인덱스에 따라 다른 값들을 비교해 최대/최소를 결정짓는다.
        dpMax2[0] = max(dpMax1[0], dpMax1[1]) + v[i][0];
        dpMax2[2] = max(dpMax1[1], dpMax1[2]) + v[i][2];
        tmp = max(dpMax1[0], dpMax1[1]);
        dpMax2[1] = max(tmp, dpMax1[2]) + v[i][1];

        dpMin2[0] = min(dpMin1[0], dpMin1[1]) + v[i][0];
        dpMin2[2] = min(dpMin1[1], dpMin1[2]) + v[i][2];
        tmp = min(dpMin1[0], dpMin1[1]);
        dpMin2[1] = min(tmp, dpMin1[2]) + v[i][1];
    }

    minV = dpMin2[0];
    maxV = dpMax2[0];
    for (i = 1; i < 3; i++) {
        if (dpMin2[i] < minV)
            minV = dpMin2[i];
        if (maxV < dpMax2[i])
            maxV = dpMax2[i];
    }

    cout << maxV << " " << minV;
}