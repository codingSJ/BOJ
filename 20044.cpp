#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, i, a;
    int min = INT32_MAX;
    cin >> n;
    vector<int> v;
    for (i = 0; i < 2 * n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (min > v.at(i) + v.at(2 * n - i - 1))
            min = v.at(i) + v.at(2 * n - i - 1);
    }
    cout << min << '\n';
}