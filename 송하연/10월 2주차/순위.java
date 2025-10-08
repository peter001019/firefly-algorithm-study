import java.util.*;

class Solution {
    int answer = 0;
    
    public int solution(int n, int[][] results) {

        List<List<Integer>> winGraph = new ArrayList<>();
        List<List<Integer>> loseGraph = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            winGraph.add(new ArrayList<>());
            loseGraph.add(new ArrayList<>());
        }
        
        for(int[] group:results){
            int win = group[0];
            int lose = group[1];
            winGraph.get(win-1).add(lose-1);
            loseGraph.get(lose-1).add(win-1);
        }
        
        //이긴 사람+진 사람 수 = n-1
        for(int i=0; i<n; i++){
            boolean[] visited = new boolean[n];
            visited[i] = true;
            int winCnt = dfs(winGraph,i,visited);
            
            Arrays.fill(visited,false);
            visited[i] = true;
            int loseCnt = dfs(loseGraph,i,visited);
            
            if(winCnt+loseCnt==n-1){
                answer++;
            }
        }
        
        return answer;
    }
    
    int dfs(List<List<Integer>> graph, int node, boolean[] visited){
        int cnt=0;
        for(int next:graph.get(node)){
            if(!visited[next]){
                visited[next] = true;
                cnt+= 1+dfs(graph,next,visited);
            }
        }
        return cnt;
    }
}
