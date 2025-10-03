#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// m은 사이 거리 n은 돌 빼는 개수
bool feasible(int m, const vector<int>& rocks, int n) {
    int prev = 0;
    int removed = 0;
    for (auto it = rocks.begin(); it != rocks.end(); it++) {              // rocks는 정렬 
        if (*it - prev < m) {
            removed++;                 // 사이 거리 m을 못 채우므로 이 바위 제거
            if (removed > n) {
                return false;
            }
        } 
        else {
            prev = *it;                  // 간격 m을 만족하니 이 바위를 stay
        }
    }
    return true;                       // 제거 n개 이내로 m 유지 가능
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end()); //정렬 -> 이분탐색의 기본
    rocks.push_back(distance); //끝점 삽입
    
    
    int left = 1;
    int right = distance;
    
    //탐색 대상은 무엇일까?, 1번 간격 거리라 생각했는데 도저히 답이 안나옴
    //그래서 보통 알고리즘 문제는 답을 기준으로 생각하니까
    //답을 구하는 방식은 최소 거리 값 중 최대값이므로,
    //지점 사이의 최소 거리를 기준으로 이분탐색으로 하자.
    while (left <= right) {
        
        int mid = left + (right - left) / 2;
        
        
        //최소 간격이 
        if (feasible(mid,rocks,n)) { 
            answer = mid; //탐색 답
            left = mid + 1;
            
        } 
        
        else {
            right = mid - 1;
        }
    }
    
    
    
    return answer;
}