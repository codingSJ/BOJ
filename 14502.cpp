// base setting
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int map[8][8];
bool isUsed[8][8];
int N, M, rv;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>> q;
vector<pair<int, int>> v;

int bfs() {
    bool visited[8][8];
    int tmpMap[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            tmpMap[i][j] = map[i][j];
    int ret = 0;
    memset(visited, false, sizeof visited);

    queue<pair<int, int>> qtmp;
    int qsize = q.size();
    for (int i = 0; i < qsize; i++) {
        qtmp.push(q.front());
        q.push(q.front());
        q.pop();
    }

    visited[qtmp.front().first][qtmp.front().second] = true;

    while (!qtmp.empty()) {
        int y = qtmp.front().first;
        int x = qtmp.front().second;
        qtmp.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (0 <= nx && nx < M && 0 <= ny && ny < N) {
                if (!visited[ny][nx] && !tmpMap[ny][nx]) {
                    visited[ny][nx] = true;
                    qtmp.push({ny, nx});
                    tmpMap[ny][nx] = 2;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!tmpMap[i][j])
                ret++;
        }
    }
    return ret;
}

void solve(int k, int value) {
    if (k == 3) {
        int tmp = bfs();
        if (tmp > rv)
            rv = tmp;
        return;
    } else if (value == v.size())
        return;

    for (int i = value; i < v.size(); i++) {
        if (!isUsed[v[i].first][v[i].second]) {
            isUsed[v[i].first][v[i].second] = true;
            map[v[i].first][v[i].second] = 1;
            solve(k + 1, i + 1);

            isUsed[v[i].first][v[i].second] = false;
            map[v[i].first][v[i].second] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)
                v.push_back({i, j});
            else if (map[i][j] == 2)
                q.push({i, j});
        }
    }
    rv = 0;

    solve(0, 0);

    cout << rv;
}