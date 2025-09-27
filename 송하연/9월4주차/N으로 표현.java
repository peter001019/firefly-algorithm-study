import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int answer = 0;
        
        List<Set<Integer>> dp = new ArrayList<>();
        
        for(int i=0; i<=8; i++){
            dp.add(new HashSet<>());
        }
        
       
        for(int i=1; i<=8; i++){
            String repeat = String.valueOf(N).repeat(i);
            int num = Integer.parseInt(repeat);
            dp.get(i).add(num);
            
            for(int j=1; j<i; j++){
              for(int a : dp.get(j)){
                  for(int b : dp.get(i-j)){
                      dp.get(i).add(a+b);
                      dp.get(i).add(a-b);
                      dp.get(i).add(a*b);
                      if(b!=0) dp.get(i).add(a/b);
                  }   
              } 
          }
            
            //System.out.println(dp);
            if(dp.get(i).contains(number)){
                return answer = i;
            }
           
        }
        
        return -1;
    }
}
