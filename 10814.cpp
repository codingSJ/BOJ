// base setting
#include <iostream>
#include <vector>
#include <functional>
#include <limits.h>

using namespace std;
using ll = long long;


int N;
vector<string> v[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int _min = INT_MAX;
    int _max = INT_MIN;
    for (int i = 0; i < N; i++) {
        int a;
        string b;
        cin >> a >> b;
        v[a].push_back(b);
        if (a < _min)
            _min = a;
        if (_max < a)
            _max = a;
    }

    for (int i = _min; i <= _max; i++) {
        if (v[i].size() == 0)
            continue;
        for (int j = 0; j < v[i].size(); j++) {
            cout << i << " " << v[i][j] << '\n';
        }
    }
}
