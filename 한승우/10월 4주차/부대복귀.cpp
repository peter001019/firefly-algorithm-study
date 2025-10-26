#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100002];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for(const auto& r: roads){
        graph[r[0]].push_back(r[1]);
        graph[r[1]].push_back(r[0]);
    }
    
    for(int s: sources){
        queue<int> q;
        vector<int> visited(n + 2, -1);
        
        visited[s] = 0;
        q.push(s);
        
        while(!q.empty()){
            int v = q.front(); q.pop();
            
            for(int n: graph[v]){
                if(visited[n] >= 0) continue;
                visited[n] = visited[v] + 1;
                q.push(n);
            }
        }
        
        answer.push_back(visited[destination]);
    }
    
    return answer;
}