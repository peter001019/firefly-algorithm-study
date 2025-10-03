#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> tiling(n+1);
    tiling[1] = 1;
    tiling[2] = 2;
    tiling[3] = 3;
    
    for(int i = 4; i <= n; i ++) {
        tiling[i] = (tiling[i-1] + tiling[i-2]) % 1000000007;
    }
    answer = tiling[n];
    return answer;
}
