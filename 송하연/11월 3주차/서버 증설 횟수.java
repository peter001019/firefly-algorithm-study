import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        
        int answer = 0;
        Map<Integer, Integer> map = new HashMap<>(); //운영 끝 시간, 개수
        int computerCnt = 0;
 
        for(int i=0; i<players.length; i++){
            //운영 종료 처리
            if(map.containsKey(i)) computerCnt-=map.get(i);
            
            int endTime = i+k;
            int needCnt = getComputerCnt(players[i],m);
            int addCnt =0;
            
            while(computerCnt<needCnt){
                computerCnt++;
                addCnt++;
            }
            
            //운영 종료 시간과 개수 저장
            if(addCnt>0) {
                map.put(endTime,addCnt);
                answer+=addCnt;
            }

        }
        return answer;
    }
    
    //총 인원 대비 필요한 컴퓨터 수
    int getComputerCnt(int playerCnt, int m){
        return playerCnt/m;
    }

    
    
}
