#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    vector<int> A;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    vector<int> V;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        V.push_back(temp);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < V.size(); i++)
    {
        if (binary_search(A.begin(), A.end(), V[i]))
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
}