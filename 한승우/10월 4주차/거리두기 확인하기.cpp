#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
각 대기실별로 거리두기를 지키고 있는지 확인한다

BFS 사용, 파티션 나오면 종료, 다른 사람에 도달하면 종료
*/

int visited[5][5];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in_range(int x, int y){
    return 0 <= x && x < 5 && 0 <= y && y < 5;
}

bool bfs(int r, int c, const vector<string>& place) {
    queue<pair<int, int>> q;
    
    //초기화
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            visited[i][j] = 0;
    
    visited[r][c] = 1;
    q.push({r, c});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //시작점이 아닌데 사람이라면
        if(visited[x][y] > 1 && place[x][y] == 'P') return false;
        //맨해튼 거리 2까지만 탐색
        if(visited[x][y] == 3) continue;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(in_range(nx, ny) && !visited[nx][ny] && place[nx][ny] != 'X'){
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return true;
}

//한 대기실 탐색
bool room(const vector<string>& place){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(place[i][j] == 'P'){
                if(!bfs(i, j, place)){
                    return false;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int k = 0; k < 5; k++){
        if(room(places[k])){
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }
    
    return answer; 
}