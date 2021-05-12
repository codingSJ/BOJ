// base setting
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
#include <string.h>
#include <string>
#include <sstream>
#include <stdio.h>


using namespace std;
using ll = long long;
#define INT_MAX   __INT_MAX__
#define INT_MIN   (-__INT_MAX__  -1)

int L;
int ML, MK;
int C, tmpC;
int rv;
vector<int> Z;
deque<int> d;   //폭탄이 사용된 위치

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> L;
    cin >> ML >> MK;
    cin >> C;
    Z.push_back(0);

    for (int i = 1; i <= L; i++) {
        int a;
        cin >> a;
        Z.push_back(a);
    }

    rv = 1;
    tmpC = 0;
    for (int i = 1; i <= L; i++) {
        if (d.size() > C) {
            rv = 0;
            break;
        }

        while (!d.empty() && ML <= i - d.front())   //현재 좀비가 ML 범위 내에 있는 동안 터진 폭탄만 남기기
            d.pop_front();

        //기관총 맞는 길이
        int len = ML;
        if (i <= ML)
            len = i;

        if (Z[i] > MK * (len - d.size())) {
            d.push_back(i);
            tmpC++;
        }
    }

    if (tmpC > C)
        rv = 0;

    if (rv)
        cout << "YES";
    else
        cout << "NO";
}