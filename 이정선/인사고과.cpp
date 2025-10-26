#include <bits/stdc++.h>

using namespace std;

// 반례: 총 합이 꼴지가 아니어도 인센티브 대상이 아닐 수 있음! 

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] != b[0]) return a[0] > b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    
    vector<int> myScore = scores[0];
    
    scores.erase(scores.begin());
    sort(scores.begin(), scores.end(), cmp);
    
    vector<vector<int> > newScore;
    
    for(const auto &s: scores){
        if(myScore[0] < s[0] &&  myScore[1] < s[1]){
            return -1;
        }
    }
    
    int maxSecond = -1;
    
    for(const auto &s: scores){
        // scores의 first는 내림차순, second는 오름차순
        
        // s[1] < maxSecond 
        // 이 비교가 참이라면 일단 second 값은 확실하게 선행하는 값보다 작은게 있음을 의미함
        // 만약 first가 같음을 가정한다면 second는 first값이 같을 때 오름차순이므로, first값도 같지 않음을 의미 
        // 그러나 선행하는 값들의 first는 모두 내 first 값보다 큼!
        
        if(s[1] < maxSecond) {
            continue; 
        } 
        
        newScore.push_back(s);

        if (s[1] > maxSecond) {
            maxSecond = s[1];
        }
    }
    
    for(int i = 0; i < newScore.size(); i++){
        if(newScore[i][0] + newScore[i][1] > myScore[0] + myScore[1]){
            answer ++;
        }
    }
    
    return answer;
}
