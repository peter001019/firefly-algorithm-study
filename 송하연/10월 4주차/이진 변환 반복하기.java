import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[2];
        
        int deleteCnt =0;
        int cnt=0;
        
        while(true){
            if(s.equals("1")) break;
            int beforeLength = s.length();
            
            s=s.replace("0","");
            deleteCnt += beforeLength- s.length();
            
            s = Integer.toString(s.length(),2);
            cnt++;

        }
     
        answer[0] = cnt;
        answer[1] = deleteCnt;

        return answer;
    }
}
