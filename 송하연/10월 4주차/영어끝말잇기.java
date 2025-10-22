import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[]{0,0};

        List<String> wordList = new ArrayList<>();
        wordList.add(words[0]);
        
        for(int i=1; i<words.length; i++){
            String prior = words[i-1];
            char end = prior.charAt(prior.length()-1);
            
            String word = words[i];
            char start = word.charAt(0);
            
            if(wordList.contains(word) || end!=start){
                answer[0] = i%n+1;
                answer[1] = i/n+1;   
                break;
            }
            
            wordList.add(word);
        }

        return answer;
    }
}
