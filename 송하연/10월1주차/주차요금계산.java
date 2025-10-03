import java.util.*;

class Solution {
    
    static int OUT_TIME= 23*60+59;
    
    public int[] solution(int[] fees, String[] records) {
       
        Map<String, Integer> inMap = new TreeMap<>();
        Map<String, Integer> diffMap = new TreeMap<>();
        
        for(String record:records){
            String[] parts = record.split(" ");
            int time= convertTime(parts[0]);
            String carNum= parts[1];
            String type = parts[2];
            
            if(type.equals("IN")){
                inMap.put(carNum, time);
            }
            //이용 시간 저장
            else if(type.equals("OUT")){
                int inTime = inMap.get(carNum);
                int outTime= convertTime(parts[0]);
                
                int totalDiff = (outTime-inTime) + diffMap.getOrDefault(carNum,0);
                diffMap.put(carNum,totalDiff);
                inMap.remove(carNum);
            }
        }
        
        //23:59시 출차 처리
        for(String carNum:inMap.keySet()){
            int inTime = inMap.get(carNum);
            int totalDiff = (OUT_TIME-inTime) + diffMap.getOrDefault(carNum,0);
            diffMap.put(carNum,totalDiff);
        }
        
        int[] answer = new int[diffMap.size()];
        int i=0;
        
        //정산 요금 계산
        for(int time: diffMap.values()){
            int price = getPrice(time, fees);
            answer[i++]=price;
        }

        return answer;
    }
    

    //시간분변환
    int convertTime(String time){
        String[] parts = time.split(":");
        int hour = Integer.parseInt(parts[0]);
        int minute = Integer.parseInt(parts[1]);
        return hour*60+minute;
    }
    
    //주차요금 계산
    int getPrice(int time, int[] fees){
        int baseTime = fees[0];
        int basePrice = fees[1];
        int perTime = fees[2];
        int perPrice = fees[3];
        int totalPrice =0;
 
        if(time<=baseTime){
            totalPrice=basePrice;
        }
        else {
            //올림 적용하기
            double num = Math.ceil((double)(time-baseTime)/perTime);
            totalPrice = basePrice + (int)num*perPrice;
        }
        return totalPrice;
    }
}
