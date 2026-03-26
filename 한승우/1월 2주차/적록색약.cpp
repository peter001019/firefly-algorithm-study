#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef long long ll;

/*
색맹이면 r과 G를 구분을 못한다.
*/

int n;
string mat[105];

int visited[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in_range(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void bfs(int r, int c){
    queue<pair<int, int>> q;

    visited[r][c] = 1;
    q.push({r, c});
    
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!in_range(nx, ny) || visited[nx][ny] || mat[x][y] != mat[nx][ny]) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> mat[i];

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 1) continue;
            bfs(i, j);
            cnt++;
        }
    }
    cout << cnt << ' ';

    cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(mat[i][j] == 'R' || mat[i][j] == 'G') mat[i][j] = 'X';
            
    for(int i = 0; i < n; i++)
        fill(visited[i], visited[i] + n, 0);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 1) continue;
            bfs(i, j);
            cnt++;
        }
    }
    cout << cnt << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}