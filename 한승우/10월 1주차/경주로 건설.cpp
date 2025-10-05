#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAX = 320000;

int N;

//동서남북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//x, y, dir
int visited[25][25][4];

typedef struct State {
    int x;
    int y;
    int dir; 
};

bool in_range(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 4; k++){
                visited[i][j][k] = MAX;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = MAX;
    queue<State> q;
    N = board.size();
    
    init();
    
    visited[0][0][0] = 0;
    visited[0][0][2] = 0;
    //오른쪽 또는 아래 이동   
    q.push({0, 0, 0}); q.push({0, 0, 2});
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(in_range(nx, ny) && !board[ny][nx]){
                int new_cost;
                
                //이동 비용 계산
                if(i != dir)
                    new_cost = visited[y][x][dir] + 600;
                else 
                    new_cost = visited[y][x][dir] + 100;
                
                if(new_cost <= visited[ny][nx][i]){
                    visited[ny][nx][i] = new_cost;
                    q.push({nx, ny, i});
                }
            }
        }
    }
    
    for(int i = 0; i < 4; i++){
        answer = min(answer, visited[N - 1][N - 1][i]);
    }
    
    return answer;
}