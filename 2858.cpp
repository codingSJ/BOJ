// base setting
#include <iostream>

#include <math.h>

using namespace std;
using ll = long long;
#define INT_MAX   __INT_MAX__
#define INT_MIN   (-__INT_MAX__  -1)

int R, B;
int L, W;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> B;

    //R+B = L*W
    //R=2(L+W-2)
    //LW = 2L+2W+B-4
    //(L-2)(W-2) = B
    for (L = 3; L <= sqrt(B) + 2; L++) {
        W = B / (L - 2) + 2;
        if (L * W == B + R && (L - 2) * (W - 2) == B)
            break;
    }

    if (L < W)
        swap(L, W);
    cout << L << " " << W;
}
