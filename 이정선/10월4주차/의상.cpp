#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    // 각 카테고리의 옷이 몇벌씩 있는지 
    unordered_map<string, int> categoryCountMap;
    
    // 카테고리 종류
    vector<string> category;
    
    for(int i = 0; i < clothes.size(); i++){
        if(categoryCountMap.find(clothes[i][1]) != categoryCountMap.end()) {
            int count = categoryCountMap[clothes[i][1]];
            categoryCountMap[clothes[i][1]] = count + 1;
            
        } else {
            category.push_back(clothes[i][1]);
            categoryCountMap.insert({clothes[i][1], 1});
        }
    }
    
    int gop = 1;
    
    for(int i = 0; i < category.size(); i++){
        gop *= categoryCountMap[category[i]] + 1;
        // 각 카테고리에 대한 선택의 경우의 수는 하나만 입거나, 안입거나(+1)
    }
    
    answer = gop - 1; // 아무것도 입지 않은 경우는 뺌 
    
    return answer;
}
