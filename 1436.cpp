// base setting
#include <iostream>

using namespace std;

int N, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    ret = 666;
    while (N) {
        int tmp = ret;
        while (tmp) {
            if (tmp % 1000 == 666) {
                N--;
                if (N == 0)
                    cout << ret;
                break;
            }
            tmp /= 10;
        }
        ret++;
    }
}
