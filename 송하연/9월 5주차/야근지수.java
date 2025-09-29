import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int time:works){
            pq.add(time);
        }
        //System.out.println(pq);
        
        for(int i=0; i<n; i++){
            if(pq.isEmpty()) return 0;
            
            int max = pq.poll();
            int minus = max-1;
            if(minus!=0) pq.add(max-1);
        }
        
        long result =0;
        while(!pq.isEmpty()){
           result += Math.pow(pq.poll(),2);
        }

        return answer=result;
    }
}
