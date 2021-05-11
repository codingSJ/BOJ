// base setting
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

int T;
string p, x;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> p;
        cin >> N;
        cin >> x;
        istringstream ss(x);
        string buffer;
        deque<string> d;
        int flag = 1;   //방향. 1: 정방향, -1: 역방향
        int result = 1; //0이면 error

        while (getline(ss, buffer, ',')) {
            if (buffer.find('[') != string::npos) {
                buffer.erase(buffer.begin());
            }
            if (buffer.find(']') != string::npos) {
                buffer.erase(buffer.begin() + buffer.length() - 1);
            }
            if (buffer.length())
                d.push_back(buffer);
        }


        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                flag *= -1;
            } else if (p[i] == 'D') {
                if (!d.empty()) {
                    if (flag == 1)
                        d.pop_front();
                    else
                        d.pop_back();
                } else {
                    result = 0;
                    break;
                }
            }
        }

        if (result) {
            cout << "[";
            if (flag == 1) {
                while (!d.empty()) {
                    cout << d.front();
                    d.pop_front();
                    if(d.size())
                        cout << ",";
                }
                cout << "]\n";
            } else {
                while (!d.empty()) {
                    cout << d.back();
                    d.pop_back();
                    if (d.size())
                        cout << ",";
                }
                cout << "]\n";
            }
        } else {
            cout << "error\n";
        }
        d.clear();
    }
}