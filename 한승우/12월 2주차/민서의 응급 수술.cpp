#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ans, n, m;
vector<int> graph[100005];
int visited[100005];

bool is_cycle;
void dfs(int cur, int pre){
    visited[cur] = 1;

    for(int n: graph[cur]){
        if(visited[n]){
            if(n != pre){
                is_cycle = 1;
                //ans++; //cycle을 만드는 간선을 빼준다.
            }
            continue;
        }
        dfs(n, cur);
    }
}

void solve() {
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int group = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        is_cycle = 0;
        dfs(i, -1);
        group++; //연결 요소들을 세준다.
    }

    ans += group - 1; //떨어진 요소들을 연결
    ans += m + group - 1 - (n - 1); //cycle을 형성하는 간선 제거

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}