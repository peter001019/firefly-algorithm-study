#include <bits/stdc++.h>

using namespace std;

// x1, y1, x2, y2
// (2, 2), (2, 4), (5, 2), (5, 4) 이렇게가 꼭짓점 -> (x1, y1), (x1, y2), (x2, y1), (x2, y2)
// 시계방향 회전
// 꼭짓점 기준으로 이동 계산

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int> > map(rows, vector<int>(columns, 0));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            map[i][j] = (i * columns + j + 1);
        }
    }
        
    int index = 0;
    
    while(index < queries.size()){
        int x1 = queries[index][0];
        int y1 = queries[index][1];
        int x2 = queries[index][2];
        int y2 = queries[index][3];
                
        int minValue = rows * columns;
        
        vector<vector<int> > mapCopy = map;
        
        x1 -= 1;
        y1 -= 1;
        x2 -= 1;
        y2 -= 1;
        
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <= y2; j++){
                // (x1, y1) 기준
                // x를 한 칸 위로 이동 
                if(i != x2 && j == y1) {
                    mapCopy[i][j] = map[i + 1][j];
                    minValue = min(minValue, mapCopy[i][j]);
                    continue;
                }
                // (x1, y2) 기준
                // y를 한 칸 오른쪽으로 이동 
                if(i == x1 && j != y1) {
                    mapCopy[i][j] = map[i][j - 1];
                    minValue = min(minValue, map[i][j - 1]);
                    continue;
                }
                // (x2, y1) 기준
                // y를 한 칸 왼쪽으로 이동 
                if(i == x2 && j != y2) {
                    mapCopy[i][j] = map[i][j + 1];
                    minValue = min(minValue, map[i][j + 1]);
                    continue;
                }
                // (x2, y2) 기준
                // x를 한 칸 아래쪽으로 이동 
                if(i != x1 && j == y2) {
                    mapCopy[i][j] = map[i - 1][j];
                    minValue = min(minValue, map[i - 1][j]);
                    continue;
                }
                
            }
        }
        map = mapCopy;
        answer.push_back(minValue);
        index++;
    }

    return answer;
}
