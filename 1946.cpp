#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <string>
#include <queue>
#include <cmath>
#include <fstream>
#include <string>

#define pii pair<int,int>
#define pipii pair<int, pii>
#define ppiii pair<pii, int>
#define ull unsigned long long
#define pll pair<ull,ull>
#define ull_max (ull)0 - 1
#define BIG_NUM 1000000009
#define MAX_INT 100
#define MAXN 5000
#define MAXF 3000
#define pql priority_queue<pll, vector<pll>, greater<pll>>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n, i;
        int min, cnt;
        cin >> n;
        vector<pair<int, int>> v(n);

        for (i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;

        sort(v.begin(), v.end());
        min = v[0].second;
        cnt = 1;
        
        for(i=1;i<n;i++){
            if(v[i].second<min) {
                min = v[i].second;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}