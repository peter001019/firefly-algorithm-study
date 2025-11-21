#include <bits/stdc++.h>

using namespace std;

void move(vector<vector<int>> &answer, int n, int start, int temp, int end){
    if(n == 1) {
        answer.push_back({start, end});
    } else {
        move(answer, n-1, start, end, temp);
        answer.push_back({start, end});
        move(answer, n-1, temp, start, end);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    move(answer, n, 1, 2, 3);
    
    return answer;
}
