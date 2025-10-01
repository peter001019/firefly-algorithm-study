#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int> > dp(triangle.size());
    dp[0].push_back(triangle[0][0]);
    for(int i = 1; i < triangle.size(); i++) {
        dp[i].push_back(dp[i-1][0] + triangle[i][0]);
        for(int j = 1; j < triangle[i].size() - 1; j++) {
            int temp = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            dp[i].push_back(temp);
        }
        dp[i].push_back(dp[i-1][triangle[i].size() - 2] + triangle[i][triangle[i].size() - 1]);
    }
    int size = triangle.size();
    int max = 0;
    for(int i = 0; i < size; i++ ) {
        if(max < dp[size - 1][i]) {
            max = dp[size - 1][i];
        }
    }
    answer = max;
    return answer;
}
