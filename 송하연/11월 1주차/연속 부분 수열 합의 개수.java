import java.util.*;

class Solution {
    public int solution(int[] elements) {
        int answer = 0;
        
        int n = elements.length;
        Set<Integer> set = new HashSet<>();

        for(int i=1; i<=n; i++){

            int sum=0;
            for(int j=0; j<n; j++){
                //초기 윈도우
                int idx=0;
                if(j==0){
                    while(idx<i) {  
       
                        int order = j+idx;
                        if(order>=n) order = (order)%n;

                        sum+=elements[order];
                        idx++;
                        set.add(sum);

                    }
                }
                else{ 
   
                    int minus = j-1;
                    int plus = (j+i-1)%n;

                    sum-=elements[minus];
                    sum+=elements[plus];
                    set.add(sum);
  
                }

            }
        }

        return answer = set.size();
    }
}
