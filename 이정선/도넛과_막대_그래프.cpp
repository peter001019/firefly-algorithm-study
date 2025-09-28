#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    vector<bool> state(1000000, false);

    vector<int> out(1000000, 0);
    vector<int> in(1000000, 0);
    int start;
    for(int i = 0; i < edges.size(); i++) {
        out[edges[i][0]] += 1;
        in[edges[i][1]] += 1;
        state[edges[i][0]] = true;
        state[edges[i][1]] = true;
    }
    for(int i = 0; i < edges.size(); i++) {
        if(!state[i]) continue;
        if(in[i] == 0 && out[i] >= 2) {
            start = i;
            break;
        }
        continue;
    }
    for(int i = 0; i < edges.size(); i++) {
        if(edges[i][0] == start){
            in[edges[i][1]] -= 1;
        }
    }
    
    int lineCount = 0;
    int eightCount = 0;
    int aloneLine = 0;
    for(int i = 0; i < out.size(); i++) {
        if(i == start) {
            continue;
        }
        if(!state[i]) continue;
        if(out[i] + in[i] == 0){
            lineCount += 1;
            continue;
        }
        if(out[i] + in[i] == 1){
            aloneLine += 1;
            continue;
        }
        if(out[i] == 2 && in[i] == 2){
            eightCount += 1;
            continue;
        }
        
    }
    int total = out[start];
    answer.push_back(start);
    answer.push_back(total-lineCount-aloneLine/2-eightCount);
    answer.push_back(lineCount+aloneLine/2);
    answer.push_back(eightCount);
    
    cout << state[2];
    return answer;
}
