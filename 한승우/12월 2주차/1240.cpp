#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
floyd warshall 안됨
bfs -> 1000 * (1000 + 999) 되네
*/

vector<pair<int, int>> tree[1002];

void solve() {
    int n, m, a, b, d;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b >> d;
        tree[a].push_back({b, d});
        tree[b].push_back({a, d});
    }

    while(m--){
        cin >> a >> b;

        queue<pair<int, int>> q;
        vector<bool> visited(n + 1);
        visited[a] = 1;
        q.push({a, 0});

        while(!q.empty()){
            auto [v, d] = q.front(); q.pop();

            if(v == b){
                cout << d << '\n';
                break;
            }

            for(auto [n, nd]: tree[v]){
                if(visited[n]) continue;
                visited[n] = 1;
                q.push({n, d + nd});
            }
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