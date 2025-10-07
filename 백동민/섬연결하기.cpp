#include <bits/stdc++.h>
using namespace std;
#define INF 999999

struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]); // 경로 압축
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // 이미 같은 집합
        parent[b] = a;            // 그냥 붙임 (rank 없이)
        return true;
    }
};

// n: 섬 개수, costs: [시작, 도착정점, 가주치]

// [[0,1,1]
//(출발, 도착, cost),...] 
//그래프 문제 
//가장 적은 비용으로 모두를 통행(길찾기) 
//현재 주어지는 건 간선 리스트 -> 프림 혹은 크루스칼 알고리즘

bool compareCost(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];//비용 기준으로 오름차순 정렬
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //1: 간선 비용 기준 오름차순 정렬
    sort(costs.begin(), costs.end(), compareCost);

    DSU dsu(n);
    int edgesUsed = 0;

    //2. 간선을 하나씩 확인
    for (int i = 0; i < costs.size(); i++) {
        int u = costs[i][0];
        int v = costs[i][1];
        int w = costs[i][2];

        //사이클이 안 생기면 선택
        if (dsu.unite(u, v)) {
            answer += w;
            edgesUsed++;
            if (edgesUsed == n - 1) break; //최소 신장트리 완성
        }
    }

    return answer;
}