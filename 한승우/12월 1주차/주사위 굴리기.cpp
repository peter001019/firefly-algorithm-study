#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
1. 주사위를 굴린다. (동서남북)
2. 지도와 주사위 사이의 숫자를 이동
*/

int n, m, x, y;
int dice[5][5];
int mat[25][25];

//동서북남
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

bool in_range(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void roll(int dir){
    int tmp;

    if(dir == 1){
        tmp = dice[2][3];
        for(int i = 3; i >= 2; i--) dice[2][i] = dice[2][i - 1];
        dice[2][1] = dice[4][2];
        dice[4][2] = tmp;
    } else if(dir == 2){
        tmp = dice[2][1];
        for(int i = 1; i <= 2; i++) dice[2][i] = dice[2][i + 1];
        dice[2][3] = dice[4][2];
        dice[4][2] = tmp;
    } else if(dir == 3){
        tmp = dice[1][2];
        for(int i = 1; i <= 3; i++) dice[i][2] = dice[i + 1][2];
        dice[4][2] = tmp;
    } else{
        tmp = dice[4][2];
        for(int i = 4; i >= 2; i--) dice[i][2] = dice[i - 1][2];
        dice[1][2] = tmp;
    }
}

void solve() {
    int dir;
    cin >> dir;

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(!in_range(nx, ny)) return;
    
    x = nx;
    y = ny;
    roll(dir);
    if(mat[x][y] == 0) mat[x][y] = dice[4][2];
    else{
        dice[4][2] = mat[x][y];
        mat[x][y] = 0;
    }

    cout << dice[2][2] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> n >> m >> x >> y >> k;
    x++; y++;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mat[i][j];

    while (k--) solve();
    return 0;
}