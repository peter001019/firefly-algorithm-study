#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> m;
    
    int num = 1;
    
    for(char c = 'A';c<='Z';c++){
        string s(1, c);
        m[s] = num++;
    }
    
    int i=0;
    while(i<msg.length()){
        string w(1, msg[i]);
        int j= i+1;
        
        // 사전에서 찾음
        while(j<=msg.length()&&m.count(msg.substr(i, j-i))){
            w = msg.substr(i, j-i);
            j++;
        }
        
        answer.push_back(m[w]);
        
        // 사전에 추가
        if(j<=msg.length()){
            m[msg.substr(i, j-i)] = num++;
        }
        
        // 저장한 만큼 건너뛰기
        i = i+w.size();
    }
    
    return answer;
}