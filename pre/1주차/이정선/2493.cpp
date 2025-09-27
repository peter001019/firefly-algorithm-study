#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    stack<pair<int, int>> stack;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        while (!stack.empty() && stack.top().second <= temp)
        {
            stack.pop();
        }
        if (stack.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << stack.top().first << " ";
        }
        stack.push({i + 1, temp});
    }
}