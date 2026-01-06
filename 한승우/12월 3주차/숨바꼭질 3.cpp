#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

typedef long long ll;

const int MAX = 100'000;
const int INF = 1e9;

int n, k;

void solve() {
    cin >> n >> k;

    vector<int> d(MAX + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //가중치, 정점
    d[n] = 0;
    pq.push({0, n});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();

        if(cur.X != d[cur.Y]) continue;

        if(cur.Y * 2 <= MAX && d[cur.Y * 2] > cur.X){
            d[cur.Y * 2] = cur.X;
            pq.push({d[cur.Y * 2], cur.Y * 2});
        }

        if(cur.Y + 1 <= MAX && d[cur.Y + 1] > cur.X + 1){
            d[cur.Y + 1] = cur.X + 1;
            pq.push({d[cur.Y + 1], cur.Y + 1});
        }

        if(cur.Y - 1 >= 0 && d[cur.Y - 1] > cur.X + 1){
            d[cur.Y - 1] = cur.X + 1;
            pq.push({d[cur.Y - 1], cur.Y - 1});
        }
    }

    cout << d[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}