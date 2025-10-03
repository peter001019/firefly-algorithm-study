#include <string>
#include <vector>

using namespace std;

int dp[60001];

int solution(int n) {
    int answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1]+dp[i-2])%1000000007;//메모라이제이션 활용
    }
    answer = dp[n];
    return answer;
}