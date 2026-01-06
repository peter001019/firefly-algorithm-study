#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
+로 쏘냐, X로 쏘냐 둘중에 큰것을 선택

30 * 225 * 2
*/

int n, m;
int mat[20][20];
int cnt = 1;

void solve() {
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int sum = 0;

            int st = (j - m + 1 >= 0) ? j - m + 1 : 0;
            int en = (j + m - 1 < n) ? j + m - 1 : n - 1;
            for(int k = st; k <= en; k++) {
                sum += mat[i][k];
                sum += mat[k][j];
            }
            sum -= mat[i][j];

            ans = max(ans, sum);

            sum = 0;
            st = (i - m + 1 >= 0) ? i - m + 1 : 0;
            en = (i + m - 1 < n) ? i + m - 1 : n - 1;

            for(int k = st; k <= en; k++) {
                sum += mat[k][k];
                sum += mat[st + en - k][k];
            }
            sum -= mat[i][j];
            
            ans = max(ans, sum);
        }
    
    cout << '#' << cnt++ << ' ' << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    cin >> Tc;
    while (Tc--) solve();
    return 0;
}