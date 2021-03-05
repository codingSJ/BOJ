// base setting
#include <iostream>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;

int N, M;
int map[1001][1001] = {0};
bool visited[1001][1001] = {false};
queue<pair<int, int>> q;

//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void DFS() {
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nY = yy + dy[k];
            int nX = xx + dx[k];

            if (1 <= nX && nX <= M && 1 <= nY && nY <= N) {
                if (visited[nY][nX] == true) {
                    map[nY][nX] = map[nY][nX] < map[yy][xx] + 1 ? map[nY][nX] : map[yy][xx] + 1;
                }
                if (visited[nY][nX] == false && map[nY][nX] != -1) {
                    visited[nY][nX] = true;
                    q.push({nY, nX});
                    map[nY][nX] = map[yy][xx] + 1;
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;
    bool flag = true;

    int i, j;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = true;
            }
            if (map[i][j] == 0)
                flag = false;
        }
    }

    if (flag) {
        cout << 0;
        return 0;
    }

    DFS();

    int max = 0;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            if (map[i][j] == 0) {
                max = 0;
                break;
            }
            if (map[i][j] > max)
                max = map[i][j];
        }
        if (max == 0)
            break;
    }

    cout << max - 1;
}