#include <string>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int vis[102][102];
int countR[102][102];
int countD[102][102];

int solution(vector<string> maps) {
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
   
    queue<pair<int, int>> Q;
    
    for(int i=0;i<n;i++){
        fill(vis[i], vis[i]+m,-1);
        fill(countR[i], countR[i]+m, 0);
        fill(countD[i], countD[i]+m, 0);
    }

    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
            if(maps[i][j] == 'S'){
                Q.push({i, j});
            }
        }
    }
    
    // 스타트에서 레버로 가기 + 갈 수 없다면 -1
    while(!Q.empty()){
        pair<int, int> cursor = Q.front();
        Q.pop();
        for(int dir = 0;dir<4;dir++){
            int nx = cursor.X + dx[dir];
            int ny = cursor.Y + dy[dir];
            
            if(nx<0||nx>=n||ny<0||ny>=m){
                continue;
            }
            if(maps[nx][ny]=='X'||vis[nx][ny]==1){
                continue;
            }
            Q.push({nx, ny});
            vis[nx][ny] = 1;
            countR[nx][ny] = countR[cursor.X][cursor.Y] + 1;
        }
    }
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
            if(maps[i][j] == 'L'){
                if(countR[i][j]==0){
                    return -1;
                }
                answer = countR[i][j];
                Q.push({i, j});
            }
        }
    }
    
    for(int i=0;i<n;i++){
        fill(vis[i], vis[i]+m,-1);
    }
    
    // 레버에서 출구로 가기 + 갈 수 없다면 -1
    while(!Q.empty()){
        pair<int, int> cursor = Q.front();
        Q.pop();
        for(int dir = 0;dir<4;dir++){
            int nx = cursor.X + dx[dir];
            int ny = cursor.Y + dy[dir];
            
            if(nx<0||nx>=n||ny<0||ny>=m){
                continue;
            }
            if(maps[nx][ny]=='X'||vis[nx][ny]==1){
                continue;
            }
            Q.push({nx, ny});
            vis[nx][ny] = 1;
            countD[nx][ny] = countD[cursor.X][cursor.Y] + 1;
        }
    }
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
            if(maps[i][j] == 'E'){
                if(countD[i][j]==0){
                    return -1;
                }
                answer = answer + countD[i][j];
            }
        }
    }
    
  
    
    return answer;
}