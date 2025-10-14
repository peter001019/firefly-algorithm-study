import java.util.*;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        Map<String, Integer> map = new HashMap<>();

        //초기값
        for(int k=0; k<10; k++){
            map.put(discount[k], map.getOrDefault(discount[k],0)+1);
        }

        if(isMatch(map,want,number)) answer++;
        
        //하나씩 업데이트
        if(discount.length>10){
            for(int j=10; j<discount.length; j++){
                String remove = discount[j-10];
                map.put(discount[j-10], map.get(discount[j-10])-1);
                map.put(discount[j], map.getOrDefault(discount[j],0)+1);

                if(isMatch(map,want,number)) answer++;
            }
        }    
   
        return answer;
    }
      boolean isMatch(Map<String, Integer> map, String[] want, int[] number){
          boolean result = true;
                  
          for(int i=0; i<want.length; i++){
              String type = want[i];
              int num =number[i];

            if(map.get(want[i])==null) return false;
            else{
                if(map.get(want[i])<num) return false;
            }
              
           
          }
          
          return result;
      } 
}
