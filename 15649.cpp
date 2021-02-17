#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
bool isUsed[9] = {false};   //수열에 사용되었는지 구분할 변수
vector<int> p;

/**
 * func(k)는 수열의 k번째 항을 정하는 함수
 */
void func(int k) {
    //수열을 완성한 경우 출력해준다.
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << p[i] << " ";
        cout << '\n';
        return;
    }

    int i;
    for (i = 1; i <= N; i++) {           //N개의 자연수 중
        if (isUsed[i] == false) {       //i가 아직 수열에 포함되지 않았다면
            //수열의 k번째 항으로 i를 정하고 k+1번 항을 구하는 경우와
            isUsed[i] = true;
            p.push_back(i);
            func(k + 1);

            //i를 수열에 포함시키지 않는 경우로 나눌 수 있다.
            isUsed[i] = false;
            p.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    p.clear();

    func(0);
}