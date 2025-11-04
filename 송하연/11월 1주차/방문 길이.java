import java.util.*;

class Solution {
    public int solution(String dirs) {
        int answer = 0;
        Set<String> set = new HashSet<>();
        int x=0;
        int y=0;
        
        for(int i=0; i<dirs.length(); i++){
            char cmd = dirs.charAt(i);
            boolean isIncrease = false;
            
            String point1 = x+","+y;
            
            //좌표평면의 경계를 넘어가는 명령어는 무시 
            if(!isValid(x,y,cmd)) continue;
            
            if(cmd=='U') {y++; isIncrease=true;}
            if(cmd=='D') {y--;}
            if(cmd=='R') {x++; isIncrease=true;}
            if(cmd=='L') {x--;}

            String point2 = x+","+y;
            
            //순서 구분 없이 같은 경로로 저장(증가 방향)
            if(isIncrease) set.add(point1 +" -> "+ point2);
            else set.add(point2 +" -> "+ point1);
    
        }

        return answer=set.size();
    }
    
    boolean isValid(int x, int y, char cmd){
        if(x==5&&cmd=='R' || x==-5&&cmd=='L' || y==5&&cmd=='U' || y==-5&&cmd=='D') return false; 
        return true;
    }
}
