#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
단어 리스트의 길이는 최대 100

1. 이전 단어의 마지막 글자와 현재 단어의 첫번째 글자가 일치하는지 검사
2. 이전에 사용했던 단어가 또 사용되는지 검사
3. 사람들의 순번 카운팅 (index를 n으로 나눈 몫 = 차례, 나머지 = 번호)
*/
unordered_set<string> set;

//올바른지?
bool check(int i, const vector<string>& words){
    return (words[i - 1].back() == words[i].front()) && 
        set.insert(words[i]).second;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    set.insert(words[0]);
    
    for(int i = 1; i < words.size(); i++){
        if(!check(i, words)){
            answer = {i % n + 1, i / n + 1};
            break;
        }
    }

    return answer;
}