#include <bits/stdc++.h>
using namespace std;
vector<int> v(500002);

int main()
{
    int n;
    cin >> n;
    int num;
    stack<pair<int, int>> stk1;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        stk1.push({num, i});
    }

    stack<pair<int, int>> stk2;
    // vector<int> v;
    for (int i = n; i > 0; i--)
    {
        if (stk1.empty())
            break;
        pair<int, int> num1 = stk1.top();
        stk1.pop();
        if (stk1.empty())
            break;
        pair<int, int> num2 = stk1.top();

        if (num1.first >= num2.first)
        {
            stk2.push(num1);
        }
        else
        {
            v[num1.second] = num2.second;
            // cout << num1.first << " " << num2.second << '\n';

            while (!stk2.empty())
            {
                pair<int, int> num3 = stk2.top();
                if (num2.first >= num3.first)
                {
                    v[num3.second] = num2.second;
                    // cout << num3.first << " " << num2.second << '\n';
                    stk2.pop();
                }
                else
                {
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}