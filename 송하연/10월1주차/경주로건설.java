import java.util.*;

class Solution {
    public int solution(int[][] board) {
        int answer = Integer.MAX_VALUE; 
        
        int n = board.length;
        int[][][] cost = new int[n][n][4];
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               Arrays.fill(cost[i][j], Integer.MAX_VALUE);
            }
        }
        
        Queue<int[]> queue = new LinkedList<>();

        //시작위치 초기화
        queue.offer(new int[]{0,0,-1,0}); //x,y,방향,비용
        cost[0][0][0] = cost[0][0][1] = cost[0][0][2] = cost[0][0][3] = 0;

        while(!queue.isEmpty()){
            int[] now = queue.poll();
            
            int x = now[0];
            int y = now[1];
            int dir = now[2];
            int price = now[3];

            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    if(board[nx][ny]==0){
                        
                        int newPrice = price;
                        if(dir==-1||dir==i) newPrice+=100;
                        else newPrice+=600;
                        
                        if(newPrice < cost[nx][ny][i]){
                        cost[nx][ny][i] = newPrice;
                        queue.offer(new int[]{nx, ny, i, newPrice});
                    }

                    }
                    
                }
            }
        }
        answer = Math.min(Math.min(cost[n-1][n-1][0], cost[n-1][n-1][1]),
                  Math.min(cost[n-1][n-1][2], cost[n-1][n-1][3]));
        return answer;
    }
}
