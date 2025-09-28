#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
typedef long long ll;

using namespace std;

string convert(int n, int k){
    string res = "";
    
    while(n > 0){
        res += to_string(n % k);
        n /= k;
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}

bool is_prime(ll num){
    if(num < 2) return false;
    
    for(ll i = 2; i * i <= num; i++)
        if(num % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num = convert(n, k); //k진법으로 변환
    //cout << num << endl;
    
    string token;
    vector<string> tokens;
    stringstream ss(num);
    
    //0으로 분할
    while(getline(ss, token, '0')){
        if(!token.empty()) {
            tokens.push_back(token);
            //cout << token << endl;
        }
    }
    
    //각 숫자가 소수인지 검사
    for(string s: tokens){
        if(is_prime(stoll(s))) answer++;
    }
    
    return answer;
}