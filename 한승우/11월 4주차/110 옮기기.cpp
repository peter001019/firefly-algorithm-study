#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
110 단위로 옮겨서 이진수를 최대한 작게 만든다.
100만 원소
모든 원소 길이의 합 = 100만

- 0이 앞에 가야 함.
- 110이 없으면 옮길 수 없음

1. 110 앞에가 1이라면 앞에 0이 나올 때까지 앞으로 땡긴다.
2. 110 뒤가 0이라면 뒤에 1이 나올때까지 뒤로 떙긴다.
*/

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(auto& x: s){
        if(x.size() <= 3){
            answer.push_back(x);
            continue;
        }
        
        int cnt = 0; //110 개수
        string tmp = "";
        
        //1. 110 자르기
        for(char c: x){
            tmp += c;
            
            if(tmp.size() >= 3 && tmp.substr(tmp.size() - 3, 3) == "110"){
                cnt++;
                tmp.erase(tmp.size() - 3, 3);
            }
        }
        
        //cout << tmp << '\n';
        
        //2. 110 삽입
        int zero_idx = -1;
        for(int i = tmp.size() - 1; i >= 0; i--){
            if(tmp[i] == '0'){
                zero_idx = i;
                break;
            }
        }
        
        string result = "";
        if(zero_idx == -1){
            while(cnt--) result += "110";
            result += tmp;
        } else {
            result += tmp.substr(0, zero_idx + 1);
            while(cnt--) result += "110";
            result += tmp.substr(zero_idx + 1);
        }
        
        answer.push_back(result);
    }
    
    return answer;
}
