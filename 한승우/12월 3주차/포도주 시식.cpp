#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
연속 3잔을 마실 수 없음. 가장 많은 양을 선택
-> 다 시도 해봐야 함. dp로 해결 
*/

int glass[10005];
int dp[10005];

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> glass[i];

    dp[0] = glass[0];
    dp[1] = glass[0] + glass[1];
    dp[2] = max(glass[1] + glass[2], glass[0] + glass[2]);
    dp[2] = max(dp[2], dp[1]);

    for(int i = 3; i < n; i++){
        dp[i] = max(dp[i - 2] + glass[i], dp[i - 3] + glass[i - 1] + glass[i]);
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}