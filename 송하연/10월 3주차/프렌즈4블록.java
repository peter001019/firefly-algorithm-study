import java.util.*;

class Solution {
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        char[][] map = new char[m][n];
        
        for(int i=0; i< m; i++){
            map[i] = board[i].toCharArray();
        }
        
        while(true){
            boolean removed = false;
            Set<String> removeSet= new HashSet<>();
            
            for(int j=0; j< m-1; j++){
                 for(int k=0; k< n-1; k++){
                       char ch = map[j][k];
                       if (ch == '.') continue;
             
                       if(map[j][k+1]==ch && map[j+1][k+1]==ch && map[j+1][k]==ch){
                           removed = true;
                           
                           int kPlus = k+1;
                           int jPlus = j+1;

                           removeSet.add(new String(j+","+k));
                           removeSet.add(new String(j+","+kPlus));
                           removeSet.add(new String(jPlus+","+k));
                           removeSet.add(new String(jPlus+","+kPlus));
                       }
                 }
            }

            if(!removed) break;
            else{
                answer+=removeSet.size();
                move(map, removeSet, m, n);
            }
            
        }

        return answer;
    }
    
    char[][] move(char[][] map, Set<String> removeSet, int m, int n){
        for(String remove : removeSet){
            String[] parts = remove.split(",");
            int x = Integer.parseInt(parts[0]);
            int y = Integer.parseInt(parts[1]);
            map[x][y] = '.';
        }
        
    
        while (true) {
            boolean moved = false;

            for (int i = m - 2; i >= 0; i--) {
                for (int j = 0; j < n; j++) {
                    if (map[i + 1][j] == '.' && map[i][j] != '.') {
                        map[i + 1][j] = map[i][j];
                        map[i][j] = '.';
                        moved = true;
                    }
                }
            }
            if (!moved) break; 
        }
        
        return map;
    }
}
