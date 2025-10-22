#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    // 1 3 5 7
    // 2 2 6 8
    
    int index = 0;
    for(int i = 0; i < A.size(); i++){
        while(A[i] >= B[index] && index < B.size()) {
            index++;
            continue;
        }
        
        if(A[i] < B[index]){
            answer++;
            index++;
            continue;
        }
     }
    return answer;
}

