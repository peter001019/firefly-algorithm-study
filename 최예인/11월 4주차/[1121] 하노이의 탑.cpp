#include <string>
#include <vector>

using namespace std;

void hanoi(int num, int start, int by, int end, vector<vector<int>> &answer){
    if(num==1){
        answer.push_back({start, end});
        return;
    }
    hanoi(num-1, start, end, by, answer);
    answer.push_back({start, end});
    hanoi(num-1, by, start, end, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 2, 3, answer);
    
    return answer;
}