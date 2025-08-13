#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[1001];
int visited[1001];

void bfs(int start){
    queue<int> q;

    visited[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int n: graph[v]){
            if(!visited[n]){
                visited[n] = true;
                q.push(n);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){ 
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);        
    }

    int cnt = 0;

    for(int i = 1; i <= N; i++){
        if(!visited[i]) {
            bfs(i);
            cnt++;
        }
    }    

    cout << cnt;

    return 0;
}