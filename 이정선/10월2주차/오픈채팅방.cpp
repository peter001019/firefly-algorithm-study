#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string> > action; // Enter/Leave/Change , uid
    unordered_map<string, string> nickname; // uid , Nickname
    
    for(int i = 0 ; i < record.size(); i++) {
        istringstream ss(record[i]);
        string order, uid, nick;
        ss >> order >> uid >> nick;
        if(order == "Change") {
            nickname[uid] = nick;
        } else {
            if(order == "Enter") {
                nickname[uid] = nick;
            }
            action.push_back({order, uid});
        }
    }
    
    for(int i = 0 ; i < action.size(); i++) {
        if(action[i].first == "Enter"){
            string s = nickname[action[i].second] + "님이 들어왔습니다.";
            answer.push_back(s);
        } else {
            string s = nickname[action[i].second] + "님이 나갔습니다.";
            answer.push_back(s);
        }
    }
    
    return answer;
}
