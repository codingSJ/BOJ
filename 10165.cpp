#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
// using ll = long long;

bool compare(pair<pair<int,int>,int> i, pair<pair<int,int>,int> j) {
    if(i.first.first==j.first.first)
        return i.first.second>j.first.second;
    else
        return i.first.first < j.first.first;
}

bool compare2(pair<pair<int,int>,pair<bool,int>> i, pair<pair<int,int>,pair<bool,int>> j) {
    return i.second.second < j.second.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, a, b; // n: 정류장 개수,   m: 버스 노선 수
    vector<pair<pair<int,int>,int>>v; // <시작, 끝>
    vector<int>ans;
    cin >> n >> m;

    for(i=0;i<m;i++){
        cin>>a>>b;
        if(a<b)
            v.push_back({{a, b},i+1});
        else{
            v.push_back({{a-n, b},i+1});
            v.push_back({{a, b+n},i+1});
        }
    }

    sort(v.begin(), v.end(), compare);
    int start=0;
    ans.push_back(v[0].second);
    for(i=1;i<v.size();i++){
        if(v[start].first.second<v[i].first.second){
            start=i;
            ans.push_back(v[i].second);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

