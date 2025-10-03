#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

//주차 시간 계산
int cal_time(string in, string out){
    int h = stoi(out.substr(0, 2)) - stoi(in.substr(0, 2));
    int m = stoi(out.substr(3, 2)) - stoi(in.substr(3, 2));
    
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> cars; //차량별 입출차 시각
    
    //차량별 입출차 시각 저장
    for(string record: records){
        stringstream ss(record);
        string time, name, inout;
        
        ss >> time >> name >> inout;
        cars[name].push_back(time);
    }
    
    //주차 요금 계산 및 저장    
    for(auto kv: cars){
        vector<string>& v = kv.second;
        
        //출차 내역이 없는 차량은 23:59 출차 기록 삽입
        if(v.size() % 2 == 1) v.push_back("23:59");
        
        //1. 주차 시간 계산
        int time = 0; //누적 주차 시간
        for(int i = 0; i < v.size(); i += 2){
            time += cal_time(v[i], v[i + 1]);
        }
        
        //2. 주차 요금 계산
        int fee = fees[1];
        if(time > fees[0]){
            fee += ceil((time - fees[0]) / (double)fees[2]) * fees[3];
        }
        
        //3. 저장
        answer.push_back(fee);
    }
    
    return answer;
}
