#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, ans;
int mat[20][20];

//오른쪽, 대각선, 아래
vector<int> dx[3] = {
    {0, 1, 100},
    {0, 1, 1},
    {100, 1, 1}
};

vector<int> dy[3] = {
    {1, 1, 100},
    {1, 1, 0},
    {100, 1, 0}
};

bool in_range(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

//방향, 위치
void dfs(int d, int x, int y){
    if(x == n && y == n){
        ans++;
        return;
    }

    for(int i = 0; i < dx[d].size(); i++){
        int nx = x + dx[d][i];
        int ny = y + dy[d][i];

        if(!in_range(nx, ny) || mat[nx][ny] == 1) continue;
        if(i == 1 && (mat[nx - 1][ny] == 1 || mat[nx][ny - 1] == 1)) continue; //대각선으로 옮겼을 때 벽있는 경우 

        dfs(i, nx, ny);
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> mat[i][j];

    dfs(0, 1, 2);

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