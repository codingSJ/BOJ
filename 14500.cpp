// base setting
#include <iostream>

using namespace std;

int N, M, rv;
int map[500][500];
// ----*2, ㅁ*1, ㄴ*8, ㄱㄴ*4, ㅗ*4
int dx[19][4]={
        {0,1,2,3},{0,0,0,0}, // ---- * 2
        {0,1,0,1},           // ㅁ * 1
        {0,0,0,1},{0,1,2,2},{0,0,0,-1},{0,-1,-2,-2},{0,0,0,-1},{0,-1,-2,-2},{0,0,0,1},{0,1,2,2}, // ㄴ*8
        {0,0,1,1},{0,1,1,2},{0,0,-1,-1},{0,-1,-1,-2},    //ㄱㄴ * 4
        {0,1,2,1},{0,0,0,1},{0,-1,-2,-1},{0,0,0,-1}       //ㅗ * 4
};

int dy[19][4]={
        {0,0,0,0},{0,-1,-2,-3},  // ---- * 2
        {0,0,-1,-1},             // ㅁ*1
        {0,-1,-2,-2},{0,0,0,1},{0,1,2,2},{0,0,0,-1},{0,-1,-2,-2},{0,0,0,1},{0,1,2,2},{0,0,0,-1},    //ㄴ*8
        {0,-1,-1,-2},{0,0,1,1},{0,-1,-1,-2},{0,0,1,1},  //ㄱㄴ*4
        {0,0,0,-1},{0,1,2,1},{0,0,0,1},{0,1,2,1}    //ㅗ*4
};

int getValue(int y, int x, int idx){
    int ret = 0;

    for(int k=0;k<4;k++){
        int ny = y + dy[idx][k];
        int nx = x + dx[idx][k];
        if(0<=ny && ny<N&&0<=nx&&nx<M){
            ret += map[ny][nx];
        }
        else{
            ret = -1;
            break;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    rv = 0;
    int y, x;

    for(y=0;y<N;y++){
        for(x=0;x<M;x++){
            for(int i=0;i<19;i++){
                int tmpReturnvalue = getValue(y, x, i);
                if(tmpReturnvalue>rv)
                    rv = tmpReturnvalue;
            }
        }
    }
    cout << rv;
}