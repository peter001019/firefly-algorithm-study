#include <bits/stdc++.h>
using namespace std;
#define INF 300001;

int N, M, K, X;
vector<int> graph[300001];
int dist[300001];

void dijkstra(){
    priority_queue<pair<int, int>> pq;

    pq.push({0, X});
    dist[X] = 0;

    while(!pq.empty()){
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for(int n_node: graph[cur_node]){
            int n_dist = cur_dist + 1;

            if(n_dist < dist[n_node]){
                dist[n_node] = n_dist;
                pq.push({-n_dist, n_node});
            }
        }
    }
}  

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K >> X;

    int A, B;
    for(int i = 0; i < M; i++){
        cin >> A >> B;

        graph[A].push_back(B);
    }

    for(int i = 1; i <= N; i++) dist[i] = INF;

    dijkstra();

    bool flag = false;

    for(int i = 1; i <= N; i++){
        if(dist[i] == K){
            cout << i << "\n";
            flag = true;
        }
    }

    if(!flag) cout << -1;

    return 0;
}