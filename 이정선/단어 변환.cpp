#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool oneDiff(string str1, string str2) {
    int count = 0;
    for(int i = 0; i < str1.length(); i++) {
        if(str1[i] != str2[i]) count++;
        if(count > 1) return false;
    }
    return (count == 1);
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(50, false);
    queue<pair<string, int>> q; // (단어, depth)

    int answer = 0;

    q.push(make_pair(begin, 0));
    
    while (!q.empty()) {
        auto p = q.front();
        string currentWord = p.first;
        int currentDepth = p.second;
        q.pop();

        if (currentWord == target) {
            answer = currentDepth;
        }

        for (int i = 0; i < words.size(); i++) {
            if(visited[i]) continue;
            if(oneDiff(currentWord, words[i])) {
                visited[i] = true;
                q.push(make_pair(words[i], currentDepth + 1));
            }
        }
    }

    return answer;
}
