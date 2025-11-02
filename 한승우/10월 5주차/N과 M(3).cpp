#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> tmp;

void comb(int start){
    if(tmp.size() == m){
        for(int i: tmp) cout << i << ' ';
        cout << '\n';
        return;
    }

    for(int i = start; i <= n; i++){
        tmp.push_back(i);
        comb(start);
        tmp.pop_back();
    }
}

void solve() {
    cin >> n >> m;

    comb(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}