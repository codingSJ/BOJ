// base setting
#include <iostream>
#include <functional>
#include <string.h>
#include <stack>

using namespace std;
using ll = long long;

int w, h;
int map[50][50];
bool visited[50][50];
int result;
stack<pair<int, int>> q;

//좌상~우하
int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};

void dfs() {
    while (!q.empty()) {
        int y = q.top().first;
        int x = q.top().second;
        q.pop();

        for (int k = 0; k < 9; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (0 <= nx && nx < w && 0 <= ny && ny < h) {
                if (visited[ny][nx] == false && map[ny][nx] == 1) {
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

    cin >> w >> h;
    while (!(w == 0 && h == 0)) {
        //초기화
        for (int i = 0; i < 50; i++) {
            memset(map[i], 0, 50);
            memset(visited[i], false, 50);
        }
        result = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && visited[i][j] == false) {
                    result++;
                    q.push({i, j});
                    dfs();
                }
            }
        }
        cout << result << '\n';
        cin >> w >> h;
    }
}