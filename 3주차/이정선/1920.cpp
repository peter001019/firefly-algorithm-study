#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    cin >> M;
    vector<int> Answer;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        int binary = binarySearch(A, a);
        Answer.push_back(binary);
    }
    for (int i = 0; i < M; i++)
    {
        cout << Answer[i] << endl;
    }
}