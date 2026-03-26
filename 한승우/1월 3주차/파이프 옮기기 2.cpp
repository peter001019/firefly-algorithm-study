#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int mat[35][35];

//오른쪽, 대각선, 아래
int dp[3][35][35];

int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};

bool in_range(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> mat[i][j];

    for(int d = 0; d < 3; d++)
        for(int i = 1; i <= n; i++)
            fill(dp[d][i] + 1, dp[d][i] + n + 1, 1e9);

    dp[0][1][2] = 0;
    for(int d = 0; d < 3; d++){
        for(int i = 1; i <= n; i++){
            for(int j = 2; j <= n; j++){
                if(!in_range(i - dx[d], j - dy[d])) continue;
                if(mat[i][j] == 1) continue; //이동한 곳이 벽
                if(d == 1 && (mat[i - 1][j] == 1 || mat[i][j - 1] == 1)) continue; //대각선으로 이동할 수 없음

                //오른쪽
                if(d == 0){
                    if(dp[0][i][j - 1] < 1e9) dp[d][i][j] += dp[0][i][j - 1] + 1;
                    if(dp[1][i - 1][j - 1] < 1e9) dp[d][i][j] += dp[1][i - 1][j - 1] + 1;
                } 
                //대각선
                else if(d == 1){
                    if(dp[0][i][j - 1] < 1e9) dp[d][i][j] += dp[0][i][j - 1] + 1;
                    if(dp[1][i - 1][j - 1] < 1e9) dp[d][i][j] += dp[1][i - 1][j - 1] + 1;
                    if(dp[2][i - 1][j] < 1e9) dp[d][i][j] += dp[2][i - 1][j] + 1;
                }
                else {
                    if(dp[1][i - 1][j - 1] < 1e9) dp[d][i][j] += dp[1][i - 1][j - 1] + 1;
                    if(dp[2][i - 1][j] < 1e9) dp[d][i][j] += dp[2][i - 1][j] + 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 3; i++){
        if(dp[i][n][n] < 1e9) ans += dp[i][n][n];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}