#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

/*
숫자를 이진트리로 표현할 수 있는가?
ex) 100 같은 숫자는 포화 이진트리로 만들 수 없는 숫자.

7 = 111
42 = 101010
5 = 101

63 = 111111
111 = 1101111
95 = 1011111

1. 십진수를 이진수로 변환
2. 포화 이진트리로 만들기 위해 앞에 0을 채워넣음
    2^N-1

3. 만든 이진수가 트리가 맞는지? (끊기지 않았는지)
*/

string to_binary(ll num){
    string res = "";
    
    while(num >= 1){
        res.push_back(num % 2 + '0');
        num /= 2;
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}

void make_full(string& num){
    //포화 이진 트리 길이 구하기
    ll len = 1;
    while(len <= num.size()) len *= 2;
    len--;
    
    //0 붙히기
    string tmp = "";
    while(tmp.size() < len - num.size()) tmp += '0';
    
    num = tmp + num;
}

bool check(int l, int r, string& num){
    //leaf node
    if(l == r) return true;
    
    int mid = (l + r) / 2;
    int lc = (l + mid - 1) / 2;
    int rc = (mid + 1 + r) / 2;
    
    //자식이 하나라도 있는데, 루트가 0이면 false
    if(num[mid] == '0' && (num[lc] == '1' || num[rc] == '1')) return false;
    
    return check(l, mid - 1, num) && check(mid + 1, r, num);
}

vector<int> solution(vector<ll> numbers) {
    vector<int> answer;
    
    for(ll num: numbers){
        string s = to_binary(num);
        make_full(s);
        
        if(check(0, s.size() - 1, s)) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}