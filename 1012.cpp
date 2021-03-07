// base setting
#include <iostream>
#include <functional>
#include <string.h>
#include <stack>

using namespace std;
using ll = long long;

int N, M, K, T;
int cnt;
bool map[50][50];
bool visited[50][50];
int num[50][50];
stack<pair<int, int>> q;

//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
    while (!q.empty()) {
        int y = q.top().first;
        int x = q.top().second;
        visited[y][x] = true;
        q.pop();

        if (num[y][x] == 0)
            num[y][x] = ++cnt;

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (0 <= nx && nx < M && 0 <= ny && ny < N) {
                if (visited[ny][nx] == false && map[ny][nx] == true) {
                    num[ny][nx] = num[y][x];
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        for (int i = 0; i < 50; i++) {
            memset(map[i], false, sizeof(bool) * 50);
            memset(visited[i], false, sizeof(bool) * 50);
            memset(num[i], 0, sizeof(int) * 50);
        }

        cin >> M >> N >> K;
        cnt = 0;
        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            map[b][a] = true;
            if (map[b][a])
                q.push({b, a});
        }

        bfs();
        cout << cnt << '\n';
    }
}