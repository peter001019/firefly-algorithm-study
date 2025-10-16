#include <string>
#include <vector>
#include <queue>
#include <iostream>

typedef long long ll;

/*
작업 = 큐에서 꺼내서 다른 큐에 넣기

큐마다 sum을 둬야 될듯

sum을 같게 만드는 방법은 다양하다. 여러 시도를 해봐야 하네.

1. 완탐을 어떻게 하지?
한쪽이 다른 한쪽으로 넘어가면 끝 -> O(30만)
한쪽이 결과보다 크다 -> 그러면 작게 만들고. 
다른 한 쪽이 결과보다 작다 -> 그러면 키우고. 그런식으로 하면 되겠네.

//완탐이 아니고 시뮬레이션으로 할 수 있네.

- 시뮬레이션 종료 조건? -> 이게 어렵네
//한쪽이 없어지면 = 분배하지 못함 
*/

using namespace std;

int solution(vector<int> v1, vector<int> v2) {
    int answer = 0;
    int n = v1.size();
    
    queue<int> q1; queue<int> q2;
    ll sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < n; i++){
        q1.push(v1[i]); q2.push(v2[i]);
        sum1 += v1[i]; sum2 += v2[i];
    }
    
    while(answer <= 4 * n){ //초기 조건 : sum1 && sum2
        if(sum1 == sum2) break;
        int tmp;
        
        //q1 -> q2로 원소 이동
        if(sum1 > sum2){
            tmp = q1.front();
            q2.push(tmp);
            sum2 += tmp;
            sum1 -= tmp;
            q1.pop();
        } else{ //q2 -> q1
            tmp = q2.front();
            q1.push(tmp);
            sum1 += tmp;
            sum2 -= tmp;
            q2.pop();
        }
        
        //cout << sum1 << " " << sum2 << "\n";
        
        answer++;
    }
    
    if(sum1 != sum2) answer = -1;
    
    return answer;
}