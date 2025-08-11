#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N;

vector<int> graph[501];
int indegree[501];
int cost[501];
int dp[501];

void topological_sort(){
    queue<int> q;

    for(int i = 1; i <= N; i++)
        if(indegree[i] == 0) {
            dp[i] = cost[i];
            q.push(i);
        }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int n: graph[v]){
            indegree[n]--;
            dp[n] = max(dp[n], dp[v] + cost[n]);

            if(indegree[n] == 0) q.push(n);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> cost[i];

        while(true){
            int num; cin >> num;
            if(num == -1) break;

            graph[num].push_back(i);
            indegree[i]++;
        }
    }

    topological_sort();

    for(int i = 1; i <= N; i++) cout << dp[i] << "\n";

    return 0;
}