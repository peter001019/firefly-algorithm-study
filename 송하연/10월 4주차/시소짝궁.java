import java.util.*;

class Solution {
    public long solution(int[] weights) {
        long answer = 0;
        
        //weights에서 비율이 맞는지 탐색(X) -> 먼저 모든 비율에 대한 짝궁 계산 후 weight 저장한 map에 있는지 확인
        double[] num = new double[]{2.0/2.0, 2.0/3.0, 2.0/4.0, 3.0/2.0, 3.0/4.0, 4.0/3.0};
        
        Map<Double, Integer> map = new HashMap<>(); // 짝궁 : 개수
        Arrays.sort(weights); 
        
        for(int weight:weights){
            double doubleWeight = (double)weight;

            // 지금까지 나온 몸무게 중 짝이 맞는 경우만 카운트
            for(double n:num){
                double pair = weight * n;
                if(map.containsKey(pair)){
                    answer += map.get(pair);
                }
            }
            map.put(doubleWeight, map.getOrDefault(doubleWeight, 0) + 1);
            System.out.println(map);
        }

        return answer;
    }
}
