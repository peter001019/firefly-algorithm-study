#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string line;
    cin >> n;
    cin.ignore();
    queue<string> q;
    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        istringstream iss(line);
        string word;

        while (iss >> word)
        {
            words.push_back(word);
        }

        if (words[0] == "push")
        {
            q.push(words[1]);
        }
        else if (words[0] == "pop")
        {
            if (q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (words[0] == "size")
        {
            cout << q.size() << endl;
        }
        else if (words[0] == "empty")
        {
            if (q.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (words[0] == "front")
        {
            if (q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.front() << endl;
            }
        }
        else if (words[0] == "back")
        {
            if (q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.back() << endl;
            }
        }
        words.clear();
    }
    return 0;
}