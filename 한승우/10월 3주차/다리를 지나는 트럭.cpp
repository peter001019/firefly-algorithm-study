#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
1초에 트럭 한대씩 올라가고, 한대씩 빠진다.
트럭이 다리 위에 최대 bridge_length대 올라갈 수 있고, weight까지만 올라갈 수 있다.

1. 트럭이 다리를 지나는 시간을 어떻게 카운팅 할 것인가.
그냥 큐의 길이를 bridge_length로 유지하고, 계속 앞에 pop, 뒤에 push하면 될 것 같은데?
*/

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> q;
    for(int i = 0; i < bridge_length; i++) q.push(0); //초기화
    
    int idx = 0; //트럭 번호
    int sum = 0; //다리 위 트럭들의 무게
    
    //마지막 트럭이 다리에 올라가면 종료
    while(idx < truck_weights.size()){
        sum -= q.front();
        q.pop();
        
        if(sum + truck_weights[idx] <= weight){
            q.push(truck_weights[idx]);
            sum += truck_weights[idx];
            idx++;
        } else {
            q.push(0);
        }
        
        answer++;
    }
    
    answer += bridge_length;
    
    return answer;
}