#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<char> > versus(n+1, vector<char>(n+1, 'N')); 
    // (n, m) 일 때 n이 m을 이기면 W, 지면 L
    
    for(int i = 0 ; i < results.size(); i ++){
        int winner = results[i][0];
        int loser = results[i][1];
        versus[winner][loser] = 'W';
        versus[loser][winner] = 'L';
    }
    for(int i = 1; i < n+1; i ++) {
        for(int j = 1 ; j < n+1; j++) {
            for(int k = 1; k < n+1; k++){
                if(versus[i][j] == 'W' && versus[j][k] == 'W'){
                    versus[i][k] = 'W';
                    versus[k][i] = 'L';
                }
                if(versus[i][j] == 'L' && versus[j][k] == 'L'){
                    versus[i][k] = 'L';
                    versus[k][i] = 'W';
                }
            }
        }
    }
    
    bool flag = true;
    for(int i = 1 ; i < n+1; i++){
        for(int j = 1 ; j < n+1; j++){
            if(i==j) continue;
            if(versus[i][j] == 'N'){
                flag = false;
            }
        }
        if(flag) answer ++;
        flag = true;
    }

    return answer;
}
