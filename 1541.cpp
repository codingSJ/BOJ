#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>

#define INT_MIN   (-__INT_MAX__  -1)
using namespace std;

int result, tmp;
string st;
vector<int> num;
vector<char> ops;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin, st);

    int i, j;
    i = 0;
    //st를 parsing한다.
    while (i < st.length()) {
        //숫자를 읽는 경우
        if (st[i] != '+' && st[i] != '-') {
            //i 이후 첫 연산자의 위치(j)를 찾는다.
            for (j = i + 1; j < st.length(); j++) {
                if (st[j] == '+' || st[j] == '-') {
                    ops.push_back(st[j]);
                    break;
                }
            }
            //i~j-1까지의 값은 숫자이므로 이를 stoi를 통해 숫자로 변환 후 num에 추가해준다.
            int v = stoi(st.substr(i, j));
            num.push_back(v);

            //인덱스 재설정. 연산자 이후의 값을 찾도록 한다.
            i = j + 1;
        }

            //연산자를 읽는 경우
        else {
            ops.push_back(st[i]);
            i++;
        }
    }

    result = num[0];

    //숫자+숫자-(숫자+숫자+숫자)-(숫자+숫자)-숫자... 형식이 최소값.
    //즉 -와 그 다음 - 사이의 숫자들은 +연산자로만 구성되어 있으므로 이 숫자들을 괄호로 묶는다.
    //주석 처리된 cout을 해제하면 각 괄호 안에 어떤 값들이 들어가있는지 확인할 수 있다.
    for (i = 0; i < ops.size(); i++) {
        //연산자가 -인 경우
        if (ops[i] == '-') {
            //괄호 시작
            tmp = num[i + 1];
//            cout << "괄호 안에.." << num[i + 1] << " ";

            //다음 -가 나오기 전까지 숫자들은 괄호 안에 넣는다.
            while (i < ops.size() && ops[i + 1] == '+') {
                i++;
                tmp += num[i + 1];
//                cout << num[i + 1] << " ";
            }

            //괄호 완성
            result -= tmp;
//            cout << "괄호 끝\n";
        }
            //연산자가 +인 경우
        else {
            result += num[i + 1];
        }
    }
    cout << result;
}