// base setting
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <limits.h>

using namespace std;
using ll = long long;

int N;
map<double, ll> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int i;
    for (i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        //똑같은 기울기가 없는 경우
        auto itr = m.find((double) a / (double) b);
        if (itr == m.end()) {
            m.insert({(double) a / (double) b, 1});
        }
            //똑같은 기울기 존재
        else {
            itr->second++;
        }
    }

    ll result = 0;
    map<double, ll>::iterator iter;

    for (iter = m.begin(); iter != m.end(); iter++) {
        //같은 기울기에 포함된 사람 수 * 다른 기울기에 포함된 사람 수들의 합
        result += iter->second * (N - iter->second);
    }

    //a->b에게 연락,b->a에게 연락하는 게 중복되어 있으므로 나누기 2
    cout << result / 2;
}