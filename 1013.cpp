#include <iostream>
#include <string>

using namespace std;


int main() {
    int T, i;
    bool flag;
    cin >> T;
    cin.ignore();
    while (T > 0) {
        T--;
        string st;
        getline(cin, st);


        i = 0;
        flag = true;
        while (i < st.length() && flag) {
            // ..0 start
            if (st[i] == '0') {
                if (i + 1 == st.length()) {
                    flag = false;
                    break;
                }
                if (st[i + 1] == '0') {
                    flag = false;
                    break;
                }
                i = i + 2;
                // ..01 check done
            }
                // ..1
            else {
                // ..100 start
                if (i + 3 < st.length() && !(st[i + 1] == '0' && st[i + 2] == '0')) {
                    flag = false;
                    break;
                }
                // ..100 check done

                // ..100+1 start
                i = st.find('1', i + 3);
                if (i == -1) {
                    flag = false;
                    break;
                }

                // ..100+1+ start
                while (i < st.length() && st[i] == '1')
                    i++;    // i: first 0 after 1+ or end of string
                // ..100+1+ check done

                // check if string is done correctly
                if (i == st.length()) {
                    flag = true;
                    break;
                } else if (i + 1 == st.length()) {
                    flag = false;
                    break;
                }

                // check either 100+1+01 or 100+1+100+1
                if (st[i + 1] == '0') {
                    // 100+1+ 100
                    if(st[i-2]=='1')
                        i--;
                    else{
                        flag = false;
                        break;
                    }
                } else {
                    // 100+1+01
                }
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}