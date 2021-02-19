#include <iostream>
#include <algorithm>
#include <vector>

#define INT_MAX   __INT_MAX__
using namespace std;
using ll = long long;

int S[20][20] = {0};
int N;
bool isUsed[20] = {false};
ll gap;
vector<int> T;

//T의 k번째 멤버로 value를 영입할지 결정하는 함수
void func(int k, int value) {
    //팀이 완성되었다면
    if (k == N / 2) {
        vector<int> T2;
        T2.clear();

        int i, j;
        //T2를 구한다.
        for (i = 0; i < N; i++) {
            if (isUsed[i] == false) {
                T2.push_back(i);
            }
        }

        //T와 T2의 각각 S값들의 총합을 구한다.
        ll sumT1 = 0, sumT2 = 0;
        for (i = 0; i < N / 2; i++) {
            for (j = 0; j < N / 2; j++) {
                sumT1 += S[T[i]][T[j]];
                sumT2 += S[T2[i]][T2[j]];
            }
        }

        //gap과 비교
        if (abs(sumT2 - sumT1) < gap)
            gap = abs(sumT2 - sumT1);
        return;
    }

    int i;

    //인원수 맞추기 위해 무조건 영입해야하는 경우
    if (T.size() + N - k == N / 2) {
        T.push_back(value);
        isUsed[value] = true;
        func(k + 1, value + 1);
    }
        //인원수에 여유가 있어 영입할지 선택할 수 있는 경우
    else {
        if (T.size() < N / 2) {
            int i;
            for (i = value; i < N; i++) {
                //아직 팀에 영입되지 않았다면
                if (isUsed[i] == false) {
                    //i를 영입하는 경우
                    T.push_back(i);
                    isUsed[i] = true;
                    func(k + 1, i + 1);

                    //i를 영입하지 않는 경우
                    T.pop_back();
                    isUsed[i] = false;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    cin >> N;
    gap = INT_MAX;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            cin >> S[i][j];

    func(0, 0);
    cout << gap;
}