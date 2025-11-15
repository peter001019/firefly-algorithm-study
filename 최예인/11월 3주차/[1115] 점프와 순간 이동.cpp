#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n>0){
        if(n%2==0){
            n = n/2;
        }else{
            n = n-1;
            ans++;
        }
    }
    
// 초기 접근 : dp => N이 10억까지 될 수 있어서 효율성 테스트에서 시간초과 발생
//     int dp[1000000];
    
//     dp[0] = 0;
//     dp[1] = 1;
//     dp[2] = 1;
//     dp[3] = 2;
    
//     for(int i=4;i<=n;i++){
//         if(i%2==0){
//             dp[i] = dp[i/2];
//         }
//         else{
//             dp[i] = dp[i-1] +1;
//         }
//     }
//     ans = dp[n];

    return ans;
}