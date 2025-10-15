#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    vector<int> dp(size);
    
    // dp[i] -> i번째 집까지 탐색했을 때의 최대 money

    dp[0] = money[0];
    dp[1] = max(money[0], money[1]); 
    
    int index = 2; 
    
    // 마지막 집 안터는 경우(size - 2 인덱스까지만 확인)
    while(index < size - 1){
        // max(i - 2번째 집까지의 최댓값 + i번째 집 털기, i - 1번째 집까지의 최댓값)
        // 즉 현재 인덱스의 집을 터냐, 털지 않냐로 나누어서 max값을 취한다
        dp[index] = max(dp[index - 2] + money[index], dp[index - 1]);
        index++;
    }
    
    answer = dp[size - 2]; 
    
    dp.clear();
    
    // 0 인덱스의 집 안터는 경우
    dp[0] = 0;
    dp[1] = money[1];
    
    index = 2;
    
    // 마지막 집까지 확인하기
    while(index < size){
        dp[index] = max(dp[index - 2] + money[index], dp[index - 1]);
        index++;
    }
    
    answer = max(answer, dp[size - 1]);
    return answer;
}
