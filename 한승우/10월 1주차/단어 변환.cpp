#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//두 문자열의 다른 문자 개수가 1개인지?
bool check(string a, string b){
    int cnt = 0;
    
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) cnt++;
        if(cnt > 1) return false;
    }
    
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    //시작점 설정위해 begin을 queue에 삽입
    words.push_back(begin);
    
    queue<int> q;
    vector<int> visited(words.size(), 0);
    
    int target_idx = -1;
    
    //begin 방문 처리
    visited[words.size() - 1] = 1;
    q.push(words.size() - 1);
    
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        
        if(words[idx] == target){
            answer = visited[idx] - 1;
            break;
        }
        
        for(int i = 0; i < words.size(); i++){
            if(!visited[i] && check(words[idx], words[i])){
                visited[i] = visited[idx] + 1;
                q.push(i);
            }
        }
    }
    
    return answer;
}