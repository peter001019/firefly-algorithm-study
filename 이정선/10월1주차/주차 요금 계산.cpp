#include <bits/stdc++.h>


using namespace std;

int calFee(int defaultTime, int defaultFee, int time, int fee, int allTime) {
    if(allTime <= defaultTime) {
        return defaultFee;
    }
    
    int leaveTime = allTime - defaultTime;
    int unitTime = leaveTime / time;
    if(leaveTime % time >= 1) {
        unitTime+=1;
    }
    return defaultFee + (unitTime * fee);
}

int calTime(string str1, string str2 = "23:59") {
    int time1 = stoi(str1.substr(3, 2)) + stoi(str1.substr(0, 2))*60;
    int time2 = stoi(str2.substr(3, 2)) + stoi(str2.substr(0, 2))*60;
    int allTime = time2 - time1;
    return allTime;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int> > answers;
    
    int defaultTime = fees[0]; // 기본 시간
    int defaultFee = fees[1]; // 기본 요금
    int time = fees[2]; //단위 시간
    int fee = fees[3]; //단위 요금
    
    vector<vector<string> > parsingRecords(records.size(), vector<string>(3));
    vector<bool> usedOut(records.size(), false);

    for(int i = 0; i < records.size(); i++) {
        istringstream ss(records[i]);
        string str;
        int j = 0;
        while(getline(ss, str, ' ')){
            parsingRecords[i][j]=str; 
            j++;
        }
    }
    
    for(int i = 0; i < parsingRecords.size(); i++) {
        if(parsingRecords[i][2] == "OUT") continue;
        for(int j = i; j < parsingRecords.size(); j++) {
            if(parsingRecords[i][1] == parsingRecords[j][1] && parsingRecords[j][2] == "OUT" && !usedOut[j]){
                usedOut[j] = true;
                string str1 = parsingRecords[i][0];
                string str2 = parsingRecords[j][0];
                
                int allTime = calTime(str1, str2);
                
                bool isFind = false;
                for(int k = 0; k < answers.size(); k++) {
                    if(parsingRecords[i][1] == answers[k].first) {
                        answers[k].second += allTime;

                        isFind = true;
                    }
                }
                if(isFind == false) {
                    answers.push_back({parsingRecords[i][1], allTime});
                }
                break;
            }
            if(j == parsingRecords.size() - 1){
                bool isFind = false;
                string str1 = parsingRecords[i][0];
                int allTime = calTime(str1);

                for(int k = 0; k < answers.size(); k++) {
                    if(parsingRecords[i][1] == answers[k].first) {
                        answers[k].second += allTime;
                        isFind = true;
                        break;
                    }
                }
                if(isFind == false) {
                    answers.push_back({parsingRecords[i][1], allTime});
                }
            }
        }
    }

    sort(answers.begin(), answers.end());
    
    for(int i = 0; i < answers.size(); i ++) {
        int a = calFee(defaultTime, defaultFee, time, fee, answers[i].second);
        answer.push_back(a);
    }
    
    return answer;
}
