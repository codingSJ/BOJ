// base setting
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;

int N;
int m[26][26] = {0};
bool visited[26][26] = {false};
vector<int> result;
//상, 하, 좌, 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


void bfs(int y, int x) {
    queue<pair<int, int>> q;    //<y,x>
    q.push({y, x});
    visited[y][x] = true;

    int cnt = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int newY = y + dy[k];
            int newX = x + dx[k];

            if (1 <= newX && newX <= N && 1 <= newY && newY <= N) {
                if (visited[newY][newX] == false && m[newY][newX] == 1) {
                    q.push({newY, newX});
                    visited[newY][newX] = true;
                    cnt++;
                }
            }
        }
    }
    result.push_back(cnt);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin.ignore();

    int i, j;
    for (i = 1; i <= N; i++) {
        string st;
        getline(cin, st);

        for (j = 1; j <= N; j++) {
            if (st[j - 1] == '1')
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }

    for (i = 1; i < N + 1; i++) {
        for (j = 1; j < N + 1; j++) {
            if (visited[i][j] == false && m[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (i = 0; i < result.size(); i++)
        cout << result[i] << '\n';

}