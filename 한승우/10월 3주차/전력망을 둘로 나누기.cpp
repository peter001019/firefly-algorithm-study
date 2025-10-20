#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
전력망을 끊었을 때 송전탑 수를 가장 비슷하게

송전탑 수 100개

완전 탐색 = 100 간선(시행) * BFS(100)
*/

vector<int> tree[101];

void bfs(int start, int s, int e, vector<bool>& visited){
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        for(int n: tree[v]){
            if((v == s && n == e) || (v == e && n == s)) continue;
            if(!visited[n]){
                visited[n] = true;
                q.push(n);
            }
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for(const auto& v: wires){
        tree[v[0]].push_back(v[1]);
        tree[v[1]].push_back(v[0]);
    }
    
    //완전 탐색
    for(const auto& v: wires){
        vector<bool> visited(n + 1, false);
        
        bfs(1, v[0], v[1], visited);
        
        //카운팅
        int cnt = 0;
        
        for(int i = 1; i <= n; i++){
            if(!visited[i]) cnt++;
        }
        
        answer = min(answer, abs(n - 2 * cnt));
    }   
    
    return answer;
}