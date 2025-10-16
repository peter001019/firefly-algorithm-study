import java.util.*;

class Solution {
    

    
    public int[] solution(int rows, int columns, int[][] queries) {
        
        int[] answer = new int[queries.length];       
        int[][] matrix = new int[rows][columns];
        
        //행렬 값 채우기
        int cnt=1;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                matrix[i][j]=cnt;
                cnt++;
            }
        }
        
        //로테이션->배치->최솟값 구하기
        for(int j=0; j<queries.length; j++) {
            int[] query = queries[j];
            List<Integer> list = rotate(query[0],query[1],query[2],query[3],matrix);              
            int[][] rotatedMatrix = place(query[0],query[1],query[2],query[3],matrix,list);  
            answer[j] = Collections.min(list);
        }
        
 
        return answer;
    }
    
    List<Integer> rotate(int x1, int y1, int x2, int y2, int[][] matrix){
        List<Integer> list = new ArrayList<>();

        for (int i=y1; i<y2; i++) list.add(matrix[x1-1][i-1]);    
        for (int i=x1; i<x2; i++) list.add(matrix[i-1][y2-1]);    
        for (int i=y2; i>y1; i--) list.add(matrix[x2-1][i-1]);     
        for (int i=x2; i>x1; i--) list.add(matrix[i-1][y1-1]);  
        
        int lastNum = list.remove(list.size()-1);
        list.add(0, lastNum); 
        
        return list;     
    }
    
    int[][] place(int x1, int y1, int x2, int y2, int[][] matrix, List<Integer> list){
        int idx =0;   
        
        for (int i=y1; i<y2; i++) matrix[x1-1][i-1] = list.get(idx++);
        for (int i=x1; i<x2; i++) matrix[i-1][y2-1] = list.get(idx++);
        for (int i=y2; i>y1; i--) matrix[x2-1][i-1] = list.get(idx++);
        for (int i=x2; i>x1; i--) matrix[i-1][y1-1] = list.get(idx++);
        
        return matrix;
    }  
   
}
