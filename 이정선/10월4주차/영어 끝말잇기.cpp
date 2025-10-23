#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<string> currentWords;

    currentWords.push_back(words[0]);
    
    for(int i = 1; i < words.size(); i++){
        int turn = i % n + 1;
        int currentNum = i / n + 1;
        
        string currentWord = words[i];
        string prevWord = words[i - 1];
            
        char currentfirstWord = currentWord[0];
        char prevlastWord = prevWord[prevWord.length() - 1];
            
        if(currentfirstWord != prevlastWord) {
            answer.push_back(turn);
            answer.push_back(currentNum);
            return answer;
        }
            
        if(find(currentWords.begin(), currentWords.end(), currentWord) != currentWords.end()) {
            answer.push_back(turn);
            answer.push_back(currentNum);
            return answer;
        }
        currentWords.push_back(currentWord);
    }
    
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}
