#include <iostream>
#include <algorithm>
#include <vector>

#define INT_MIN   (-__INT_MAX__  -1)
using namespace std;
using ll = long long;

int L, C;
vector<char> sel, v;    //v는 입력 값들, sel은 암호로 선택된 값들

//sel의 k번째 자리에 v[value]를 넣을지 결정하는 함수
void func(int k, int value) {
    //암호가 완성되었다면
    if (k == L) {
        int moeum = 0, jaeum = 0;    //각각 모음 개수, 자음 개수
        int i;

        //모음과 자음 개수를 센다.
        for (i = 0; i < L; i++) {
            if (sel[i] == 'a' || sel[i] == 'e' || sel[i] == 'i' || sel[i] == 'o' || sel[i] == 'u')
                moeum++;
            else
                jaeum++;
        }

        //유효한 암호라면 출력해준다.
        if (1 <= moeum && 2 <= jaeum) {
            for (i = 0; i < L; i++)
                cout << sel[i];
            cout << '\n';
        }

        return;
    }

    int i;

    for (i = value; i < C; i++) {
        //v[i]를 암호로 k번째 암호로 선택할 경우
        sel.push_back(v[i]);
        func(k + 1, i + 1);

        //v[i]를 암호로 선택하지 않을 경우
        sel.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;
    char ch;

    for (int i = 0; i < C; i++) {
        cin >> ch;
        v.push_back(ch);
    }

    //v를 정렬 후 탐색을 시작한다.
    sort(v.begin(), v.end());

    func(0, 0);

    return 0;
}