#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string line;
    
    while(true){
        getline(cin, line);

        if(line == ".")
            break;

        stack<char> st;
        bool isBalanced = true;

        for(char c: line){
            if(c == '[' || c == '(') st.push(c);
            else if(c == ']'){
                if(!st.empty() && st.top() == '[') st.pop();
                else isBalanced = false;
            }
            else if(c == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else isBalanced = false;
            }
            else if(c == '.'){
                if(isBalanced && st.empty()) cout << "yes" << "\n";
                else cout << "no" << "\n";
            }
        }
    }

    return 0;
}