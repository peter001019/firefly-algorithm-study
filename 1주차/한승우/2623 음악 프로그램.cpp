#include <bits/stdc++.h>
using namespace std;

int N, M;
set<int> graph[1001];
int indegree[1001];
vector<int> ans;

void topological_sort(){
    queue<int> q;

    for(int i = 1; i <= N; i++)
        if(indegree[i] == 0) q.push(i);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        ans.push_back(v);

        for(int next: graph[v]){
            indegree[next]--;

            if(indegree[next] == 0) q.push(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    int num, a, b;
    for(int i = 0; i < M; i++){
        cin >> num;

        cin >> a;
        for(int j = 0; j < num - 1; j++){
            cin >> b;

            if(graph[a].find(b) == graph[a].end())
                indegree[b]++;
                
            graph[a].insert(b);

            a = b;
        }
    }

    topological_sort();

    if(ans.size() < N){
        cout << 0;
    } else {
        for(int a: ans) cout << a << "\n";
    }

    return 0;
}