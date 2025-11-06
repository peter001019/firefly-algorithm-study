#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<int> list;
    
    for(int i = 0; i < stations.size(); i++){
        if(i == 0) {
            if(stations[i] - w - 1 <= 0) continue;
            list.push_back(stations[i] - w - 1);
        } else {
            if(stations[i] - w - (stations[i-1] + w) - 1 <= 0) continue;
            list.push_back(stations[i] - w - (stations[i-1] + w) - 1);
        }
    }
    
    if(stations[stations.size() - 1] != n) {
        if(n - (stations[stations.size() - 1] + w) > 0) {
            list.push_back(n - (stations[stations.size() - 1] + w));
        }

    }
    
    for(int i = 0; i < list.size(); i++){
        answer += (list[i] - 1 )/ (2 * w + 1) + 1;
    }
    
    return answer;
}
