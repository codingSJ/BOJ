// base setting
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
#include <string.h>
#include <string>
#include <sstream>
#include <stdio.h>


using namespace std;
using ll = long long;
#define INT_MAX   __INT_MAX__
#define INT_MIN   (-__INT_MAX__  -1)

int N;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    while (true) {
        int a;
        cin >> a;
        if (a > 0) {
            if (q.size() < N)
                q.push(a);
        } else if (a == 0)
            q.pop();
        else
            break;
    }
    if (!q.empty()) {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    } else
        cout << "empty";
}