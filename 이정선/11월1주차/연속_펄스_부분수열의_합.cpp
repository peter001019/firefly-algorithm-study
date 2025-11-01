#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> sequence) {
    int flag = 1;
    long long a =0;
    long long minN = 0;
    long long maxN = 0;
    for(int i = 0; i < sequence.size(); i++){
        a += flag * sequence[i];
        flag *= -1;
        minN = min(minN, a);
        maxN = max(maxN, a);
    }

    long long answer = maxN - minN;
    
    flag = -1;
    a = 0;
    minN = 0;
    maxN = 0;
    for(int i = 0; i < sequence.size(); i++){
        a += flag * sequence[i];
        flag *= -1;
        minN = min(minN, a);
        maxN = max(maxN, a);
    }

    answer = max(answer, maxN - minN);
    return answer;
}
