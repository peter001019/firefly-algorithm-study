class Solution {
    int answer = 0;
    int[] cols;
    
    public int solution(int n) {
        cols = new int[n];
        dfs(0, n);
        
        return answer;
    }
    
    void dfs(int row, int n){
        if(row==n){
            answer++;
            return;
        }
        
        for(int col=0; col<n; col++){
            cols[row] =col;
            if(isSafe(row)){
                dfs(row+1, n);
            }  
        }
    }
    
    boolean isSafe(int row){
        for(int i=0; i<row; i++){
            if(cols[i]==cols[row]) return false;
            //같은 대각선 : 열 차이 = 행 차이
            if (Math.abs(cols[row]-cols[i]) == Math.abs(row-i)) return false;
        }
        return true;
    }
}
