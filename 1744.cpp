#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//#define div 1000000000
using namespace std;
using ll = long long;

int N, sum;
vector<int> vplus;  //0보다 큰 값만 저장할 벡터
vector<int> vother; //0이하의 값들만 저정할 벡터

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int i, tmp;

    for (i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp > 0)
            vplus.push_back(tmp);
        else
            vother.push_back(tmp);
    }

    sort(vplus.rbegin(), vplus.rend()); //양수는 내림차순으로 정렬
    sort(vother.begin(), vother.end()); //0이하는 오름차순으로 정렬

    sum = 0;

    //양수
    for (i = 0; i < vplus.size(); i++) {
        //벡터 내에 다음 수가 존재한다면 묶어서 더한다.
        if (i < vplus.size() - 1) {
            //i, i+1 항 중 1이 존재한다면 각각 더해주는 게 곱해서 더하는 것보다 크다.
            if (vplus[i] != 1 && vplus[i + 1] != 1) {
                sum += vplus[i] * vplus[i + 1];
                i++;
            }
                //값이 1인 항이 존재한다면 그냥 더한다.
            else
                sum += vplus[i];
        }
            //마지막 항이 남는다면 그냥 더한다.
        else
            sum += vplus[i];
    }

    //음수
    for (i = 0; i < vother.size(); i++) {
        //두 개씩 묶어 더해주는 게 이득이다.
        if (i < vother.size() - 1) {
            sum += vother[i] * vother[i + 1];
            i++;
        }
            //마지막 항은 그냥 더한다.
        else
            sum += vother[i];
    }

    cout << sum;
}