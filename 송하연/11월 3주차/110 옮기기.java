import java.util.*;

class Solution {
    public String[] solution(String[] s) {
        String[] answer = new String[s.length];
        int idx=0;
        
        for(String str: s){
            StringBuilder sb = new StringBuilder();
            int cnt=0;
            
            for(char ch: str.toCharArray()){
                //System.out.println(ch);
                sb.append(ch);
                
                //110 제거
                if(sb.length()>=3){
                    int n = sb.length()-1;
                    if(sb.charAt(n-2)=='1' && sb.charAt(n-1)=='1' && sb.charAt(n)=='0'){
                        cnt++;
                        sb.delete(n-2, n+1);
                    }
                }
       
                
            }
            //System.out.println("sb : " + sb);
            
            //가장 오른쪽 0 위치에 110삽입
            int inputIdx=-1;
            for(int i=sb.length()-1; i>=0; i--){
                if(sb.charAt(i)=='0'){
                    inputIdx=i;
                    break;
                }
            }
            
            for(int i=0; i<cnt; i++){
                sb.insert(inputIdx+1,"110");
            }
            answer[idx++]=sb.toString();
        }
       
        
        
        return answer;
    }
}
