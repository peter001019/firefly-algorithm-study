import java.util.*;
class Solution {
    
    public int[] solution(int[][] edges) {
        int[] answer = new int[4];
        
        int max = 0;
        
        //노드 최댓값
        for(int[] connect : edges){
            max = Math.max(max, Math.max(connect[0], connect[1]));
        }
        // System.out.println("max : " + max);
        
        int[] in = new int[max+1];
        int[] out = new int[max+1];
        
        //in, out 구하기
        for(int[] connect : edges){
            out[connect[0]]++;
            in[connect[1]]++; 
            
        }
        
        
        for (int i = 0; i <= max; i++) {
            //정점 
            if(in[i]==0 && out[i]>=2){
                answer[0] = i;
            }
            //막대
            if(in[i]>0 && out[i]==0){
                answer[2]++;
            }
            //8자
            if(in[i]>=2 && out[i]>=2){
                answer[3]++;
            }       
        }
        
        //도넛
        int graphNum = out[answer[0]];
        answer[1] = graphNum - answer[2] - answer[3];   

        return answer;
    }
}
