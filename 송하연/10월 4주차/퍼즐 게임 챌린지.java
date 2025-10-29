import java.util.*;

class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        
        int max = 0;
        for(int diff:diffs){
            max = Math.max(max,diff);
        }
        
        int low=1;
        int high=max;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(solve(mid,diffs,times)<=limit) {
                answer= mid;
                high=mid-1;
            }
            else low=mid+1;
        }
    
        return answer;
    }
    
    long solve(int level, int[] diffs, int[] times){
        long totalTime = 0;
        totalTime+= times[0];
        
        for(int i=1; i<diffs.length; i++){  
            if(diffs[i] <= level) totalTime+= times[i];
            //diff > level : 현재 시간 + 이전 시간 * 실패 횟수(diff-level) + 현재시간
            else{
                totalTime+= (times[i]+times[i-1]) * (diffs[i]-level) + times[i];
            }
        }
        //System.out.println(totalTime);
        return totalTime; 
    }
}
