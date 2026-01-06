#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int k;
int s[15];

vector<int> v;
void comb(int idx, int cnt){
    if(cnt == 6){
        for(auto i: v) cout << i << ' ';
        cout << '\n';
        return;
    }

    for(int i = idx; i < k; i++){
        v.push_back(s[i]);
        comb(i + 1, cnt + 1);
        v.pop_back();
    }
}

bool solve() {
    cin >> k;
    if(k == 0) return 0;

    for(int i = 0; i < k; i++) cin >> s[i];

    comb(0, 0);
    cout << '\n';

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;

    bool flag = true;
    while (flag){
        flag = solve();
    }
    return 0;
}