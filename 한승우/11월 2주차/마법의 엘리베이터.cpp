#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
1 ~ 10^8

1의 자리 수부터 검사하며 5보다 큰지 작은지?
5보다 크면 10에서 뺴고, 5보다 작으면 그대로 

자리 올림? 

5일 때 올릴지 말지를 검사해봐야 함.
5일 떄 다음 숫자가 5보다 같거나 크다면 올리는게 맞고, 아니라면 내리는게 맞음

54 -> 9 or 4 + 5 + 1 = 10, 
64 -> 4 + 6 = 10, 4 + 4 + 1 = 9

555 -> 15 or 5 + 4 + 4 + 1 = 14

15 -> 6 or 7
16 -> 7 or 4 + 2 = 6

55 -> 5 + 4, 10

505 -> 10 
*/

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0){
        int n = storey % 10;
        storey /= 10;
        
        if(n < 5) answer += n;
        else if(n == 5){
            answer += n;
            
            //자리 올림
            if(storey % 10 >= 5) storey++;
        } 
        else{
            answer += 10 - n;
            storey++;
        }
    }
    
    return answer;
}