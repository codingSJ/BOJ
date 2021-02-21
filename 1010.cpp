#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, M, N;
    int i, j;
    int c[31][31] = {0};

    for (i = 1; i < 31; i++) {
        c[0][i] = c[i][0] = c[i][i] = 1;
        c[i][1] = i;
    }

    for (i = 1; i < 31; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    cin >> T;
    while(T--){
        cin >> N >> M;
        cout << c[M][N] << '\n';
    }
}