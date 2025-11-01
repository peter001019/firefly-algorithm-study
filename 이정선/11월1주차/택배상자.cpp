#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    
    int index = 0;
    int orderNum = 1;
    while(order.size() >= orderNum){
       if(order[index] == orderNum) {
           answer++;
           index++;
           orderNum++;
       } else if (!s.empty() && order[index] == s.top()){
           s.pop();
           answer++;
           index++;
       } else {
           s.push(orderNum);
           orderNum++;
       }
        
    }
    
    while(!s.empty()) {
        if(order[index] == s.top()){
            answer++;
            s.pop();
            index++;
        } else break;
    }
    return answer;
}
