#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int> > map(m, vector<int>(n, 0));
    
    for(const auto &p: puddles){
        map[p[0] - 1][p[1] - 1] = -1;
    }
    
    map[0][0] = 1;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // 물웅덩이 제외
            if(map[i][j] == -1) continue;
            
            // 0, 0 제외
            if(i == 0 && j == 0) continue;
            
            if(i == 0) {
                map[i][j] += map[i][j - 1];
            }
            else if(j == 0) {
                map[i][j] += map[i - 1][j];
            } else {
                if(map[i - 1][j] != -1){
                    map[i][j] += map[i - 1][j];
                }
                if(map[i][j - 1] != -1){
                    map[i][j] += map[i][j - 1];
                }
            }
            map[i][j] = map[i][j] % 1000000007;
        }
    }
    
    answer = map[m - 1][n - 1];
    
    return answer;
}
