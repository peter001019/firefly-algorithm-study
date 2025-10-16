#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    queue<int> queue1Q;
    queue<int> queue2Q;
    
    long long queue1Sum = 0;
    long long queue2Sum = 0;
    for(int i = 0; i < queue1.size(); i++){
        queue1Sum += queue1[i];
        queue1Q.push(queue1[i]);
    }
    for(int i = 0; i < queue2.size(); i++){
        queue2Sum += queue2[i];
        queue2Q.push(queue2[i]);
    }
    
    int count = 0;
    
    if((queue2Sum + queue1Sum) % 2 == 1) {
        return -1;
    }
    
    while(count <= 2 * (queue1.size() + queue2.size())){
        if(queue1Sum == queue2Sum) {
            answer = count;
            break;
        }
        if(queue1Sum > queue2Sum) {
            int front = queue1Q.front();
            queue1Sum -= front;
            queue1Q.pop();
            queue2Sum += front;
            queue2Q.push(front);
            count ++;
        } else {
            int front = queue2Q.front();
            queue2Sum -= front;
            queue2Q.pop();
            queue1Sum += front;
            queue1Q.push(front);
            count ++;
        }
    }
    
    return answer;
}
