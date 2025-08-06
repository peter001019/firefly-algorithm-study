#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[10001];
bool visited[10001];
int hack_cnt[10001];

int bfs(int n){
    queue<int> q;
    int cnt = 0;
    
    visited[n] = true;
    q.push(n);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        cnt++;

        for(int next: graph[v]){
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    hack_cnt[n] = cnt;
    return cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;

        graph[b].push_back(a);
    }

    int max_hack = 0;

    for(int i = 1; i <= N; i++){
        for(int i = 1; i <= N; i++) visited[i] = false;

        max_hack = max(max_hack, bfs(i));
    }

    for(int i = 1; i <= N; i++){
        if(hack_cnt[i] == max_hack){
            cout << i << " ";
        }
    }

    return 0;
}