#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
출차 시점으로 정렬
첫번 째 차의 출차 위치에 카메라를 놓는다.
만약 다음 차의 진입 시점이 늦는다면 카메라를 새로 놓는다.
*/

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end(), [](const auto& a, const auto& b){
        return a[1] < b[1];
    });
    
    int exit = routes[0][1];
    for(int i = 1; i < routes.size(); i++){
        if(exit >= routes[i][0]) continue;
        exit = routes[i][1];
        answer++;
    }
    
    return answer;
}