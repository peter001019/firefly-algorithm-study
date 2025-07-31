#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string line;
    cin >> n;
    cin.ignore();
    stack<string> stack;
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
            stack.push(words[1]);
        }
        else if (words[0] == "pop")
        {
            if (stack.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << stack.top() << endl;
                stack.pop();
            }
        }
        else if (words[0] == "size")
        {
            cout << stack.size() << endl;
        }
        else if (words[0] == "empty")
        {
            if (stack.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (words[0] == "top")
        {
            if (stack.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << stack.top() << endl;
            }
        }

        words.clear();
    }
    return 0;
}