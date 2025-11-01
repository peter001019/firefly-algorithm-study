#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int BFS(int i, int j, int vis[][502], vector<vector<int>>&land, int id){
    queue<pair<int, int>> Q;
    Q.push({i, j});
    vis[i][j] = id;
    int count = 1;
    
    while(!Q.empty()){
        pair<int, int> cursor;
        cursor = Q.front();
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cursor.X + dx[dir];
            int ny = cursor.Y + dy[dir];
            
            if(nx<0||nx>=land.size()||ny<0||ny>=land[0].size()){
                continue;
            }
            if(land[nx][ny]==0||vis[nx][ny]!=-1){
                continue;
            }
            Q.push({nx, ny});
            vis[nx][ny] = id;
            count ++;
        }
        
    }
    return count;
    
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int vis[502][502];
    queue<int> Q;
    vector<pair<int, int>> count;
    map<int, int> oil_size;
    set<int> groups;
    
    for(int i=0;i<502;i++){
        fill(vis[i], vis[i]+502, -1);
    }
    int id = 1;
    
    // 석유 위치 확인
    for(int i=0;i<land.size();i++){
        for(int j=0;j<land[0].size();j++){
            if(land[i][j]==1&&vis[i][j]==-1){
                int amount = BFS(i, j, vis, land, id);  
                oil_size[id] = amount;
                id++;
            }
        }
    }
    
    // 시츄 넣기
    int total = 0;
    int maxs = 0;
    for(int i=0;i<land[0].size();i++){
        total = 0;
        groups.clear();
        for(int j=0;j<land.size();j++){
            if(land[j][i]==1){
                groups.insert(vis[j][i]);
            }
        }
        for(auto &it : groups){
            total = total+oil_size[it];
        }
        maxs = max(maxs, total);
    }
    answer = maxs;
    return answer;
}