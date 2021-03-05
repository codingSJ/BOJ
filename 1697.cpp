// base setting
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int N, K;
int cnt[100001] = {0};
bool visited[100001] = {false};
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int u = q.front();
        visited[u] = true;
        q.pop();

        if (u == K)
            break;

        if (2 * u <= 100000) {
            if (visited[2 * u] == false) {
                visited[2 * u] = true;
                cnt[2 * u] = cnt[u] + 1;
                q.push(2 * u);

            }
            else {
                cnt[2 * u] = cnt[2 * u] < cnt[u] + 1 ? cnt[2 * u] : cnt[u] + 1;
            }
        }

        if (0 < u) {
            if (visited[u - 1] == false) {
                visited[u - 1] = true;
                cnt[u - 1] = cnt[u] + 1;
                q.push(u - 1);
            }
            else {
                cnt[u - 1] = cnt[u - 1] < cnt[u] + 1 ? cnt[u - 1] : cnt[u] + 1;
            }
        }
        if (u < 100000) {
            if (visited[u + 1] == false) {
                visited[u + 1] = true;
                cnt[u + 1] = cnt[u] + 1;

                q.push(u + 1);
            }
            else {
                cnt[u + 1] = cnt[u + 1] < cnt[u] + 1 ? cnt[u + 1] : cnt[u] + 1;
            }
        }


    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    q.push(N);

    bfs();

    cout << cnt[K];
}