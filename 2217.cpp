#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v;
    int N, i, a;
    int result;

    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    //v를 내림차순으로 정렬해준다.
    sort(v.rbegin(), v.rend());

    result = v[0];  //로프를 1개만 쓸 경우 지탱 가능한 최대 무게

    //2개 이상의 로프를 사용할 경우
    for (i = 0; i < v.size(); i++) {
        //사용하는 로프 중 (가장 낮은 지탱무게)*(사용한 개수) = 새 지탱 가능한 최대 무게
        if (v[i] * (i + 1) > result) {
            result = v[i] * (i + 1);
        }
    }
    cout << result;
}