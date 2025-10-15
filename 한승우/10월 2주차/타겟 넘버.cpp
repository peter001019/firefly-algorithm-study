#include <string>
#include <vector>

using namespace std;

int target;

int dfs(int cal, int idx, const vector<int>& numbers){
    if(idx == numbers.size()){
        if(cal == target) return 1; //하나 찾음
        return 0;
    }
    
    return dfs(cal + numbers[idx], idx + 1, numbers) + dfs(cal - numbers[idx], idx + 1, numbers);
}

int solution(vector<int> numbers, int tg) {
    int answer = 0; 
    target = tg;
    
    answer = dfs(0, 0, numbers);
    
    return answer;
}