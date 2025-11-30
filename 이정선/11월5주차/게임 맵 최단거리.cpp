#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int moveX[4] = {0, 1, 0, -1};
    int moveY[4] = {1, 0, -1, 0};
    
    int sizeX = maps.size();
    int sizeY = maps[0].size();
    
    int answer = 0;
    
    // 현재 cost, (x, y)
    queue<pair<int, pair<int, int> > > mapQ;
    
    vector<vector<bool>> visited(sizeX, vector<bool>(sizeY, false));
    
    mapQ.push({1, {0, 0}});
    
    visited[0][0] = true;
    int currentCost = 0;
    
    while(!mapQ.empty()){
        auto [currentX, currentY] = mapQ.front().second;
        currentCost = mapQ.front().first;
        mapQ.pop();
        
        if (currentX == sizeX - 1 && currentY == sizeY - 1) {
            return currentCost;
        }
        
        for(int i = 0; i < 4; i++){
            int newX = currentX + moveX[i];
            int newY = currentY + moveY[i];
           
            // 외벽에 부딪혔을 때
            if(newX >= sizeX || newY >= sizeY || newY < 0 || newX < 0) {
                continue;
            }
            // 벽일 때
            if(maps[newX][newY] == 0) {
                continue;
            }
            // 이미 방문했다
            if(visited[newX][newY]){
                continue;
            }
            mapQ.push({currentCost + 1, {newX, newY}});
            visited[newX][newY] = true;
        }
    }
    return -1;
}
