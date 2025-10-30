#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
0을 제거한다.
문자열의 길이를 이진법으로 변환한다.
제거된 0의 개수를 각각 배열에 담는다.
*/

string to_binary(int num){
    string tmp = "";
    
    while(num > 0){
        tmp += to_string(num % 2);
        num /= 2;
    }
    
    reverse(tmp.begin(), tmp.end());
    
    return tmp;
}

vector<int> solution(string s) {
    int cnt = 0;
    int zero = 0;
    
    while(s != "1"){
        string tmp = "";
        
        for(char c: s){
            if(c == '0') zero++;
            else tmp += c;
        }
        
        s = to_binary(tmp.size());
        cnt++;
    }
    
    return {cnt, zero};
}s