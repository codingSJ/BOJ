#include <iostream>
#include <algorithm>
#include <vector>

#define INT_MIN   (-__INT_MAX__  -1)
using namespace std;
using ll = long long;

int R, C;
bool isUsed[26] = {false};
char b[21][21];
int cnt;
vector<char> v;

//현 (r,c)에서 더 진행이 가능한지 확인하는 함수
bool isAvailable(int r, int c){
    char ch;

    //상 방향으로 갈 수 있다면 true
    ch = b[r - 1][c];
    if (isUsed[(int) ch - 65] == false && 1 < r) return true;

    //하 방향으로 갈 수 있다면 true
    ch = b[r + 1][c];
    if (isUsed[(int) ch - 65] == false && r < R) return true;

    //좌 방향으로 갈 수 있다면 true
    ch = b[r][c - 1];
    if (isUsed[(int) ch - 65] == false && 1 < c) return true;

    //우 방향으로 갈 수 있다면 true
    ch = b[r][c + 1];
    if (isUsed[(int) ch - 65] == false && c < C) return true;

    //4방향 모두 갈 수 없다면 false
    return false;
}

void func(int r, int c) {
    //더 이상 갈 수 없는 경우
    if (isAvailable(r, c) == false) {
        //cnt를 비교 후 갱신
        if(cnt<v.size())
            cnt = v.size();

        return;
    }

    char ch;

    //상 방향으로 갈지 정한다
    ch = b[r - 1][c];
    if (isUsed[(int) ch - 65] == false && 1 < r) {
        //상 방향으로 가는 경우
        isUsed[(int) ch - 65] = true;
        v.push_back(ch);
        func(r - 1, c);

        //상 방향으로 가지 않는 경우
        isUsed[(int) ch - 65] = false;
        v.pop_back();
    }

    //하 방향으로 갈지 정한다
    ch = b[r + 1][c];
    if (isUsed[(int) ch - 65] == false && r < R) {
        //하 방향으로 가는 경우
        isUsed[(int) ch - 65] = true;
        v.push_back(ch);
        func(r + 1, c);

        //하 방향으로 가지 않는 경우
        isUsed[(int) ch - 65] = false;
        v.pop_back();
    }

    //좌 방향으로 갈지 정한다
    ch = b[r][c - 1];
    if (isUsed[(int) ch - 65] == false && 1 < c) {
        //좌 방향으로 가는 경우
        isUsed[(int) ch - 65] = true;
        v.push_back(ch);
        func(r, c - 1);

        //좌 방향으로 가지 않는 경우
        isUsed[(int) ch - 65] = false;
        v.pop_back();
    }

    //우 방향으로 갈지 정한다
    ch = b[r][c + 1];
    if (isUsed[(int) ch - 65] == false && c < C) {
        //우 방향으로 가는 경우
        isUsed[(int) ch - 65] = true;
        v.push_back(ch);
        func(r, c + 1);

        //우 방향으로 가지 않는 경우
        isUsed[(int) ch - 65] = false;
        v.pop_back();
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    //b 초기화
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 21; j++)
            b[i][j] = '\0';
    }
    v.clear();

    cin >> R >> C;
    cin.ignore();

    for (i = 1; i <= R; i++) {
        string st;
        getline(cin, st);
        for (j = 1; j <= st.length(); j++) {
            b[i][j] = st[j - 1];
        }
    }

    //기본값 설정
    isUsed[(int) b[1][1] - 65] = true;
    v.push_back(b[1][1]);
    cnt = 1;

    func(1, 1);

    cout << cnt << '\n';
}