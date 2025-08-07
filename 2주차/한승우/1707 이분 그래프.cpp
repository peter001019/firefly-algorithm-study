#include <bits/stdc++.h>
using namespace std;

#define RED 1
#define BLUE 2

int K, V, E;
vector<int> graph[20001];
int visited[20001];

void bfs(int start){
    queue<int> q;
    int color = RED;

    visited[start] = color;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(visited[v] == RED) color = BLUE;
        else color = RED;

        for(int n: graph[v]){
            if(visited[n] == 0){
                visited[n] = color;
                q.push(n);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> K;

    while(K--){
        cin >> V >> E;

        int u, v;
        for(int i = 0; i < E; i++){
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 1; i <= V; i++){
            if(!visited[i]) {
                bfs(i);
            }
        }

        int flag = true;

        for(int i = 1; i <= V; i++){
            for(int n: graph[i]){
                if(visited[i] == visited[n]) flag = false;
            }
        }

        if(flag) cout << "YES" << "\n";
        else cout << "NO" << "\n"; 

        for(int i = 1; i <= V; i++){
            graph[i].clear();
            visited[i] = 0;
        }
    }

    return 0;
}