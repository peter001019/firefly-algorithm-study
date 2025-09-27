import java.util.*;

public class ConnectedComponent {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        List<List<Integer>> graph = new ArrayList<>();

        for(int i=0; i<=n; i++){
            graph.add(new ArrayList<>());
        }

        for(int i=0; i<m; i++){
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            graph.get(start).add(end);
            graph.get(end).add(start);
        }

        //System.out.println(graph);
        boolean[] visited = new boolean[n+1];
        int cnt =0;

        for(int node =1; node<=n; node++){
            if(!visited[node]){
                dfs(graph,visited,node);
                cnt++;
            }
        }

        System.out.println(cnt);
    }

    private static void dfs(List<List<Integer>> graph, boolean[] visited, int node){
        visited[node] = true;
        for(int next : graph.get(node)){
            if(!visited[next]){
                dfs(graph,visited,next);
            }
        }
    }

}
