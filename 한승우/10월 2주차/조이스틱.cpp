#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//조이스틱 상하 이동 계산
int updown(char& c){
    int tmp = c - 'A';
    
    return tmp > 13 ? 26 - tmp : tmp;
}

int solution(string name) {
    int answer = 0;
    int j;
    int move = 41;
    int len = name.size();
    
    for(int i = 0; i < name.size(); i++){
        answer += updown(name[i]);
        
        j = i + 1;
        while(j < name.size() && name[j] == 'A') j++;
        
        move = min({move, len - 1, 2 * i + (len - j), 2 * (len - j) + i});
    }
    
    answer += move;
    
    return answer;
}