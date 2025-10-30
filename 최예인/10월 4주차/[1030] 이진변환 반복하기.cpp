#include <string>
#include <vector>
#include <bitset>

using namespace std;

int zeroCount = 0;

int removeZero(string x){
    int count = 0;
    for(int i=0;i<x.length();i++){
        if(x[i]=='1'){
            count ++;
        }
    }
    zeroCount +=x.length()-count;

    return count;
}

string changeC(int x){
    string res = "";
    while(x>0){
        res = char('0'+(x%2))+res;
        x = x/2;
    }
    
    return res;
}

bool isOne(string s){
    if(s=="1"){
         return true;
    }
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int count = 0;
    zeroCount = 0;
    
    string sentence = s;
    
    while(!(isOne(sentence))){
        // 1. x의 모든 0을 제거한다
        int length = removeZero(sentence);
    
        // 2. c를 2진법으로 표현
        sentence = changeC(length);
        count ++;
    }
    
    answer.push_back(count);
    answer.push_back(zeroCount);
    
    return answer;
}
