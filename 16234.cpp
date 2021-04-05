// base setting
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>



using namespace std;

int N, L, R, rv;
int map[50][50];
bool visited[50][50] = {false};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool flag;
queue<pair<int, int>> q;

void dfs() {
    vector<pair<int, int>> v;
    v.clear();

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        v.push_back({y, x});

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (!visited[ny][nx] && L <= abs(map[y][x] - map[ny][nx]) && abs(map[y][x] - map[ny][nx]) <= R) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    flag = true;
                }
            }
        }
    }

    if (flag) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += map[v[i].first][v[i].second];
        }

        for (int i = 0; i < v.size(); i++) {
            map[v[i].first][v[i].second] = sum / v.size();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    while (1) {
        for (int i = 0; i < N; i++)
            memset(visited[i], false, sizeof visited[i]);

        flag = false;
        int y, x;
        for (y = 0; y < N; y++) {
            for (x = 0; x < N; x++) {
                if (!visited[y][x]) {
                    q.push({y, x});
                    visited[y][x] = true;
                    dfs();
                }
            }
        }

        if (!flag)
            break;
        rv++;
    }

    cout << rv;
}