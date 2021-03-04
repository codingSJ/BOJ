// base setting
#include <iostream>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;

int N, M;
int m[101][101];
int cnt[101][101] = {0};
bool visited[101][101] = {false};

//상, 하, 좌, 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cin.ignore();

    int i, j;
    for (i = 1; i <= N; i++) {
        string st;
        getline(cin, st);
        for (j = 1; j <= M; j++) {
            if (st[j - 1] == '1')
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }

    q.push({1, 1});
    cnt[1][1] = 1;
    visited[1][1] = true;

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        if (i == N && j == M)
            break;

        for (int k = 0; k < 4; k++) {
            int newX = j + dx[k];
            int newY = i + dy[k];

            if (1 <= newX && newX <= M && 1 <= newY && newY <= N) {
                if (visited[newY][newX] == false && m[newY][newX] == 1) {
                    q.push({newY, newX});
                    cnt[newY][newX] = cnt[i][j] + 1;
                    visited[newY][newX] = true;
                }
            }
        }
    }

    cout << cnt[N][M];
}