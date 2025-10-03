#include <string>
#include <map>
#include <vector>

#define L_TIME 1439 //시간을 분으로 환산, 23:59분이면 당연히 24시간 - 1

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    
    //데이터 전처리 파트
    //map(rb트리) vs unordered_map(해쉬테이블)
    map<int,int> logs; // 차량번호 -> 입차 시간
    map<int,int> totalTime; // 차량번호 -> 누적 주차 시간

    auto it = records.begin();
    while (it != records.end()) {
        string record = *it;  //한 줄 

        //파싱
        string timeStr = record.substr(0, 5);     //05:34
        string numStr  = record.substr(6, 4);     //5961
        string inout   = record.substr(11);       //IN or OUT

        //분으로 변환
        int hour = stoi(timeStr.substr(0, 2));
        int min  = stoi(timeStr.substr(3, 2));
        int time = hour * 60 + min;

        int carNum = stoi(numStr);

        if (inout == "IN") {
            logs[carNum] = time;  //입차 기록 저장
        } 
        else if (inout == "OUT") {
            // OUT : 시간 계산 + 누적
            int inTime = logs[carNum];
            totalTime[carNum] += (time - inTime);
            logs.erase(carNum); // pop
        }

        ++it;
    }
    
    //연산 파트
    // 1) 남아있는 IN 차량은 23:59로 강제 출차
    for (const auto &p : logs) {
        int car = p.first;
        int inTime = p.second;
        totalTime[car] += (L_TIME - inTime);
    }
    logs.clear();

    // 2. 요금 계산 
    int basicTime = fees[0];
    int basicFee  = fees[1];
    int unitTime  = fees[2];
    int unitFee   = fees[3];

    //차량번호 오름차순으로 answer에 push
    for (const auto &p : totalTime) {
        int car = p.first;
        int t   = p.second;     //총 주차 시간
        int fee = basicFee;

        if (t > basicTime) {
            int extra = t - basicTime;
            //올림 나눗셈: (a + b - 1) / b
            int units = (extra + unitTime - 1) / unitTime;
            fee += units * unitFee;
        }
        answer.push_back(fee);
    }
    return answer;
}