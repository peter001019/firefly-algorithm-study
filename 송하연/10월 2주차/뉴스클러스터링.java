import java.util.*;

class Solution {
    static int MULTI_VALUE=65536;
    public int solution(String str1, String str2) {
        int answer = 0;
        
        Map<String,Integer> map1 = new HashMap<>();
        Map<String,Integer> map2 = new HashMap<>();

        
        for(int i=0; i<str1.length()-1; i++){
            if(!Character.isLetter(str1.charAt(i))||!Character.isLetter(str1.charAt(i+1))) continue;
    
            String parts1=str1.substring(i,i+2).toLowerCase();
            map1.put(parts1,map1.getOrDefault(parts1,0)+1);
        }
        
         for(int i=0; i<str2.length()-1; i++){
            if(!Character.isLetter(str2.charAt(i))||!Character.isLetter(str2.charAt(i+1))) continue;
    
            String parts2=str2.substring(i,i+2).toLowerCase();
            map2.put(parts2,map2.getOrDefault(parts2,0)+1);
         }
                    
        if(map1.isEmpty()&&map2.isEmpty()) {
            return MULTI_VALUE;
        }
        
        int plus=0;
        int multi=0;
        
        for(String key1:map1.keySet()){
            //겹치지 X 
            if(!map2.containsKey(key1)){
                plus+= map1.get(key1);
            }
            //겹치는 경우
            else{
                plus+= Math.max(map1.get(key1),map2.get(key1));
                multi+= Math.min(map1.get(key1),map2.get(key1));
            } 
        }
        
        for(String key2:map2.keySet()){
            //겹치지 X
            if(!map1.containsKey(key2)){
                plus+= map2.get(key2);
            }
        }
        
        double result = (double)multi/(double)plus*MULTI_VALUE;
        
        return answer=(int)result;
    }
}ㄴ
