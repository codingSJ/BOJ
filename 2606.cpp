// base setting
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int C, P;   //C:컴퓨터 수, P:컴퓨터 간 연결된 쌍의 수
vector<int> m[101];
bool isUsed[101] = {false};
int result = 0;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> C >> P;
    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }

    isUsed[1] = true;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int k = 0; k < m[u].size(); k++) {
            int v = m[u][k];
            if (isUsed[v] == false) {
                result++;
                isUsed[v] = true;
                q.push(v);
            }
        }
    }

    cout << result;
}