#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define X first
#define Y second

int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in_range(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int solution(vector<string> board) {
    queue<pair<int, int>> q;
    pair<int, int> st, end;
    n = board.size();
    m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, -1));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'R')
                st = {i, j};
            if(board[i][j] == 'G')
                end = {i, j};
        }
    
    visited[st.X][st.Y] = 0;
    q.push(st);
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        
        if(board[x][y] == 'G') break;
        
        for(int i = 0; i < 4; i++){
            int nx = x; 
            int ny = y;
            
            //끝까지 이동
            while(in_range(nx + dx[i], ny + dy[i]) 
                  && board[nx + dx[i]][ny + dy[i]] != 'D'){
                nx += dx[i];
                ny += dy[i];
            }
            
            //이미 방문 했을 경우
            if(visited[nx][ny] >= 0) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return visited[end.X][end.Y];
}