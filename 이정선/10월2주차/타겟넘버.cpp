#include <bits/stdc++.h>

using namespace std;

void dfs(int currentIndex, vector<int> numbers, int sum, int target, int &answer) {
    // 마지막 인덱스까지 전부 연산이 완료되었을 때,
    if(currentIndex == numbers.size()) {
        // 현재 구한 합계가 target 넘버와 같으면 
        if(sum == target) {
            // 경우의 수 한 가지 추가!
            answer++;
        } 
        // 합계가 다르면 그낭 return
        return;
    }
    // sum에 현재 인덱스값을 +/- 해주면서 dfs 호출
    dfs(currentIndex + 1, numbers, sum + numbers[currentIndex], target, answer);
    dfs(currentIndex + 1, numbers, sum - numbers[currentIndex], target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, numbers, 0, target, answer);
    
    return answer;
}
