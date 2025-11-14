#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](const vector<int>&a, const vector<int>&b){
        return a[1]<b[1];
    });
    
    int camera = -30001;
    for(auto &it:routes){
        if(it[0]>camera){
            camera = it[1];
            answer++;
        }
    }
    
    for(int i=0;i<routes.size();i++){
        for(int j=0;j<routes[0].size();j++){
            cout<<routes[i][j]<<" ";
        }
        cout<<'\n';
    }
    
    
    
    
    
    return answer;
}