import java.util.*;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        
        Arrays.sort(rocks);
        
        //바위 사이 거리의 최솟값을 만드는 최댓값(1~distance)
        //rock : 2 11 14 17 21
        //distance : 13(x)->6(x)->3(o)->4(o)->5(x)
  
        int left=1;
        int right=distance;
        
        while(left<=right){
            //최소 거리 후보
            int mid = (left+right)/2;
            int removeCnt=0;
            int preValue=0;
       
            for(int i=0; i<rocks.length; i++){
                int diff = rocks[i] - preValue;
                //건너뛰기 가능 여부
                if(diff<mid) removeCnt++;
                else preValue=rocks[i];
            }
            //마지막 원소 건너뛰기 가능여부
            if(distance-preValue<mid) removeCnt++;
            
            if(removeCnt>n){
                right=mid-1;
            }
            else {
                answer=mid;
                left=mid+1;
            }
        }
        
        return answer;
    }
}
