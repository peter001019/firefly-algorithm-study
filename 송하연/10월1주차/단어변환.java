import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        Queue<String[]> queue = new LinkedList<>();
        queue.offer(new String[]{begin,"0"});
        boolean[] visited = new boolean[words.length];
        
        while(!queue.isEmpty()){
            String[] pair = queue.poll();
            String currentWord = pair[0];
            int step = Integer.parseInt(pair[1]);
            
            if(step!=0&&currentWord.equals(target)){
                return answer = step;
            }
            
           for(int i=0; i<words.length; i++){
               if((visited[i]==false)&&isChange(currentWord,words[i])){
                   queue.offer(new String[]{words[i],String.valueOf(step+1)});
                   visited[i]=true;
               }
           }
        }
      
        return answer;
    }
    
    //변환 가능한 단어인지 체크
    boolean isChange(String a, String b){
        int diff = 0; 
        for(int i=0; i<a.length(); i++){
            if(a.charAt(i)!=b.charAt(i)) diff++;
        }
        return diff==1;
    }
}ㄷ
