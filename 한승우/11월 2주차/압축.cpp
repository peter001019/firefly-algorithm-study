#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    
    string tmp;
    for(int i = 0; i < 26; i++){
        tmp += 'A' + i;
        dict[tmp] = i + 1;
        tmp = "";
    } 
    
    string w = {msg[0]};
    
    for(int i = 1; i < msg.size(); i++){
        //현재 입력이 사전에 있음
        if(dict.find(w + msg[i]) != dict.end()){
            w += msg[i];
            continue;
        }
        
        answer.push_back(dict[w]);
        dict[w + msg[i]] = dict.size() + 1;
        w = msg[i];
    }
    answer.push_back(dict[w]);
    
    return answer;
}
