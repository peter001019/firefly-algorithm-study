#include <bits/stdc++.h>

using namespace std;

// 전체 쭉 내려가는 방법과
// 올라가서 자릿수를 올린 뒤 내려가는 방법이 있다

int solution(int storey) {
    int answer = 0;
    
    while(storey != 0){
        int temp = storey % 10;
        
        if(temp > 5) {
            answer += 10 - temp;
            storey = storey / 10 + 1;
        } else if (temp < 5) {
            answer += temp;
            storey = storey / 10;
        } else {
            // temp가 5인 경우에는 하나 위의 자리수까지 마저 탐색해야 함
            if((storey / 10) % 10 >= 5) {
                answer += 10 - temp;
                storey = storey / 10 + 1;
            } else {
                answer += temp;
                storey = storey / 10;
            }
        }
    }
    
    return answer;
}
