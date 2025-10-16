import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = -2;
        
        Queue<Long> queueA =  new LinkedList<>();
        Queue<Long> queueB =  new LinkedList<>();
        
        long sumA=0;
        long sumB=0;
        
        for(long num1 : queue1){
            queueA.offer(num1);
            sumA+=num1;
        }
        
        for(long num2 : queue2){
            queueB.offer(num2);
            sumB+=num2;
        }
        
        int limit = (queueA.size() + queueB.size())*10;
        long cnt = 0;
        boolean isFind = false;
        
        for(int i=0; i<limit; i++){
            
            if(sumA>sumB){
                long num = queueA.poll();
                queueB.offer(num);
                
                sumA-=num; sumB+=num;
                
                cnt++;
            }
            else if(sumA<sumB){
                 long num = queueB.poll();
                 queueA.offer(num);
                
                 sumA+=num; sumB-=num;
                 cnt++;
            }
            else {
                isFind=true;
                break;
                
            }
        }
        
        if(!isFind) return answer=-1;
        
        return answer=(int)cnt;
    }
    
    int sum(Queue<Integer> queue){
        int result =0;
        
        while(!queue.isEmpty()){
            result+=queue.poll();
        }
        return result;
    }
}
