import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Integer> waitQueue = new LinkedList<>();
        Queue<int[]> bridgeQueue = new LinkedList<>();
        
        int time =0;
        int sum=0;
        
        for(int truck_weight:truck_weights){
            waitQueue.offer(truck_weight);
        }
        
        
        while(!waitQueue.isEmpty() || !bridgeQueue.isEmpty()){
            time+=1; 
            int[] bridge=new int[2];
            int wait=0;
           
            if(!bridgeQueue.isEmpty()){
                bridge = bridgeQueue.peek(); 
                if(bridge[1]==time && time!=1){
                    bridgeQueue.poll();
                    sum-=bridge[0];
                }  
            }
            
            if(!waitQueue.isEmpty()){
                wait = waitQueue.peek();  
                if((sum+wait)<=weight){
                    waitQueue.poll();
                    bridgeQueue.offer(new int[]{wait,time+bridge_length});
                    sum+=wait;
                }  
            }         
        }
   
        return answer=time;
    }
    

}
