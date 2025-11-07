import java.util.*;


class Solution {
    public int[] solution(int n) {
        int[][] triangle = new int[n][];
        boolean[][] visited = new boolean[n][];
        
        for(int i=0; i<n; i++){
            triangle[i] = new int[i+1];
            visited[i] = new boolean[i+1];
        }

        int blockCnt = (1+n)*n/2;
        
        int[] dx = {1,0,-1};
        int[] dy = {0,1,-1};
        
        int x=0;
        int y=0;
        int dir=0;
        int num=1;
       
        
        for(int i=0; i<blockCnt; i++){
            triangle[x][y] = num++;
            visited[x][y] = true;
            
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            
            
            //이동할 수 없으면 방향 전환
            if(nx<0 || ny<0 || nx>=n || ny>=n || visited[nx][ny]){
                dir=(dir+1)%3;
                nx = x+dx[dir];
                ny = y+dy[dir];

            }      
            x=nx;
            y=ny; 
        }
        
        int[] answer = new int[blockCnt];
        int answerIdx=0;
        
        for(int j=0; j<n; j++){
            for(int k=0; k<triangle[j].length; k++){
                answer[answerIdx++] = triangle[j][k];
            }
        }
        
       
        
        
        return answer;
       
    }
     
    
    
}
