#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int A[128][128] = {0};
int idx = 0;

// 모두 비어있으면 true, 그 외엔 false
bool check(int size, int x, int y) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (A[i][j])return false;
        }
    }
    return true;
}

void indexing(int size, int x, int y) {
    ++idx;
    int s = size / 2;
    if (check(s, x, y)) A[x + s - 1][y + s - 1] = idx;
    if (check(s, x, y + s)) A[x + s - 1][y + s] = idx;
    if (check(s, x + s, y)) A[x + s][y + s - 1] = idx;
    if (check(s, x + s, y + s)) A[x + s][y + s] = idx;
    if (size == 2) return;

    indexing(s, x, y);
    indexing(s, x + s, y);
    indexing(s, x, y + s);
    indexing(s, x + s, y + s);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, x, y, size;
    int i, j;
    cin >> k >> x >> y;
    size = (int) pow(2, k);
    A[y - 1][x - 1] = -1;

    indexing(size, 0, 0);
    for (i = size - 1; i >= 0; i--) {
        for (j = 0; j < size; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}