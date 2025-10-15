#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int sum = 0;
    queue<int> truckQ;
    
    int index = 0; // truck_weights의 index
    int time = 0;
    do{
        
        if(index < truck_weights.size()){
            if(truckQ.size() == bridge_length){
                int tWeight = truckQ.front();
                sum -= tWeight;
                truckQ.pop();
            }
            
            int currentTruck = truck_weights[index];
            
            // 트럭이 들어갈 수 있는지 판단하기(무게)
            if(sum + currentTruck <= weight){
                sum += currentTruck;
                truckQ.push(currentTruck);
                index++;
            } else {
                // 들어갈 수 없다면, 0으로 자리 차지
                truckQ.push(0);
            }
        } else {
            // index가 범위를 넘어섰다면, bridge_length를 더해주고 시간 한번에 경과시키기
            time += bridge_length;
            break;
        }
        // 시간 경과
        time++;
        
    }while(!truckQ.empty());
    
    answer = time;
    return answer;
}
