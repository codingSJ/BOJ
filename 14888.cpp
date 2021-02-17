#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll maxValue, minValue;  //식에서 나올 수 있는 최댓값, 최솟값
int op[4] = {0};       //연산자 개수를 저장할 배열
vector<ll> v;          //수
vector<int> ops;        //한 식의 연산이 어떻게 진행되는지 확인
int N;

//k번째 연산자를 어떤 것으로 사용할지 정하는 함수
void func(int k) {
    //식을 완성했다면
    if (k == N - 1) {
        //연산을 진행한다. 초기값 res은 첫번째 수
        ll res = v[0];
        int i;

        for (i = 0; i < N - 1; i++) {
            //연산자에 맞게 계산을 진행한다.
            if (ops[i] == 0) {
                res += v[i + 1];
            } else if (ops[i] == 1) {
                res -= v[i + 1];
            } else if (ops[i] == 2) {
                res *= v[i + 1];
            } else {
                res /= v[i + 1];
            }
        }

        //최솟값, 최댓값과 비교 후 갱신
        if (res < minValue)
            minValue = res;
        if (maxValue < res)
            maxValue = res;

        return;
    }

    int i;

    //식을 만들어간다.
    for (i = 0; i < 4; i++) {
        //사용 가능한 연산자가 있다면
        if (op[i] > 0) {
            //k번째 연산자로 해당 연산자를 사용한 경우
            op[i]--;
            ops.push_back(i);
            func(k + 1);

            //k번째 연산자로 해당 연산자를 사용하지 않은 경우
            ops.pop_back();
            op[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //초기화
    maxValue = -1000000000;
    minValue = 1000000000;

    int i, tmp;
    v.clear();
    ops.clear();

    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    for (i = 0; i < 4; i++) {
        cin >> op[i];
    }

    func(0);

    cout << maxValue << '\n';
    cout << minValue;
}