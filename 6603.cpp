#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> sel;

void func(int k, int idx, int cnt){
    if(cnt==6){
        int i;
        for (i = 0; i < 6; i++)
            cout << sel[i] << " ";
        cout << '\n';
    }

    if(idx>=k)
        return;

    int i;
    for(i=idx;i<k;i++){
        sel.push_back(v[i]);
        func(k, i + 1, cnt + 1);
        sel.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;

    while (cin >> k) {
        v.clear();
        int i, tmp;
        for (i = 0; i < k; i++) {
            cin >> tmp;
            v.push_back(tmp);
        }
        func(k, 0, 0);
        cout << '\n';
    }
}