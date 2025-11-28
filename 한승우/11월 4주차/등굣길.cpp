#include <string>
#include <vector>
using namespace std;

/*
거리 대신에 개수를 센다.
오른쪽, 아래로만 가기 때문에 무조건 최단 거리 보장인듯.
*/

const int DIV = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for(const auto& p: puddles) dp[p[1]][p[0]] = -1;
    
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1) continue;
            
            if(dp[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % DIV;
        }
    }
       
    return dp[n][m];
}