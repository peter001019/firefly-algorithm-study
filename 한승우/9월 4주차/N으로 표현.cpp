#include <string>
#include <unordered_set>
#include <iostream>

typedef long long ll;
using namespace std;

unordered_set<ll> dp[9];

int solution(int N, int number) {
    ll nn = N; //NN
    
    dp[1].insert(N);
    
    for(int i = 2; i <= 8; i++){
        //NN 처리
        nn = nn * 10 + N;
        dp[i].insert(nn);
        
        for(int k = 1; k <= i / 2; k++){
            for(ll n1: dp[i - k]){
                for(ll n2: dp[k]){
                    dp[i].insert(n1 + n2);
                    dp[i].insert(n1 - n2); 
                    dp[i].insert(n2 - n1);
                    dp[i].insert(n1 * n2);
                    if(n2 != 0) dp[i].insert(n1 / n2);
                    if(n1 != 0) dp[i].insert(n2 / n1);
                }
            }
        }
    }
    
    for(int i = 1; i <= 8; i++){
        if(dp[i].find(number) != dp[i].end()) return i;
    }
    
    return -1;
}