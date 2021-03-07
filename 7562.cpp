// base setting
#include <iostream>
#include <functional>
#include <string.h>
#include <queue>

using namespace std;

int T, I, sX, sY, eX, eY;
int map[300][300];
bool visited[300][300];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};
queue<pair<int, int>> q;

void dfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        visited[y][x] = true;
        if (y == eY && x == eX)
            return;


        for (int k = 0; k < 8; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (0 <= nx && nx < I && 0 <= ny && ny < I) {
                if (visited[ny][nx] == false) {
                    visited[ny][nx] = true;
                    map[ny][nx] = map[y][x] + 1;
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
        cin >> I;
        for (int i = 0; i < 300; i++) {
            memset(map[i], 0, sizeof(int) * 300);
            memset(visited[i], false, sizeof(bool) * 300);
        }

        cin >> sY >> sX;
        cin >> eY >> eX;

        q.push({sY, sX});

        dfs();

        while (!q.empty())
            q.pop();

        cout << map[eY][eX] << '\n';
    }
}