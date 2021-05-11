// base setting
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;


string s1, s2;
deque<char> d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s1;
    cin >> s2;

    for (int i = 0; i < s1.length(); i++) {
        d.push_back(s1[i]);
        if (d[d.size() - 1] == s2[s2.length() - 1] && s2.length() <= d.size()) {
            int j, k;
            int flag = 1;
            for (j = d.size() - s2.length(), k = 0; j < d.size() && k < s2.length(); j++, k++) {
                if (d[j] != s2[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                j = s2.length();
                while (j--) {
                    d.pop_back();
                }
            }
        }
    }

    if (!d.empty()) {
        while (!d.empty()) {
            char ch = d.front();
            cout << ch;
            d.pop_front();
        }
    } else {
        cout << "FRULA";
    }
}