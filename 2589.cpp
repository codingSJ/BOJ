// base setting
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>



using namespace std;

int map[50][50];
int N, M, rv;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

int dfs() {
    bool visited[50][50];
    int tmp[50][50] = {0};
    memset(visited, false, sizeof visited);
    visited[q.front().first][q.front().second] = true;
    int ret = 0;
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if (0 <= nx && nx < M && 0 <= ny && ny < N) {
                    if (!visited[ny][nx] && map[ny][nx]) {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                        tmp[ny][nx] = tmp[y][x] + 1;
                        if(tmp[ny][nx]>ret)
                            ret = tmp[ny][nx];
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string st;
        getline(cin, st);
        for (int j = 0; j < M; j++) {
            if (st[j] == 'L')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }

    rv = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j]) {
                q.push({i, j});
                int tmp = dfs();
                if (tmp > rv)
                    rv = tmp;
            }
        }
    }

    cout << rv;
}