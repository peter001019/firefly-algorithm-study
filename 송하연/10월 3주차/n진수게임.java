import java.util.*;

class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";

        StringBuilder sb = new StringBuilder();
        
        int idx=0;
        int charCnt=0;
              
        //2/3 1->4->7
        //3/5 2->7->12
            
        int remain = (p-1)%m; 

        while(true){

            String num = Integer.toString(idx,n).toUpperCase();
            
            for(int i=0; i<num.length(); i++){          

                char ch = num.charAt(i);
                
                if((charCnt%m)==remain&&t!=0){
                    sb.append(ch);
                    t--;
                }
                charCnt++;
            }
            
            idx++;
            if(t==0) break;
        }
        
    
        return answer=sb.toString();
    }
}
