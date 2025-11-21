#include <string>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
#define pii pair<int, int>

/*
먼저 레버를 찾아간다.
그 다음 출구를 찾아간다.
*/

int n, m;
int dist[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in_range(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int bfs(pii s, pii e, vector<string>& maps){
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pii> q;
    
    dist[s.X][s.Y] = 0;
    q.push({s.X, s.Y});
    
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        
        if(x == e.X && y == e.Y) break;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!in_range(nx, ny) || dist[nx][ny] >= 0 || maps[nx][ny] == 'X') continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    return dist[e.X][e.Y];
}

int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    pii s, e, l;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maps[i][j] == 'S') s = {i, j};
            if(maps[i][j] == 'E') e = {i, j};
            if(maps[i][j] == 'L') l = {i, j};
        }
    }
    
    int stol = bfs(s, l, maps);
    int ltoe = bfs(l, e, maps);
    
    if(stol == -1 || ltoe == -1) answer = -1;
    else answer = stol + ltoe;
    
    return answer;
}