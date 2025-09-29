import java.util.*;

class Solution {
    public String[] solution(String[] files) {
        String[] answer = {};
             
        Arrays.sort(files,(a,b) -> {
            String[] fileA = parse(a);
            String[] fileB = parse(b);
            
            String headA = fileA[0].toLowerCase();
            String headB = fileB[0].toLowerCase();
            
            if(!headA.equals(headB)){
                return headA.compareTo(headB);
            }
            else {
                int numA = Integer.parseInt(fileA[1]);
                int numB = Integer.parseInt(fileB[1]);
                return Integer.compare(numA, numB);
            } 
        });
        return answer=files;
    }
    
    String[] parse(String file){
        int headIdx =0;
        int tailIdx = file.length();
        for(int j=0; j<file.length(); j++){
            char ch = file.charAt(j);
            if(Character.isDigit(ch) && headIdx==0){ 
                headIdx = j; 
            }
            if(!Character.isDigit(ch) && headIdx!=0 && j>headIdx && tailIdx==file.length()){
                tailIdx = j;
            }
        }
        String head = file.substring(0,headIdx);
        
        //최대 5자 제한 필요
        String num = file.substring(headIdx, Math.min(tailIdx, headIdx+5));
        String tail = file.substring(tailIdx,file.length());
        //System.out.println(head+":"+num+":"+tail);
        
        return new String[]{head,num,tail};
            
    }
}
