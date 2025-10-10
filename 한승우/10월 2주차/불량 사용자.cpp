#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

//index만 저장
vector<int> ban_list[8];
set<vector<int>> result;

bool check(string& user, string& ban){
    if(user.size() != ban.size()) return false;
    
    for(int i = 0; i < user.size(); i++){
        if(ban[i] != '*' && user[i] != ban[i]) return false;
    }
    
    return true;
}

vector<int> comb;
bool is_in[8];

void dfs(int idx, int len){
    if(idx == len){
        // for(int i: comb) cout << i << " ";
        // cout << endl;
        vector<int> tmp = comb;
        sort(tmp.begin(), tmp.end());
        result.insert(tmp);
        return;
    }
    
    for(int i: ban_list[idx]){
        if(!is_in[i]){
            comb.push_back(i);
            is_in[i] = true;
            dfs(idx + 1, len);
            comb.pop_back();   
            is_in[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    //1. 가능한 경우의 수 저장
    for(int i = 0; i < banned_id.size(); i++){
        for(int j = 0; j < user_id.size(); j++){
            if(check(user_id[j], banned_id[i])){
                ban_list[i].push_back(j);
            }
        }
    }
    
    //2. 조합 생성
    dfs(0, banned_id.size());
    
    answer = result.size();
    
    return answer;
}