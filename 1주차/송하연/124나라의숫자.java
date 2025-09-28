import java.util.*;

class Solution {
    public String solution(int n) {
        String answer = "";
        
        StringBuilder sb = new StringBuilder();
        
        while(n>0){
            int q = n/3; 
            int m = n%3; 
        
            if(m==0) {
                m=4;
                n = q - 1;
            }
            else{
                n = q; 
            }
            sb.insert(0,m);
        }
            
        answer = sb.toString();
        
        return answer;
    }

        
}

