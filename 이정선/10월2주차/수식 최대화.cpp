#include <bits/stdc++.h>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    list<string> exp;
    vector<char> sym;
    string temp = "";
    
    for(char c: expression){
        if(c == '+' || c == '-' || c =='*'){
            exp.push_back(temp);
            if(find(sym.begin(), sym.end(), c) == sym.end()){
                sym.push_back(c);
            }
            exp.push_back(string(1, c));
            temp = "";
        } else {
            temp += c;
        }
    }
    exp.push_back(temp);
    
    sort(sym.begin(), sym.end());

    long long maxValue = 0;
    do {
        list<string> expCopy = exp;
        for (char c : sym) {
           string opStr = string(1, c);
            auto it = expCopy.begin();
            while (it != expCopy.end()) {
                
                if (*it == opStr) {
                    auto prevIt = prev(it);
                    auto nextIt = next(it);

                    long long left = stoll(*prevIt);
                    long long right = stoll(*nextIt);
                    long long result = 0;

                    if (c == '+') result = left + right;
                    else if (c == '-') result = left - right;
                    else if (c == '*') result = left * right;

                    // 결과로 prev 업데이트, 나머지 제거
                    *prevIt = to_string(result);
                    it = expCopy.erase(it);     // 현재 연산자 제거
                    it = expCopy.erase(it);     // next 숫자 제거
                } else {
                    ++it;
                }
            }
        }
        
        long long finalResult = abs(stoll(expCopy.front()));
        maxValue = max(maxValue, finalResult);
    } while (next_permutation(sym.begin(), sym.end()));
    
    answer = maxValue;
    return answer;
}
