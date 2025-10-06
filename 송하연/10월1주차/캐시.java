import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        Queue<String> queue = new LinkedList<>();
        Set<String>set = new HashSet<>();
        
        for(String cityOrigin:cities){
            String city = cityOrigin.toLowerCase();
            if(cacheSize == 0){
                return answer=5*cities.length;
            }
            if(set.contains(city)){
                answer+=1;
                queue.remove(city);
                queue.add(city);
            }
            else{
                if(set.size()<cacheSize){
                    answer+=5;
                    queue.add(city);
                    set.add(city);
                }
                else{
                    answer+=5;
                    String old = queue.poll();
                    set.remove(old);
                    queue.add(city);
                    set.add(city);
                }
            }
        }
        
        return answer;
    }
}
