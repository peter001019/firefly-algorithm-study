#include <bits/stdc++.h>
using namespace std;

const int p_total = 32001;

int N, M;
int indegree[p_total];
vector<int> graph[p_total];

//topological sort
void sol(){
    queue<int> q;

    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        cout << v << " ";

        for(int n: graph[v]){
            indegree[n]--;

            if(indegree[n] == 0) q.push(n);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;

        graph[a].push_back(b);
        indegree[b]++;
    }

    sol();

    return 0;
}