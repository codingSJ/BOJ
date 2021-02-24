#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//#define div 1000000000
using namespace std;
using ll = long long;

string st;
int cnt[26] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin, st);

    int i;
    for (i = 0; i < st.size(); i++) {
        cnt[(int) st[i] - 97]++;
    }

    for (i = 0; i < 26; i++)
        cout << cnt[i] << " ";
    cout << '\n';
}