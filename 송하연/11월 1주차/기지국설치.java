class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        
        for(int i=0; i<stations.length; i++){
            int start=0;
            int end=0;
            
            int minusRange = stations[i]-w;
            int plusRange = stations[i]+w;
     
            if(i==0){
                if(minusRange>1){
                    answer+=install(minusRange-1,w);
                }
                
            }
            else{
                int emptyRange = (stations[i]-w)-(stations[i-1]+w)-1;
                if(emptyRange>0)  answer+=install(emptyRange,w);         
            }

            if(i==stations.length-1){
                if(plusRange<n){
                    answer+=install(n-plusRange,w); 
                } 
            }
        }

        return answer;
    }
    
    //빈 공간에 몇 개 설치 필요한지
    int install(int emptyRange, int w){
        int cover = 2*w+1;
        //남는 부분이 있으면 하나 추가
        int installCnt = emptyRange%cover==0? emptyRange/cover : emptyRange/cover + 1;
        return installCnt;
    }
}
