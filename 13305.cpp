#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//#define div 1000000000
using namespace std;
using ll = long long;

int N;
ll price[100000] = {0};
ll dis[100000] = {0};
ll sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int i, j;
    ll a;
    for (i = 0; i < N - 1; i++) {
        cin >> a;
        dis[i] = a;
    }
    for (i = 0; i < N; i++) {
        cin >> a;
        price[i] = a;
    }

    //현 도시의 기름 가격보다 낮은 가격의 도시에 도착할 때까지 현 도시에서 기름을 채워간다.
    for (i = 0; i < N - 1; i++) {
        ll tmpDis = dis[i];
        //현 도시보다 기름이 비싼 도시들의 거리를 더한다.
        for (j = i + 1; j < N; j++) {
            if (price[i] <= price[j])
                tmpDis += dis[j];
            else
                break;
        }
        //현 도시의 기름값에 거리를 곱해 더한다.
        sum += tmpDis * price[i];
        i = j - 1;
    }
    cout << sum;
}