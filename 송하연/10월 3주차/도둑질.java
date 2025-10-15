class Solution {
    public int solution(int[] money) {
        int answer = 0;
        
        int n=money.length;
        
        //첫 번째 집 털었을 때 마지막 집 털지 X
        int[] dp1 = new int[n];
        dp1[0] = money[0]; //max(1)
        dp1[1] = Math.max(money[0],money[1]); //max(1,2)
        for(int i=2; i<n-1; i++){
            dp1[i] = Math.max(dp1[i-1], dp1[i-2]+money[i]); //max(2,1+3)
        }
        
        //첫 번째 집 털지 X 마지막 집 털기
        int[] dp2 = new int[n];
        dp2[0] = 0; 
        dp2[1] = money[1];
        for(int j=2; j<n; j++){
            dp2[j] = Math.max(dp2[j-1], dp2[j-2]+money[j]);
        }
        
        return Math.max(dp1[n-2],dp2[n-1]);

    }
}
