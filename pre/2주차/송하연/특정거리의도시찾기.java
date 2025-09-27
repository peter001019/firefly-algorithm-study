import java.util.*;

public class Main{

     public static void main(String []args){
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt(); //도시 개수
        int m = scanner.nextInt(); //도로 개수
        int k = scanner.nextInt(); //거리 정보
        int x = scanner.nextInt(); //출발 도시 번호

        List<List<Integer>> graph = new ArrayList<>();
        for(int i=0; i<=n; i++){
            graph.add(new ArrayList<>());
        }

        for(int i=0; i<m; i++){
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            graph.get(start).add(end);
        }

        //System.out.println(graph);

        Queue<Integer> queue = new LinkedList<>();
        boolean[] isVisited = new boolean[n+1];
        int[] distance = new int[n+1];
 
        queue.offer(x);
        isVisited[x] = true;
        distance[x] = 0;
        
        List<Integer> result = new ArrayList<>();

        while(!queue.isEmpty()){
            int current = queue.poll();
            
            for(int next: graph.get(current)){
                if(!isVisited[next]){
                    queue.offer(next);
                    isVisited[next] = true;
                    distance[next] = distance[current]+1;
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            if(distance[i]==k){
                result.add(i);
            }
        }
        
        if(result.size()!=0){
            for(int city : result){
                System.out.println(city); 
            }
        }
        else{
            System.out.println(-1); 
        }
        scanner.close();
     }
     
}
