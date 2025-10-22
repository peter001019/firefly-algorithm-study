import java.util.*;

class Solution {
    
    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        
        int idx=0;
        
        for(String[] place:places){
            char[][] map = new char[5][5];
            List<int[]> peopleList = new ArrayList<>(); 
            
            for(int i=0; i<place.length; i++){
                for(int j=0; j<place[i].length();j++){
                    map[i][j] = place[i].charAt(j);
                    if(map[i][j]=='P'){
                        peopleList.add(new int[]{i,j});
                    }
                }
            }
            
            int result = 1;
            
            for (int[] p : peopleList) {
                int x = p[0];
                int y = p[1];
                //System.out.println(x + "," + y);
                //System.out.println(bfs(x,y,dx,dy,map));
                if(!bfs(x,y,dx,dy,map)) {
                    result = 0;
                    break;
                }
            }
            answer[idx] =result;
            idx++;
        }
        
        return answer;
    }
    
    boolean bfs(int x, int y, int[] dx, int[] dy, char[][] map) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x,y,0});
        
        boolean[][] visited = new boolean[5][5];
        visited[x][y] = true; 
        
        while(!queue.isEmpty()){
            int[] current = queue.poll();
            int cx = current[0];
            int cy = current[1];
            int d = current[2];
            
            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                int nd = d+1;
                
                if(nx>=0 && ny>=0 && nx<5 && ny<5 && nd<=2 &&(!visited[nx][ny])){
                    visited[nx][ny] = true;
                    
                    if(map[nx][ny]=='X'){
                        continue;
                    }
                    
                    if(map[nx][ny]=='P'){
                        return false;
                    }
                    
                    if(map[nx][ny]=='O'){
                        queue.offer(new int[]{nx, ny, nd});
                    }
                }
            }  
        }

        return true;
        
    }
}
