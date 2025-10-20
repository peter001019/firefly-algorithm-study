#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;

/*
칫솔은 개당 100원

parent 배열이 있어야 겠다.
sell 배열

dp로 아래 원소부터 amount를 이용해 차례로 부모의 노드를 업데이트 해나감 -> 재귀 함수
*/

unordered_map<string, string> parent;
unordered_map<string, int> dp;

void cal(string name, int money){
    if(money == 0) return;
    if(name == "-") return;

    int commission = money / 10;
        
    dp[name] += money - commission;
    return cal(parent[name], commission);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0; i < enroll.size(); i++)
        parent[enroll[i]] = referral[i];
    for(int i = 0; i < seller.size(); i++)
        cal(seller[i], amount[i] * 100);
    
    for(string& s: enroll){
        answer.push_back(dp[s]);
    }
    
    return answer;
}