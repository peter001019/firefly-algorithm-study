#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, string> name;

void save(vector<string>& record){
    for(string& s: record){
        stringstream ss(s);
        string a, b, c;
        ss >> a >> b >> c;
        
        if(a != "Leave"){
            name[b] = c;
        }
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    save(record);
    
    for(string& s: record){
        stringstream ss(s);
        string a, b, c;
        ss >> a >> b >> c;
        
        string result;
        
        if(a == "Enter"){
            result = name[b] + "님이 들어왔습니다.";
        } else if(a == "Leave"){
            result = name[b] + "님이 나갔습니다.";
        } else continue;
        
        answer.push_back(result);
    }
    
    return answer;
}