#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[2][100005];

void solve() {
    int n; cin >> n;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            cin >> dp[i][j];
    
    dp[0][1] += dp[1][0];
    dp[1][1] += dp[0][0];
    for(int i = 2; i < n; i++){
        int tmp = max(dp[0][i - 2], dp[1][i - 2]);
        dp[0][i] += max(tmp, dp[1][i - 1]);
        dp[1][i] += max(tmp, dp[0][i - 1]);
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    cin >> Tc;
    while (Tc--) solve();
    return 0;
}