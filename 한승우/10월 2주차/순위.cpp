#include <string>
#include <vector>
#include <queue>

using namespace std;

//a > b이고 b > c이면 a > c이다.

bool result[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(auto& r: results){
        result[r[0]][r[1]] = true;
    }
    
    for(int k= 1; k <= n; k++){
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                if(result[a][k] && result[k][b]) {
                    result[a][b] = true;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        
        for(int j = 1; j <= n; j++){
            if(result[i][j] || result[j][i]) {
                cnt++;
            }
        }
        
        if(cnt == n - 1) answer++;
    }
    
    return answer;
}