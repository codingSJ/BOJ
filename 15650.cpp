#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N, M;
vector<int> p;

//value 이상의 값을 수열 p의 k번째 항으로 정하는 함수
void func(int k, int value) {
    //수열을 완성한 경우 출력해준다.
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << p[i] << " ";
        cout << '\n';
        return;
    }

    int i;

    //value 이상의 값들에 대해
    for (i = value; i <= N; i++) {
        //i를 수열에 넣는 경우
        p.push_back(i);
        func(k + 1, i + 1);

        //i를 수열에 넣지 않는 경우
        p.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    p.clear();

    //k의 초기값은 0, value의 초기값은 1로 둔다.
    func(0, 1);
}