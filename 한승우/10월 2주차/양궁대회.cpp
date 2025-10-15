#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> result;
int max_diff;
vector<int> tmp(11);

void dfs(int start, int n, const vector<int>& info){
    if(n == 0){
        //점수 차 계산
        int diff = 0;
        
        for(int i = 0; i <= 10; i++){
            if(tmp[i] > info[i]) diff += 10 - i;
            else if(tmp[i] == 0 && info[i] == 0) continue; //둘다 0점이면 점수X
            else diff -= 10 - i;
        }
        
        if(diff == 0) return; //비기는 경우 
        if(max_diff <= diff){
            // //같은 점수라면, 더 작은 점수를 선택하는 것을 고르기
            // if(max_diff == diff){
            //     for(int i = 10; i >= 0; i--){
            //         if(result[i] < tmp[i]) break;
            //         //작은 점수가 더 높으면
            //         if(result[i] > tmp[i]) return;
            //     }
            // }
            
            
            
            max_diff = diff;
            result = tmp;
        }
        
        return;
    }
    
    for(int i = start; i <= 10; i++){
        if(n >= info[i] + 1) tmp[i] = info[i] + 1; 
        else tmp[i] = n; //남은 것 다 때려박는 경우
        
        dfs(i + 1, n - tmp[i], info);
        tmp[i] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    dfs(0, n, info);
    
    if(!result.empty()) answer = result;
    else answer.push_back(-1);
    
    return answer;
}