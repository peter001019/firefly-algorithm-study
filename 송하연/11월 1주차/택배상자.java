import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;

        Stack<Integer> stack = new Stack<>();
        
        int num=1;
        for(int target : order){
            //System.out.println("target" +target);
            //System.out.println("num" +num);
            
            while(num<=target){
                stack.push(num);
                num+=1;
            }
            
            if(!stack.isEmpty() && stack.peek()==target){
                stack.pop();
                answer++;
            }
            else break;

        }    
    
         return answer;
    }
       
}
