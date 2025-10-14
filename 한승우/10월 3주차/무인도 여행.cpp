#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;

int rN, cN;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in_range(int r, int c){
    return 0 <= r && r < rN && 0 <= c && c < cN;
}

bool visited[100][100];

int bfs(int x, int y, vector<string>& maps){
    int sum = 0;
    queue<ii> q;
    
    visited[x][y] = true;
    q.push({x, y});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        sum += maps[r][c] - '0';
        
        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            if(in_range(nr, nc) && maps[nr][nc] != 'X' && !visited[nr][nc]){
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    rN = maps.size();
    cN = maps[0].size();
    
    for(int i = 0; i < rN; i++){
        for(int j = 0; j < cN; j++){
            if(maps[i][j] != 'X' && !visited[i][j]){
                int num = bfs(i, j, maps);
                answer.push_back(num);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}