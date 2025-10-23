#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
A팀의 순서가 나왔을 때 B팀의 순서를 정하여 최대 승점을 구하라

1. 순열
10만! => 시간 초과

2. 그리디
첫번째 원소보다 큰 것 중에 최대한 작은 것을 선택한다. 
*/

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    vector<bool> visited(B.size(), false);
    sort(B.begin(), B.end());
    
    for(int i: A){
        auto it = upper_bound(B.begin(), B.end(), i);
        
        //B의 팀원이 다 작음
        if(it == B.end()) continue;
        else {
            //방문하지 않은 것 찾기
            while(it != B.end() && visited[it - B.begin()]) it++;
            
            if(it != B.end()){
                visited[it - B.begin()] = true;
                answer++;
            }
        }
    }
    
    return answer;
}