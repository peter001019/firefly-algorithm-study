import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        
        int len=name.length();
        
        for(int i=0; i<len; i++){
            char ch = name.charAt(i);
            int diff = Math.min(ch-'A','A'+26-ch);
            answer+=diff;
        }
        
        int shift=len-1; //직진
        for(int i=0; i<len; i++){
            char ch = name.charAt(i);
            int next = i+1;
            
            while(next<len&& name.charAt(next) == 'A'){
                next++; //A 건너뛰기
            }
            
            shift = Math.min(shift,i+len-next+Math.min(i,len-next));
   
        }
        return answer+shift;
    }
}
