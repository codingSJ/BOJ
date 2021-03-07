// base setting
#include <iostream>
#include <functional>
#include <stack>

using namespace std;
using ll = long long;

int N;
char map[101][101];
int m[101][101] = {0};
int m2[101][101] = {0};
bool visited[101][101];
bool visited2[101][101];
int frac = 1;
int frac2 = 1;
//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
stack<pair<int, int>> r, g, b1, rg, b2;

void bfs() {
    while (!b1.empty()) {
        int y = b1.top().first;
        int x = b1.top().second;
        b1.pop();

        visited[y][x] = true;
        if (m[y][x] == 0)
            m[y][x] = frac++;

        for (int k = 0; k < 4; k++) {
            int nY = y + dy[k];
            int nX = x + dx[k];

            if (1 <= nX && nX <= N && 1 <= nY && nY <= N) {
                if (visited[nY][nX] == false && map[nY][nX] == 'B') {
                    m[nY][nX] = m[y][x];
                    visited[nY][nX] = true;
                    b1.push({nY, nX});
                }
            }
        }
    }
    while (!r.empty()) {
        int y = r.top().first;
        int x = r.top().second;
        r.pop();
        visited[y][x] = true;
        if (m[y][x] == 0)
            m[y][x] = frac++;

        for (int k = 0; k < 4; k++) {
            int nY = y + dy[k];
            int nX = x + dx[k];

            if (1 <= nX && nX <= N && 1 <= nY && nY <= N) {
                if (visited[nY][nX] == false && map[nY][nX] == 'R') {
                    m[nY][nX] = m[y][x];
                    visited[nY][nX] = true;
                    r.push({nY, nX});
                }
            }
        }
    }

    while (!g.empty()) {
        int y = g.top().first;
        int x = g.top().second;
        g.pop();
        visited[y][x] = true;
        if (m[y][x] == 0)
            m[y][x] = frac++;

        for (int k = 0; k < 4; k++) {
            int nY = y + dy[k];
            int nX = x + dx[k];

            if (1 <= nX && nX <= N && 1 <= nY && nY <= N) {
                if (visited[nY][nX] == false && map[nY][nX] == 'G') {
                    m[nY][nX] = m[y][x];
                    visited[nY][nX] = true;
                    g.push({nY, nX});
                }
            }
        }
    }
}


void bfs2() {
    while (!b2.empty()) {
        int y = b2.top().first;
        int x = b2.top().second;
        b2.pop();

        visited2[y][x] = true;
        if (m2[y][x] == 0)
            m2[y][x] = frac2++;

        for (int k = 0; k < 4; k++) {
            int nY = y + dy[k];
            int nX = x + dx[k];

            if (1 <= nX && nX <= N && 1 <= nY && nY <= N) {
                if (visited2[nY][nX] == false && map[nY][nX] == 'B') {
                    m2[nY][nX] = m2[y][x];
                    visited2[nY][nX] = true;
                    b2.push({nY, nX});
                }
            }
        }
    }
    while (!rg.empty()) {
        int y = rg.top().first;
        int x = rg.top().second;
        rg.pop();
        visited2[y][x] = true;
        if (m2[y][x] == 0)
            m2[y][x] = frac2++;

        for (int k = 0; k < 4; k++) {
            int nY = y + dy[k];
            int nX = x + dx[k];

            if (1 <= nX && nX <= N && 1 <= nY && nY <= N) {
                if (visited2[nY][nX] == false && (map[nY][nX] == 'R' || map[nY][nX]=='G')) {
                    m2[nY][nX] = m2[y][x];
                    visited2[nY][nX] = true;
                    rg.push({nY, nX});
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin.ignore();

    for (int i = 1; i <= N; i++) {
        string st;
        getline(cin, st);

        for (int j = 1; j <= N; j++) {
            map[i][j] = st[j - 1];
            if (map[i][j] == 'B') {
                b1.push({i, j});
                b2.push({i, j});
            } else if (map[i][j] == 'R') {
                r.push({i, j});
                rg.push({i, j});
            } else {
                g.push({i, j});
                rg.push({i, j});
            }
        }
    }

    bfs();

    bfs2();

    frac--;
    frac2--;

    cout << frac << '\n' << frac2;
}