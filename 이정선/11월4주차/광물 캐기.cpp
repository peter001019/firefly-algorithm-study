#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.second >= b.second) return true;
    return false;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    vector<pair<int, int> > stoneMax;
    
    int index = 0;
    while(index < minerals.size()){
        int currentMax = 0;
        for(int i = 0; i < 5; i++){
            if(index >= minerals.size()) {

                break;
            }
            if(minerals[index] == "diamond"){
                currentMax += 25;
            } else if (minerals[index] == "iron") {
                currentMax += 5;
            } else {
                currentMax += 1;
            }
            index++;
        }
        stoneMax.push_back({(index - 1) / 5, currentMax});
    }
    
    int allCount = 0;
    for(int i = 0; i < picks.size(); i++) {
        allCount += picks[i];
    }

    sort(stoneMax.begin(), stoneMax.end(), cmp);
    
    for(const auto &s: stoneMax){
        int currentIndex = s.first;
        
        if(currentIndex + 1 > allCount){
            continue;
        }
        
        if(picks[0] != 0) {
            for(int i = 0; i < 5; i++){
                if(currentIndex * 5 + i >= minerals.size()){
                    break;
                }
                answer++;
            }
            picks[0] -= 1;
        } else if (picks[1] != 0){
            for(int i = 0; i < 5; i++){
                if(currentIndex * 5 + i >= minerals.size()){
                    break;
                }
                if(minerals[currentIndex * 5 + i] == "diamond"){
                    answer += 5;
                } else {
                    answer ++;
                }
            }
            picks[1] -= 1;
        } else if (picks[2] != 0) {
            for(int i = 0; i < 5; i++){
                if(currentIndex * 5 + i >= minerals.size()){
                    break;
                }
                if(minerals[currentIndex * 5 + i] == "diamond"){
                    answer += 25;
                } else if(minerals[currentIndex * 5 + i] == "iron"){
                    answer += 5;
                } else {
                    answer ++;
                }
            }
            picks[2] -= 1;
        } else {
            break;
        }
        
    }
    return answer;
}
