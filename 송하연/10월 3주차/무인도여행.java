import java.util.*;

class Solution {
    public int[] solution(String[] maps) {
        int[] answer = {};
        
        List<Integer> list = new ArrayList<>();
        
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        
        boolean[][] visited = new boolean[maps.length][maps[0].length()];
 
        for(int i=0; i< maps.length; i++){
            for(int j=0; j<maps[i].length(); j++){
                char ch = maps[i].charAt(j);
                
                if(ch=='X'|| visited[i][j]) continue;
               
                visited[i][j] = true;
        
                int result = dfs(i,j,maps,visited,dx,dy);
                list.add(result);
                Collections.sort(list);
                
                answer = list.stream().mapToInt(Integer::intValue).toArray();

            }
        }
        
        if(list.size()==0){
            return new int[]{-1};
        }

        return answer;
    }
    
    int dfs(int x, int y, String[] maps, boolean[][] visited,int[] dx,int[] dy){
        char num = maps[x].charAt(y);
        int sum = Character.getNumericValue(num);
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && ny>=0 && nx<maps.length && ny<maps[0].length()){
                char next = maps[nx].charAt(ny);
                 if(!visited[nx][ny] && next!='X'){
                     visited[nx][ny] = true;
                     sum += dfs(nx,ny,maps,visited,dx,dy);
                }
            }
        }
        return sum;
    }
}
