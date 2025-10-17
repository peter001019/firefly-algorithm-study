import java.util.*;

class Solution {
    
    int maxSheep=0;
    public int solution(int[] info, int[][] edges) {
        int answer = 0;
        List<List<Integer>> graph = new ArrayList<>();
        
        for(int i=0; i<info.length; i++ ){
            graph.add(new ArrayList<>());
        }
        for(int[] edge: edges){
            int parent = edge[0];
            int child = edge[1];
            graph.get(parent).add(child);   
        }
        
        List<Integer> canMove = new ArrayList<>();
        canMove.add(0);
        
        travel(0,0,info,0,graph,canMove);
        System.out.println(graph) ;
        
        return answer=maxSheep;
    }
    
    // [1,8] -> [8,2,4] -> [2,4,7,9] -> [2,4,9] ->  [2,4,10,11] 
     
    void travel(int sheep, int wolf, int[] info, int node, List<List<Integer>> graph, List<Integer> canMove){
        
        if(info[node]==0) sheep++;
        else wolf++;
        
        if(wolf>=sheep) return;
        
        maxSheep = Math.max(maxSheep,sheep);
        
        List<Integer> next = new ArrayList<>(canMove);
        next.remove(Integer.valueOf(node)); //인덱스말고 값으로 불러오기
        next.addAll(graph.get(node));
        
        for(int nextNode: next){
            travel(sheep, wolf, info, nextNode, graph, next);
        }

    }
}
