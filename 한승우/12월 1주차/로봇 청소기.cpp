#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
현재 칸 청소

주변 4칸 중 다 청소임 -> 후진(or stop) 
청소 칸 있으면 -> 왼쪽 회전 후 직진
*/

int n, m, r, c, d;
int mat[52][52];

//북 동 남 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    int answer = 0;

    cin >> n >> m >> r >> c >> d;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    while(1){
        //현재 위치 청소
        if(mat[r][c] == 0) {
            mat[r][c] = -1;
            answer++;
        }

        //주변에 청소할 곳이 있는지? 있다면 전진
        bool cleaned = 0;

        for(int i = 0; i < 4; i++){
            d = (d + 3) % 4;
            int nr = r + dx[d];
            int nc = c + dy[d];

            if(mat[nr][nc] == 0) {
                cleaned = 1;
                r = nr;
                c = nc;
                break;
            }
        }

        //청소할 곳이 없다면
        if(!cleaned){
            if(mat[r - dx[d]][c - dy[d]] == 1) break;
            r -= dx[d];
            c -= dy[d];
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << clean[i][j];
    //     }
    //     cout << '\n';
    // }  
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}