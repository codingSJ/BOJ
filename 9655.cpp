#include <iostream>

using namespace std;
using ll = long long;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    //상근이랑 창영이가 1, 3의 조합으로 가져갈 때, 한 턴씩 돌고 나면 짝수개의 돌이 사라져있다.
    //즉 어떻게 하든 창영이는 짝수 번째 공만 가져갈 수 있고, 상근이는 홀수 번째 공만 가져갈 수 있다.
    /**
         증명: 상근이와 창영이가 각각 K번씩 공을 가져갔다고 하자.
         상근이가 1개의 공을 가져간 횟수를 a, 3개의 공을 가져간 횟수를 b
         창영이가 1개의 공을 가져간 횟수를 c, 3개의 공을 가져간 횟수를 d 라 하자.
         그럼 a+b = c+d = K
         현재까지 가져간 돌 = (a+c) + 3(b+d)
         K가 홀수라면, a와 b 중 하나만 홀수. 마찬가지로 c와 d중 하나만 홀수.
         즉 a와 3b 중 하나만 홀수, c와 3d 중 하나만 홀수.
         따라서 (a+c)+3(b+d) = 2개의 홀수+2개의 짝수 = 짝수
         K가 짝수라면, a+c+3b+3d = a+c+b+d+2(b+d) = (a+b)+(c+d)+ 2(b+d) = 짝수

         따라서 어떤 조합으로 돌을 가져가든 상근이는 홀수 번째만, 창영이는 짝수 번쨰만 가져갈 수 있다.
     */
    if (N % 2)
        cout << "SK";
    else
        cout << "CY";
}