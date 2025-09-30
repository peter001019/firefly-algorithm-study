import java.util.*;

class Solution {
    public int[] solution(int n, int s) {
        List<Integer> result = new ArrayList<>();
        
        int num = s/n;
        int rest = s%n;
        
        if(n>s) {
            return new int[]{-1};
        }
       
        int[] answer = new int[n];
        Arrays.fill(answer,num);

        for(int i=n-1; i>=0; i--){
            if(rest==0) break;
            answer[i]++;
            rest--;
        }

        return answer;
    }
}
