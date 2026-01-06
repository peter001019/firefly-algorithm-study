#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> graph[502];
int visited[502];

bool is_tree;
void dfs(int v, int parent){
    for(int n: graph[v]){
        if(n == parent) continue;
        if(visited[n]){
            is_tree = 0;
            continue;
        }
        visited[n] = 1;
        dfs(n, v);
    }
}

void solve(){
    int num = 1;

    while(1){
        int n, m;
        cin >> n >> m;

        if(n == 0 && m == 0) break;

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;
            visited[i] = 1;
            is_tree = 1;
            dfs(i, 0);
            cnt += is_tree;
        }

        cout << "Case " << num << ": ";
        if(cnt == 0) cout << "No trees.\n";
        else if(cnt == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << cnt << " trees.\n";

        num++;

        for(int i = 1; i <= n; i++){
            graph[i].clear();
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}