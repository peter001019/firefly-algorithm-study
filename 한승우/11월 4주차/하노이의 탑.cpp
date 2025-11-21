#include <string>
#include <vector>

using namespace std;

/*
n번쨰 원판을 3번째로 옮기려면, n-1원판까지가 2번째로 옮겨져야 한다.
*/

vector<vector<int>> answer;

void sol(int n, int a, int b){
    if(n == 1){
        answer.push_back({a, b});
        return;
    }
    
    sol(n - 1, a, 6 - a - b);
    answer.push_back({a, b});
    sol(n - 1, 6 - a - b, b);
}

vector<vector<int>> solution(int n) {   
    sol(n, 1, 3);
    
    return answer;
}