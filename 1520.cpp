// base setting
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int N, M;
int map[500][500] = {0};
int cnt[500][500] = {0};
bool visited[500][500] = {false};
queue<pair<int, int>> q;
//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int dfs(int y, int x) {

    if (y == M - 1 && x == N - 1)
        return 1;

    else if (cnt[y][x] == -1) {
        cnt[y][x] = 0;

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (map[ny][nx] < map[y][x])
                    cnt[y][x] += dfs(ny, nx);
            }
        }
    }
    return cnt[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            cnt[i][j] = -1;
        }
    }

    cout << dfs(0, 0);
}