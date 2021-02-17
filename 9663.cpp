#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int cnt = 0;
bool b[14][14] = {false};

bool check(int y, int x){
    int i, j;
    //같은 열
    for(j=0;j<x;j++){
        if(b[y][j])
            return false;
    }

    //좌상향
    for(i=y,j=x;i>=0&&j>=0;i--,j--){
        if(b[i][j])
            return false;
    }

    //좌하향
    for(i=y,j=x;i<n&&j>=0;i++,j--){
        if(b[i][j])
            return false;
    }

    return true;
}


void func(int x) {
    if (x == n) {
        cnt++;
        return;
    }

    int y;
    for(y=0;y<n;y++){
        if(b[y][x]== false && check(y,x)==true){
            b[y][x] = true;
            func(x + 1);
            b[y][x] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    func(0);
    cout << cnt;
}