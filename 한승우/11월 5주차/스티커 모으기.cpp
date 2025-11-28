#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> s)
{
    int answer = 0;
    
    if(s.size() == 1) return s[0];
    vector<int> dp(s.size(), 0);
    
    //1. 1번째 원소 선택
    dp[0] = s[0];
    dp[1] = s[0];
    for(int i = 2; i < s.size() - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + s[i]);
    
    answer = max(answer, dp[s.size() - 2]);
    
    //2. 1번째 원소 선택 X 
    dp[0] = 0;
    dp[1] = s[1];
    for(int i = 2; i < s.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + s[i]);
    
    answer = max(answer, dp[s.size() - 1]);
    
    return answer;
}