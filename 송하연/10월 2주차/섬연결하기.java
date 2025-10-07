import java.util.*;

class Solution {
    public int solution(int n, int[][] costs) {
        int answer = 0;
            
        List<List<int[]>> graph = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            graph.add(new ArrayList<>());
        }
    
        for(int[] cost:costs){
            graph.get(cost[0]).add(new int[]{cost[1],cost[2]});
            graph.get(cost[1]).add(new int[]{cost[0],cost[2]}); 

        }
        
        boolean[] visited = new boolean[n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[1]-b[1]); //비용 오름차순
        
        visited[0] = true;
        //(1,1)(2,2)
        for(int[] arr : graph.get(0)) {
            pq.offer(arr);
        }
        
        //노드에서 연결할 수 있는 최소비용 간선 선택
        //(1,1) -> (2,2)(2,5)(3,1) -> (3,1)(2,2)(2,5)
        while(!pq.isEmpty()) {
            int[] now = pq.poll();
            int nextNode = now[0];
            int cost = now[1];

            if(visited[nextNode]) continue;

            visited[nextNode] = true;
            answer += cost;

            for(int[] arr : graph.get(nextNode)) {
                if(!visited[arr[0]]) {
                    pq.offer(arr);
                }
            }
        }

        return answer;
    }
    
 
   
}
