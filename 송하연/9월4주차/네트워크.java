import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        List<List<Integer>> graph = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        
        for(int i=0; i< n; i++){
            graph.add(new ArrayList<>());
        }
        
        for(int i=0; i< n; i++){
           for(int j=0; j<n; j++){
               if(computers[i][j]==1 && i!=j){
                   int start = i;
                   int end = j;
                   graph.get(i).add(j);
                   
               }
           }
        }
        
        //System.out.println(graph);
    
        boolean[] visited = new boolean[n]; 
        
        for(int i=0; i< n; i++){
            if(!visited[i]){
                int start = stack.push(i);
                visited[start]=true;
                answer++;
            }   
            
            while(!stack.isEmpty()){
                int now = stack.pop();
                for(int node: graph.get(now)){
                     if(!visited[node]){
                        stack.push(node);
                        visited[node]=true;
                    } 
                }
            }                       
        }
        return answer;
    }
}
