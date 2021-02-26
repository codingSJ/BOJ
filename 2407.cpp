#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

int N, M;
vector<string> C[101][101]; //조합 값을 저장할 배열

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    int i, j;

    //초기값 0C0 = 0, iC0 = iCi = 1 저장
    C[0][0].push_back("0");
    for (i = 1; i < N + 1; i++) {
        C[i][0].push_back("1");
        C[i][i].push_back("1");
    }

    for (i = 2; i < N + 1; i++) {
        for (j = 1; j < min(i, M + 1); j++) {
            //C[i][j] = C[i-1][j] + C[i-1][j-1] 이용
            vector<string> s1 = C[i - 1][j];
            vector<string> s2 = C[i - 1][j - 1];
            int tmp = 0;

            //s1과 s2를 뒤에서부터 뽑아 C[i][j]에 push해준다.
            while (!s1.empty() && !s2.empty()) {
                //tmp는 s1과 s2를 한자리씩 더할 임시값
                tmp += stoi(s1.back()) + stoi(s2.back());
                //tmp가 10보다 커지는 경우 일의 자리만 넣어준다.
                C[i][j].push_back(to_string(tmp % 10));
                tmp /= 10;
                s1.pop_back();
                s2.pop_back();
            }

            while (!s1.empty()) {
                tmp += stoi(s1.back());
                C[i][j].push_back(to_string(tmp % 10));
                tmp /= 10;
                s1.pop_back();
            }

            while (!s2.empty()) {
                tmp += stoi(s2.back());
                C[i][j].push_back(to_string(tmp % 10));
                tmp /= 10;
                s2.pop_back();
            }
            //더할 때 오른 자리가 생긴 경우 더해준다.
            if (tmp)
                C[i][j].push_back(to_string(tmp));

            //지금까지 C[i][j]는 반대로 계산되었으므로 한 번 뒤집어준다.
            reverse(C[i][j].begin(), C[i][j].end());
        }
    }

    //앞에서부터 출력을 하기 위해 뒤집어준다.
    reverse(C[N][M].begin(), C[N][M].end());
    while (!C[N][M].empty()) {
        cout << C[N][M].back();
        C[N][M].pop_back();
    }
}