#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    vector<int> bestList(n);
    
    if(s < n) return {-1};
    
    // s 를 배열에 분할
    for(int i = 0; i < n; i ++) {
        bestList[i] += s/n;
    }
    
    for(int i = 0; i < s%n; i ++) {
        bestList[n-1-i] += 1;
    }
    
    answer = bestList;
    return answer;
}
