#include <bits/stdc++.h>

using namespace std;

// 하루에 한 개씩 구매 가능 
// want 원하는 제품
// Number 원하는 제품의 수량
// discount 할인하는 제품 배열
// 10일 연속으로 정확히 일치하는 회원 등록 날짜 총 일수
// 없으면 0
// 열흘 단위로 벡터를 끊어서 temp 에 넣고 원소의 개수를 세면서 비교하기??
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    int dayIndex = 0;
    while(dayIndex <= discount.size() + 9){
        vector<string> wantCopy = want;
        vector<int> numberCopy = number;
        bool trigger = true;
        for(int i = dayIndex; i < dayIndex + 10; i++){
            auto it = find(wantCopy.begin(), wantCopy.end(), discount[i]);
            if(it == wantCopy.end()){
                trigger = false;
                break;
            } else {
                int index = distance(wantCopy.begin(), it);
                if(numberCopy[index] == 0) {
                    trigger = false;
                    break;
                } else {
                    numberCopy[index]--;
                }
            }
        }
        if(trigger){
            answer ++;
        }
        dayIndex++;
    }
    return answer;
}
