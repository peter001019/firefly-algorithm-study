#include <string>
#include <vector>

using namespace std;

/*
1. 완탐
100만 C 50만 * 100만 = 시간 초과

2. DP
홀수인 상태에서 문제네.

선형적으로 메모이제이션할 수 없는 것 같은데?
짝수일 때는 선형적으로 가능
홀수일 때는 불가능

경우를 더 나누면 가능

1. i번째 집을 선택했을 때의 최댓값
2. 첫번째 집을 선택하는 경우 (idx : 1 ~ n - 1)
dp[i] = max(dp[i - 1], dp[i - 2] + house[i]);

마지막 집을 선택하는 경우 (idx : 2 ~ n)

3. 0, 1 : 첫번째 집, 2 : 1과 2중에 큰 집
*/

int solution(vector<int> money) {
    int answer = 0;
    vector<int> dp(money.size(), 0);
    
    //1. 첫번째 집 선택
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    for(int i = 2; i < dp.size() - 1; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }
    
    answer = max(answer, dp[money.size() - 2]);
    
    //2. 마지막 집 선택
    dp[1] = money[1];
    dp[2] = max(money[1], money[2]);
    for(int i = 3; i < dp.size(); i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }
    
    answer = max(answer, dp[money.size() - 1]);
    
    return answer;
}