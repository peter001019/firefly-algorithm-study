#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;
char arr[] = {'A', 'E', 'I', 'O', 'U'};

int cnt = 1;
void init(string s) {
    if(s.size() > 5) return;
    
    if(!s.empty()) map[s] = cnt++;
    
    for(int i = 0; i < 5; i++){
        init(s + arr[i]);
    }
}

int solution(string word) {
    init("");
    
    return map[word];
}