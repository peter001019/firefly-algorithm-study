#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

#define X first
#define Y second

/*
1. 첫 풀이 : 열마다 석유 만날때마다 BFS 시전
(25만(BFS) + 25만(초기화)) * 500열 = 50만 * 500 = 2억 5천만

2. 두번쨰 풀이
BFS 한번에 싹 돌린다. -> 25만 //영역 표시 후, 크기를 따로 저장
열마다 돌면서 해당되는 영역을 뽑고 합산 -> 25만
*/

int n, m;
int visited[500][500];
unordered_map<int, int> land_list;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool in_range(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(pair<int, int> start, int land_num, const vector<vector<int>>& land){
    queue<pair<int, int>> q;
    int cnt = 0;
    
    visited[start.X][start.Y] = land_num;
    q.push(start);
    
    while(!q.empty()){
        int x, y; 
        tie(x, y) = q.front(); q.pop();
        
        cnt++;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!in_range(nx, ny) || visited[nx][ny] || land[nx][ny] == 0) continue;
            visited[nx][ny] = land_num;
            q.push({nx, ny});
        }
    }
    
    land_list[land_num] = cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size(); m = land[0].size();
    int land_num = 1;
    
    //영역 표시
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(land[i][j] == 1 && !visited[i][j]) bfs({i, j}, land_num++, land);       
    
    //열마다 영역 수 세기
    for(int c = 0; c < m; c++){
        set<int> s;
        int sum = 0;
        
        for(int r = 0; r < n; r++)
            if(visited[r][c] != 0) s.insert(visited[r][c]);
        
        for(auto i: s) sum += land_list[i];
        answer = max(answer, sum);
    }
    
    return answer;
}