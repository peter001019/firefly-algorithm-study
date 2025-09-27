#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> vec;

    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int num;
        queue<pair<int, int>> q;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            cin >> num;
            v.push_back(num);
            if (i == M)
            {
                q.push({num, 1});
            }
            else
            {
                q.push({num, 0});
            }
        }

        int i = 0;
        sort(v.begin(), v.end(), greater<int>());

        while (!q.empty())
        {
            if (q.front().first == v[i])
            {
                if (q.front().second == 1)
                {
                    int a = i + 1;
                    vec.push_back(a);
                }
                q.pop();
                i++;
            }
            else
            {
                pair<int, int> temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << '\n';
    }
    return 0;
}