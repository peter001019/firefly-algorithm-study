#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Name {
    string filename;
    string head; //소문자
    int number; //숫자만
    string tail;
};

vector<Name> names;

void input(vector<string>& files){    
    for(string s: files){
        Name n; string tmp = "";
        n.filename = s;
        
        int idx = 0;
        
        //head 입력
        while(!isdigit(s[idx])){
            tmp += tolower(s[idx]); idx++;
        }
        n.head = tmp;
        
        //number 입력
        tmp = "";
        int limit = 0; //number는 최대 5글자
        while(isdigit(s[idx]) && limit <= 5){
            tmp += s[idx]; idx++; limit++;
        }
        n.number = stoi(tmp);
        
        //tail 입력
        tmp = "";
        while(idx < s.size()){
            tmp += s[idx]; idx++;   
        }
        n.tail = tmp;
        
        names.push_back(n);
    }
}

bool compare(Name n1, Name n2){
    if(n1.head != n2.head) return n1.head < n2.head;
    return n1.number < n2.number;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    input(files);
    stable_sort(names.begin(), names.end(), compare);
    for(Name n: names)
        answer.push_back(n.filename);
    
    return answer;
}