import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
                
        int[] answer ={};
        List<Integer> result = new ArrayList<>(); 

        int todayDays = getTotalDays(today);

        //약관 종류
        Map<String, Integer> termsMap = new HashMap<>();
   
        for(String term : terms){ 
            String[] termsPart = term.split(" ");
    
            termsMap.put(termsPart[0], Integer.parseInt(termsPart[1]));
        }

        // 개인정보 수집 일자
        for(int i =0; i< privacies.length; i++){
            
            String[] privaciesPart= privacies[i].split(" ");
            
            String startDate = privaciesPart[0];
            int startDays = getTotalDays(startDate); //일로 환산

            String termType = privaciesPart[1];
            int termLength = termsMap.get(termType);
            
            if(startDays + (termLength*28) <= todayDays){
                result.add(i+1);       
            }
        }

        answer = result.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
    
    //일로 환산 함수
    private int getTotalDays(String date){
        
        String[] datePart = date.split("\\."); //.에 대한 escape 문자 추가
        int year = Integer.parseInt(datePart[0]);
        int month = Integer.parseInt(datePart[1]);
        int day = Integer.parseInt(datePart[2]);
            
        int totalDays = day + (month * 28) + (year * 12 * 28);
            
        return totalDays;
    }
   
}

