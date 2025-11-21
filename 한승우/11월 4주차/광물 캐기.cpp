#include <string>
#include <vector>

using namespace std;

/*
곡괭이를 내가 선택해야 하네.

1. 완탐
3^15 * 50 -> 10^8

2. 그리디
비싼 돌은 비싼 곡괭이로 파는게 맞음. 

앞에서부터 5개씩 그룹화 -> 광물 가치 순으로 정렬
*/

int answer = 1e9;
int fatigue[3][3] = {
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1}
};

void sol(int idx, int sum, vector<int>& picks, vector<string>& minerals){
    if((!picks[0] && !picks[1] && !picks[2]) || idx == minerals.size()){
        answer = min(answer, sum);
        return;
    }
    
    for(int p = 0; p < 3; p++){
        if(picks[p] == 0) continue;
        int tmp = 0, i = idx;
        
        for(; i < min(idx + 5, (int)minerals.size()); i++){
            if(minerals[i] == "diamond") tmp += fatigue[p][0];
            else if(minerals[i] == "iron") tmp += fatigue[p][1];
            else tmp += fatigue[p][2];
        }
        
        picks[p]--;
        sol(i, sum + tmp, picks, minerals);
        picks[p]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) { 
    sol(0, 0, picks, minerals);
    
    return answer;
}