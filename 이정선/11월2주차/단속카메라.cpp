#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int solution(vector<vector<int> > routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    
    int curCamera = routes[0][1];
    answer++;
    
    for(const auto&route: routes){
        if(curCamera < route[0]){
            curCamera = route[1];
            answer++;
        }
    }
    return answer;
}
