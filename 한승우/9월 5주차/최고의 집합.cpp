#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s){
        answer = {-1};
        return answer;
    }
    
    int num = s / n;
    int cnt = 0;
    
    while(num <= s && cnt < n - 1){
        answer.push_back(num);
        s -= num;
        cnt++;
    }
    
    if(s > 0) answer.push_back(s);
    
    sort(answer.begin(), answer.end());
    
    return answer;
}