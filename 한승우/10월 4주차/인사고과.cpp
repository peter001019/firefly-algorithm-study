#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//3,2 / 3,2 / 2,1 / 2,1

int solution(vector<vector<int>> scores) {
    int answer = -1;
    vector<int> wanho = scores[0];
    
    sort(scores.begin(), scores.end(), 
         [](const auto& a, const auto& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
         }
    );
    
    int s1 = scores[0][0]; int s2 = scores[0][1];
    for(int i = 0; i < scores.size(); i++){
        if(s1 > scores[i][0] && s2 > scores[i][1]){
            if(scores[i] == wanho) return -1;
            scores[i][0] = -1; scores[i][1] = -1;
        } else {
            s1 = scores[i][0]; s2 = scores[i][1];
        }
    }
    
    sort(scores.begin(), scores.end(),
        [](const auto& a, const auto& b){
            return a[0] + a[1] > b[0] + b[1];
        }    
    );
    
    int cur_rank = 0;
    int cur_score = 200002;
    for(int i = 0; i < scores.size(); i++){
        if(cur_score > scores[i][0] + scores[i][1]){
            cur_rank = i + 1;
            cur_score = scores[i][0] + scores[i][1];
        }
        
        if(scores[i] == wanho){
            answer = cur_rank;
            break;
        }
    }
    
    return answer;
}