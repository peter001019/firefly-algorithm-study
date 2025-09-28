#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[200];
int visited[200];

void bfs(int start){
    queue<int> q;
    
    visited[start] = 1;
    q.push(start);
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        for(int n: graph[v]){
            if(!visited[n]){
                visited[n] = 1;
                q.push(n);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {    
    int answer = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(computers[i][j]){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bfs(i);
            answer++;
        } 
    }
    
    return answer;
}