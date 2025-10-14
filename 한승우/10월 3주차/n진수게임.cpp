#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

char mapping[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                'A', 'B', 'C', 'D', 'E', 'F'};

string convert(int cnt, int n) {
    if(cnt == 0) return "0";
    
    string tmp = "";
    
    while(cnt > 0){
        tmp += mapping[cnt % n];
        cnt /= n;
    }
    
    reverse(tmp.begin(), tmp.end());
    
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    
    //변환된 숫자 문자열
    for(int number = 0; tmp.size() <= m * t; number++){
        tmp += convert(number, n);
    }
    
    //특정 인덱스 뽑기
    for(int i = p - 1; i < p + (t - 1) * m; i += m) {
        answer += tmp[i];
    }
    
    return answer;
}