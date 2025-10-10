import java.util.*;

class Solution {
    public int[] solution(String s) {
        
        Map<Integer, List<Integer>> map = new TreeMap<>();
        
        s=s.substring(2,s.length()-2);
        String[] parts = s.split("\\},\\{");
    
        for(String str:parts){
            String[] numParts = str.split(",");
            List<Integer> list = new ArrayList<>();
            
            for(String num :numParts){
                list.add(Integer.parseInt(num));
            }
            
            map.put(list.size(),list);
        }
        
        int[] answer = new int[map.size()];
        
        for(int key:map.keySet()){ 
            if(key==1){
                answer[0]=map.get(key).get(0);
            }
            else{
                List<Integer> diff = new ArrayList<>(map.get(key));
                diff.removeAll(map.get(key-1));
                answer[key-1]=diff.get(0);
            }
            
        }
        

        return answer;
    }

}
