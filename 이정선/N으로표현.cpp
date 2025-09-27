#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    
    vector<vector<int>> dp(9);
    
    for(int i = 1; i <= 8; i++) {
        string s;
        for (int j = 0; j < i; ++j) {
            s += to_string(N);
        }
        dp[i].push_back(stoi(s));
    }
    
    if (N == number) return 1;
    
    for(int i = 2; i <= 8; i++) {
        for(int j = 1; j < i; j ++) {
            for(auto &x : dp[j]){
                for(auto &y : dp[i - j]) {
                    dp[i].push_back(x + y); 

                    if(x > y) {
                        dp[i].push_back(x - y);
                    } else {
                        dp[i].push_back(y - x);
                    }
                    
                    dp[i].push_back(x * y);
                    
                    if(y != 0) {
                        dp[i].push_back(x / y);
                    }
                    
                    if(x != 0) {
                        dp[i].push_back(y / x);
                    }
                    
                }
            }
            sort(dp[i].begin(), dp[i].end());
            dp[i].erase(unique(dp[i].begin(), dp[i].end()), dp[i].end());

        }

        if(find(dp[i].begin(), dp[i].end(), number) != dp[i].end()) {
            answer = i;
            break;
        }
    }

    return answer;
}
