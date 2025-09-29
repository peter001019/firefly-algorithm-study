#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq(works.begin(), works.end());
    
    while(n > 0){
        int num = pq.top();
        if(num == 0) break;
        
        pq.pop();
        num--;
        n--;
        pq.push(num);
    }
    
    while(!pq.empty()){
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    
    return answer;
}