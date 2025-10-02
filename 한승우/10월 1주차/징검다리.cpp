#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//특정 거리가 최소가 되려면 제거해야 하는 바위 수 counting
int check(int d, vector<int>& rocks, int distance) {
    int cnt = 0;
    int pre_rock = 0;
    
    for(int i = 1; i < rocks.size(); i++){
        //가능한 바위만 저장
        if(rocks[i] - pre_rock >= d){
            pre_rock = rocks[i];
        } else {
            cnt++;
        }
    }
    
    return cnt;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0); rocks.push_back(distance);
    
    sort(rocks.begin(), rocks.end());
    
    int l = 1, r = distance;
    
    while(l <= r){
        int mid = (l + r) / 2;
        
        if(check(mid, rocks, distance) <= n){
            answer = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return answer;
}