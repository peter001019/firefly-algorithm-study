#include <string>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
#define pii pair<int, int> 

/*
최단경로 찾기 + 가중치 = dijkstra

1. s -> a, s -> b의 최단 경로를 구한다.
겹치는 경로는 하나만 계산한다. => 최단 경로와 합승이 최소가 되는 경로는 다르다.

2. s -> k -> a or b

s -> k + k -> a + k -> b가 최소가 되는 값을 찾는다.
*/

const int INF = 1e9;
int d[205][205];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
    
    for(const auto& v: fares){
        d[v[0]][v[1]] = v[2];
        d[v[1]][v[0]] = v[2];
    }
    
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    
    //floyd
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    
    for(int k = 1; k <= n; k++){
        if(d[s][k] == INF || d[k][a] == INF || d[k][b] == INF) continue;
        
        answer = min(answer, d[s][k] + d[k][a] + d[k][b]);
    }
    
    return answer;
}