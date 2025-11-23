import java.util.*;

// 행이나 열이 0이면 갈 수 있는 경로 1
// 현 위치의 경로 = 위 + 좌측 
// 웅덩이는 제외하기 = 0

class Solution {
    
    static final int MOD = 1000000007;
    
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;

        int[][] dp = new int[n][m];
        boolean[][] isPuddle = new boolean[n][m];
        
        for(int[] puddle:puddles){
            isPuddle[puddle[1]-1][puddle[0]-1]=true;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //시작점
                if(i==0 && j==0) {
                    dp[i][j]=1;
                    continue; 
                }
                
                //웅덩이
                if(isPuddle[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                
                //상단 끝
                if(i==0 && j!=0) {
                    dp[i][j] = dp[i][j-1]%MOD;
                    continue;
                }
                
                //우측 끝
                if(j==0 && i!=0) {
                    dp[i][j] = dp[i-1][j]%MOD;
                    continue;
                }

                // 그 외
                dp[i][j] = dp[i-1][j]%MOD+dp[i][j-1]%MOD;
            }
        }
        
        return answer=dp[n-1][m-1]%MOD;
    }
    
}
