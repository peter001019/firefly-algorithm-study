import java.util.*;


class Solution {
    public int solution(int[][] land) {
        int answer = 0;
        int m = land.length;
        int n = land[0].length;
        
        boolean[][] visited = new boolean[m][n];
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        int[] arr = new int[n]; 
 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j]==1 && !visited[i][j]){
                    Set<Integer> set = new HashSet<>(); //열 저장
                    int size = dfs(i,j, land, visited, m, n, dx, dy, set);
                    
                    for(int y: set){
                        arr[y] += size;
                    }
   
                }
            }
        }
        Arrays.sort(arr);
        return answer = arr[n-1];
    }
    
    
    int dfs(int x, int y, int[][] land, boolean[][] visited, int m, int n, int[] dx, int[] dy, Set<Integer> set){
        int size =1;
        visited[x][y]=true;
        set.add(y);
        
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && land[nx][ny]==1){
                visited[nx][ny]=true;
                size+=dfs(nx, ny, land, visited, m, n, dx, dy, set);
            }
        }
        return size;
    }
    
}
