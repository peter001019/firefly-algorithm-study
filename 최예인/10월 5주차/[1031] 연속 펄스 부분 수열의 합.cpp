#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<int> first_one;
    vector<int> first_minus;
    int a = sequence.size();
    
    long long dp[a];
    long long dp1[a];
    
    int flag = 0;
    for(auto &it : sequence){
        if(flag==0){
            first_one.push_back(it);
            first_minus.push_back(it*(-1));
            flag = 1;
        }else if(flag == 1){
            first_one.push_back(it*(-1));
            first_minus.push_back(it);
            flag = 0;
        }
    }
    
    dp[0] = first_one[0];
    dp[1] = first_one[0] + first_one[1];
    
    dp1[0] = first_minus[0];
    dp1[1] = first_minus[0] + first_minus[1];
    
    for(int i=2;i<first_one.size();i++){
        long long x= first_one[i]+first_one[i-1];
        long long y = dp[i-1]+first_one[i];
        dp[i] = max(x,y);
        
        long long z = first_minus[i]+first_minus[i-1];
        long long q = dp1[i-1]+first_minus[i];
        dp1[i] = max(z,q);
    }
    long long one_max = *max_element(dp,dp+a);
    long long minus_max = *max_element(dp1,dp1+a);
    
    answer = max(one_max, minus_max);
    
    
    return answer;
}