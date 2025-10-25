import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        
        
        Map<String, Integer> map = new HashMap<>();
        
        for(String[] clothe:clothes){
            String type = clothe[1];
            int num = map.getOrDefault(type,0)+1;
            map.put(type, num);
        }
          
        int cnt=1;
        for(String key: map.keySet()){
            cnt*=(map.get(key)+1); //해당 카테고리에서 안 고르는 선택지 +1
        }
              
        return answer=cnt-1; //전체에서 아무것도 안 고른 경우 -1
    }
}
