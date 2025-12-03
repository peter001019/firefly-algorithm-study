#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, w, l;
    cin >> n >> w >> l;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    queue<int> q;
    int idx = 0;
    int answer = 0;

    while(idx < n){
        if(q.size() == w) {
            l += q.front();
            q.pop();
        }

        if(l - a[idx] < 0) q.push(0);
        else{
            q.push(a[idx]);
            l -= a[idx];
            idx++;
        }  

        answer++;
    }
    answer += w;

    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}