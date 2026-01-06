#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
각 직원에 칭찬을 누적 -> m(10^5)
트리를 순회하며 점수 내려가기
*/

const int MAX = 100005;

int n, m;
vector<int> graph[MAX];
int visited[MAX];
int score[MAX];

void dfs(int cur){
    visited[cur] = 1;

    for(int n: graph[cur]){
        if(visited[n]) continue;
        score[n] += score[cur];
        dfs(n);
    }
}

void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int parent; cin >> parent;
        
        if(parent == -1) continue;
        graph[parent].push_back(i);
    }

    while(m--){
        int i, w;
        cin >> i >> w;
        score[i] += w;
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
        cout << score[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}