// base setting
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> v[1001];
bool visited[1001] = {false};
int result = 0;
queue<int> q;

void dfs(int vertex) {
    q.push(vertex);
    visited[vertex] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int k = 0; k < v[u].size(); k++) {
            int adjV = v[u][k];
            if (visited[adjV] == false) {
                visited[adjV] = true;
                q.push(adjV);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }


    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            dfs(i);
            result++;
        }
    }
    cout << result;
}