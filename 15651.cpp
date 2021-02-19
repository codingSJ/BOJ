#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N, M;
vector<int> p;

//k를 수열 p에 넣을지 정하는 함수
void func(int k) {
    //수열이 완성된 경우
    if (k == M) {
        for (int i = 0; i < k; i++)
            cout << p[i] << " ";
        cout << '\n';
        return;
    }

    int i;
    for (i = 1; i <= N; i++) {
        //i를 수열 p에 넣을 경우
        p.push_back(i);
        func(k + 1);

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

    func(0);
}