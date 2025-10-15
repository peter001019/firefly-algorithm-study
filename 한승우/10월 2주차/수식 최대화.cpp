#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

typedef long long ll;

using namespace std;

unordered_map<string, int> op;

//op1이 op2보다 우선순위가 높은지?
bool isPrior(string op1, string op2){
    return op[op1] <= op[op2];
}

void toPostfix(string& exp, vector<string>& postfix){
    stack<string> st;
    int i = 0;
    
    while(i < exp.size()){
        if(isdigit(exp[i])){
            string num = "";
            
            while(isdigit(exp[i])){
                num += exp[i];
                i++;
            }
            
            postfix.push_back(num);
        } else {
            while(!st.empty() && isPrior(st.top(), {exp[i]})){
                postfix.push_back(st.top());
                st.pop();
            }
            
            st.push({exp[i]});
            i++;
        }
    }
    
    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }
}

ll cal(vector<string>& postfix){
    stack<ll> st;
    
    for(string s: postfix){
        if(isdigit(s[0])) st.push(stoi(s));
        else {
            ll b = st.top(); st.pop();
            ll a = st.top(); st.pop();
            
            if(s == "*") st.push(a * b);
            else if(s == "+") st.push(a + b);
            else st.push(a - b);
        }
    }
    
    ll ans = st.top(); st.pop();
    
    return abs(ans);
}

long long solution(string exp) {
    long long answer = 0;
    
    //연산자 우선순위 순열
    vector<int> v = {1, 2, 3};
    
    do {
        vector<string> postfix;
        op["*"] = v[0];
        op["+"] = v[1];
        op["-"] = v[2];
        
        toPostfix(exp, postfix);
        answer = max(answer, cal(postfix));
    } while(next_permutation(v.begin(), v.end()));
    
    return answer;
}