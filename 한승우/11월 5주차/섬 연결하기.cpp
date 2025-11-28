#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> p(100, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
    u = find(u); v = find(v);
    
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[v] = u;
    return 1;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), [](const auto& a, const auto& b){
        return a[2] <= b[2];
    });
    
    int cnt = 0;
    for(const auto& c: costs){
        if(!is_diff_group(c[0], c[1])) continue;
        answer += c[2];
        cnt++;
        if(cnt == n - 1) break;
    }
    
    return answer;
}