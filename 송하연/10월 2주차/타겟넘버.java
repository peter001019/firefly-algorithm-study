import java.util.*;

class Solution {
    
    public static int cnt = 0;
    public int solution(int[] numbers, int target) {
        int answer = 0;

        int sum=0;
        int depth=0;
        int totalDepth = numbers.length-1;
        
        dfs(numbers, sum, target, depth, totalDepth); 

        answer = cnt;
        return answer;
    }

    private void dfs(int[] numbers, int sum, int target, int depth, int totalDepth){
        
        int plusSum = sum + numbers[depth];
        int minusSum = sum - numbers[depth];
        
        if(depth == totalDepth) {
            if(plusSum == target || minusSum == target)
            cnt++;
            return;
        }
        
        dfs(numbers, plusSum, target, depth+1, totalDepth);
        dfs(numbers, minusSum, target, depth+1, totalDepth);
       
    }
   
}

 
    
