import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        long max=0;
        
        for(int time:times){
            max=Math.max(max,time);
        }
        
        long left=1;
        long right = max*n;
        
        while(left<=right){
            long mid = (left+right)/2;
            //System.out.println("mid : "+mid);
            long people=0;
            
            for(int time:times){
                people += mid/time;
            }
            
            if(people>=n){
                right=mid-1;
                answer = mid;   
            }
            if(people<n){
                left=mid+1;
            }
        }

        return answer;
        
    }
}
