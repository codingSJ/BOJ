#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N, M;
vector<int> p;

//수열p의 k번째 항으로 value를 넣을지 결정하는 함수
void func(int k, int value) {
    //수열이 완성된 경우
    if (k == M) {
        for (int i = 0; i < k; i++)
            cout << p[i] << " ";
        cout << '\n';
        return;
    }

    int i;
    for (i = value; i <= N; i++) {
        //i를 수열 p에 넣을 경우
        p.push_back(i);
        func(k + 1, i);

        //i를 수열 p에 넣지 않을 경우
        p.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;
    p.clear();

    func(0, 1);
}