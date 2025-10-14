#include <bits/stdc++.h>

using namespace std;
// prices - 초 단위로 기록된 주식 가격이 담긴 배열
// 가격이 떨어지지 않은 기간(초)을 구하라


vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    int currentIndex = 0;
    while(currentIndex < prices.size()){
        if(currentIndex == prices.size() - 1) {
            answer[currentIndex] = 0;
            break;
        }
        for(int i = currentIndex; i < prices.size(); i++){
            if(prices[currentIndex] > prices[i]){
                answer[currentIndex] = i - currentIndex;
                break;
            }
            answer[currentIndex] = i - currentIndex;
        }
        currentIndex++;
    }
    return answer;
}
