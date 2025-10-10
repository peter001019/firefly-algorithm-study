#include <bits/stdc++.h>

using namespace std;
//튜플 정의 조건 : n개의 요소의 집합, 중복 X, 순서 O
/*
{{a1}, {a1, a2}, {a1, a2, a3}, {a1, a2, a3, a4}, ... {a1, a2, a3, a4, ..., an}}
{a1, a2, a3, a4, ..., an}->얘를 찾으면 됨
a1
a1 a2
a1 a2 a3
a1 a2 a3 a4
a1 a2 a3 a4 a5
5   4  3  2 1
빈도수로 정렬를 하면 아~ 튜플 나오겠구나가 되었습니다.
타겟 사이즈가 제일 숫자가 큰거 

예를 들어 튜플이 (2, 1, 3, 4)인 경우 이는

{{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}} 
와 같이 표현할 수 있습니다. 
이때, 집합은 원소의 순서가 바뀌어도 상관없으므로
{{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}
{{2, 1, 3, 4}, {2}, {2, 1, 3}, {2, 1}}
{{1, 2, 3}, {2, 1}, {1, 2, 4, 3}, {2}}

*/

bool Cmp(const pair<int,int>& a, const pair<int,int>& b){
    if (a.second != b.second) {
        return a.second > b.second;// 빈도 
    }
    return a.first < b.first; // 값 
}

vector<int> solution(string s) {
    vector<int> answer;          
    unordered_map<int,int> count;//이거는 이제 빈도수를 저장하는 배열입니다.
    //key : 0~100000인 요소 value : 빈도수
    string num;

    // 숫자 get하기
    for (char c : s) {
        if (isdigit(c)) {
            num += c;//숫자 더하기
        } 
        else {
            if (!num.empty()) {
                count[stoi(num)]++;  //count 로 구하기
                num.clear();
            }
        }
    }
    if (!num.empty()) { // 마지막 토큰 처리
        count[stoi(num)]++;
    }

    //값, 빈도  빈도 내림차순 정렬
    vector<pair<int,int>> items(count.begin(), count.end());
    sort(items.begin(), items.end(),Cmp);//내림차순으로 정렬

    answer.reserve(items.size());
    for (auto& [val, freq] : items) { //pair가 이래서 편해요
        answer.push_back(val);
    }
    return answer;
}