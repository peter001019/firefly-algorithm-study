#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
2500 * 2 * 100

지게차면 겉이 접근 가능한 곳만
크레인이면 모든 걸 다 

- 지게차 = 4면 중 적어도 1면이 창고 외부와 연결
*/

int n, m; //board 행 열
char board[52][52];
int visited[52][52];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool in_range(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

void truck(char target){
    queue<pair<int, int>> q;
    
    visited[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!in_range(nx, ny) || visited[nx][ny]) continue;
            if(board[nx][ny] != 0 && board[nx][ny] != target) continue;
            
            visited[nx][ny] = 1;
            if(board[nx][ny] == 0) q.push({nx, ny});
            else board[nx][ny] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) fill(visited[i], visited[i] + m, 0);
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    n = storage.size() + 2;
    m = storage[0].size() + 2;
    
    for(int i = 0; i < storage.size(); i++)
        for(int j = 0; j < storage[0].size(); j++)
            board[i + 1][j + 1] = storage[i][j];
    
    for(const auto& r: requests){
        //지게차
        if(r.size() == 1) truck(r[0]);
        //크레인
        else {
            for(int i = 1; i < n - 1; i++)
                for(int j = 1; j < m - 1; j++)
                    if(board[i][j] == r[0]) board[i][j] = 0;
        }
    }
    
    for(int i = 1; i < n - 1; i++)
        for(int j = 1; j < m - 1; j++)
            if(board[i][j] != 0) answer++;
    
    return answer;
}
