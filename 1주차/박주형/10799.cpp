#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> stk;
    string str;
    cin >> str;

    int total = 0;
    for (int i = 0; i < str.length(); i++)
    {
        stk.push(str[i]);
    }

    stack<int> stk2;
    while (!stk.empty())
    {
        char temp = stk.top();
        stk.pop();
        // cout << temp << '\n';
        if (!stk.empty() && stk.top() == '(' && temp == ')')
        {
            // cout << stk.top() << '\n';
            stk.pop();
            total += stk2.size();
            // cout << total << '\n';
        }
        else if (temp == '(')
        {
            stk2.pop();
        }
        else
        {
            stk2.push(temp);
            total++;
        }
    }
    cout << total;
    return 0;
}