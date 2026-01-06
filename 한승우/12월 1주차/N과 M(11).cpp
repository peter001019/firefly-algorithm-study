#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
int check[10002];
vector<int> num;

vector<int> v;
void backtracking(int cnt){
    if(cnt == m){
        for(auto i: v) cout << i << ' ';
        cout << '\n';
        return;
    }

    for(auto i: num){
        v.push_back(i);
        backtracking(cnt + 1);
        v.pop_back();
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;

        if(check[tmp]) continue;
        check[tmp] = 1;
        num.push_back(tmp);
    }

    sort(num.begin(), num.end());
    backtracking(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}