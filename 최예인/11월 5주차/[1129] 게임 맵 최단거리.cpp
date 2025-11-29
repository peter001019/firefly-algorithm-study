#include<vector>
#include<queue>

#define X first
#define Y second

using namespace std;

int vis[102][102];
int dist[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i=0;i<n;i++){
        fill(vis[i], vis[i]+m, -1);
        fill(dist[i], dist[i]+m, 0);
    }
    
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    
    while(!Q.empty()){
        pair<int, int> cursor = Q.front();
        Q.pop();
        
        for(int dir = 0;dir<4;dir++){
            int nx = cursor.X + dx[dir];
            int ny = cursor.Y + dy[dir];
            
            if(nx<0||nx>=n||ny<0||ny>=m){
                continue;
            }
            if(vis[nx][ny]==1 || maps[nx][ny]==0){
                continue;
            }
            
            Q.push({nx, ny});
            vis[nx][ny] = 1;
            dist[nx][ny] = dist[cursor.X][cursor.Y] + 1;
        }
    }
    if(dist[n-1][m-1]==0){
        return -1;
    }
    answer = dist[n-1][m-1]+1;
    
    
    return answer;
}