#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int start = 0; start < s.size(); start++){
        string tmp = "";
        int len = s.size();
        int idx = start;
        
        //문자열 복사
        while(len--){
            tmp += s[idx];
            idx = (idx + 1) % s.size();
        }
        
        //검사
        stack<char> st;
        bool isValid = true;
        for(int i = 0; i < tmp.size(); i++){
            if(tmp[i] == '(' || tmp[i] == '[' || tmp[i] == '{')
                st.push(tmp[i]);
            else {
                if(!st.empty() && ((st.top() == '(' && tmp[i] == ')') ||
                    (st.top() == '[' && tmp[i] == ']') ||
                    (st.top() == '{' && tmp[i] == '}')))
                    st.pop();
                else {
                    isValid = false;
                    break;
                }
            }
        }
        
        if(st.empty() && isValid) answer++;
    }
    
    return answer;
}