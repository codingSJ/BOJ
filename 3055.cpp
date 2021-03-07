// base setting
#include <iostream>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;

int R, C;
char map[50][50];
int num[50][50] = {0};
bool visited[50][50] = {false};
bool flag = false;
//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (0 <= ny && ny < R && 0 <= nx && nx < C) {
                //비어있는 곳이라면 채워준다. 고슴도치의 위치가 될 수도 있고 물의 위치가 될 수도 있다.
                if (visited[ny][nx] == false && map[ny][nx] == '.') {
                    map[ny][nx] = map[y][x];
                    num[ny][nx] = num[y][x] + 1;
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
                //고슴도치가 도착점에 도착했다면 끝낸다.
                if (visited[ny][nx] == false && map[ny][nx] == 'D') {
                    if (map[y][x] == 'S') {
                        num[ny][nx] = num[y][x] + 1;
                        flag = true;
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    int i, j, sx, sy, dx, arrX, arrY;
    cin.ignore();

    for (i = 0; i < R; i++) {
        string st;
        getline(cin, st);
        for (j = 0; j < C; j++) {
            map[i][j] = st[j];

            //고슴도치 위치 파악
            if (map[i][j] == 'S') {
                sy = i;
                sx = j;
            }
            //도착점 위치 파악
            if (map[i][j] == 'D') {
                arrX = j;
                arrY = i;
            }
            //물 위치를 큐에 삽입
            if (map[i][j] == '*') {
                q.push({i, j});
                visited[i][j] = true;
            }

        }
    }

    //물이 찰 예정인 곳도 고슴도치는 갈 수 없다. 따라서 map의 초기값에서 물의 위치들을 먼저 큐에 삽입 후
    //고슴도치의 위치는 가장 마지막에 큐에 넣어준다.
    //그럼 물이 먼저 퍼지게 되어 고슴도치가 갈 수 없는 예정일 곳을 미리 파악할 수 있다.
    q.push({sy, sx});

    bfs();

    if (flag)
        cout<<num[arrY][arrX];
    else
        cout << "KAKTUS";

}