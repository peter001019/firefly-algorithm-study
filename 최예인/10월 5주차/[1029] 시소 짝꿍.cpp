#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    unordered_map<double, int> w;
    
    sort(weights.begin(), weights.end());
    
    // 2, 3, 4배 => 2:3, 2:4, 3:4
    for(auto it:weights){
        if(w.count(it)){
            answer = answer+w[it];
        }
        if(w.count(it*(2.0/3.0))){
            answer = answer+w[it*(2.0/3.0)];
        }
        if(w.count(it*(3.0/2.0))){
            answer = answer+w[it*(3.0/2.0)];
        }
        if(w.count(it*(2.0/4.0))){
            answer = answer+w[it*(2.0/4.0)];
        }
        if(w.count(it*(4.0/2.0))){
            answer = answer+w[it*(4.0/2.0)];
        }
        if(w.count(it*(4.0/3.0))){
            answer = answer+w[it*(4.0/3.0)];
        }
        if(w.count(it*(3.0/4.0))){
            answer = answer+w[it*(3.0/4.0)];
        }
        w[it]++;
    }
    
    
    return answer;
}