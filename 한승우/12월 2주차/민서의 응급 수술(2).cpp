#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
모든 정점을 연결하여 DAG로 만들기 위한 최소 연산

1. 각 연결된 요소들을 찾는다.
2. 각 집합을 연결하는 횟수를 센다.
3. if 연결 요소 중에 cycle이 존재한다면? -> 하나 제거해준다.

-----
사이클을 만드는 간선이 여러 개일 수 있다는 사실을 간과함..
*/

int n, m, cnt;
vector<int> p(100005, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) {
        cnt++; //cycle인 경우 해당 간선 제거
        return;
    }

    if(p[a] > p[b]) swap(a, b); //b가 rank가 더 큼
    if(p[a] == p[b]) p[a]--; //a rank 늘림

    p[b] = a;
}

void solve() {
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        uni(u, v);
    }

    cout << cnt + n - 1 - (m - cnt);    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}