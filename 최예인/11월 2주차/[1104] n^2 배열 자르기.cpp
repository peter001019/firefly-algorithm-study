#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    // vector<vector<int>>num(n, vector<int>(n,0));
    
    // int target = n;
    // while(target>0){
    //     for(int i=0;i<target;i++){
    //         for(int j=0;j<target;j++){
    //             num[i][j] = target;
    //         }
    //     }
    //     target--;    
    // }
    
    // for(long long i=0;i<n;i++){
    //     for(long long j=0;j<n;j++){
    //         num[i][j] = max(i, j)+1;
    //     }
    // }
    
    for(long long id = left;id<=right;id++){
        long long row = id/n;
        long long col = id%n;
        answer.push_back(max(row, col)+1);
    }
    
    
    return answer;
    
}
