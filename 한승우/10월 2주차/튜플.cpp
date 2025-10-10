#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_save[100001]; //저장되었는가?
vector<int> input[501]; //집합 크기 별 저장

void parse(string& s){
    int idx = 0;
    
    while(idx < s.size()){
        idx++;
        
        if(s[idx] == '{'){
            idx++;
            vector<int> v;
            
            while(s[idx] != '}'){
                if(s[idx] == ',') {
                    idx++;
                    continue;
                }
                
                string num;
                
                while(isdigit(s[idx])){
                    num += s[idx];
                    idx++;
                }
                
                v.push_back(stoi(num));
            }
            
            //값 복사
            for(int i: v){
                input[v.size()].push_back(i);
            }
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    
    parse(s);
    
    // for(int i = 1; i <= 4; i++){
    //     for(int n: input[i]) cout << n << " ";
    //     cout << endl;
    // }
    
    for(int i = 1; i <= 500; i++){
        if(input[i].empty()) break;
        
        for(int n: input[i]){
            if(!is_save[n]){
                answer.push_back(n);
                is_save[n] = true;
            }
        }
    }
    
    return answer;
}