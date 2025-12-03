#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
모든 경우 고려 * (맵 만들기 * 회전 + BFS)

4^5 * (5! * 25 + 125) = 10^6

1. 미로의 회전하는 경우의 수 고려.
2. 미로의 순열 
3. 미로를 탐색한다.
*/

int answer = 1e9;

int input[7][7][7];
int mat[7][7][7];
int dist[7][7][7];

int dx[] = {0, 0,  0,  0, 1, -1};
int dy[] = {0, 1,  0, -1, 0,  0};
int dz[] = {1, 0, -1,  0, 0,  0};

bool in_range(int x, int y, int z){
    return 0 <= x && x < 5 && 0 <= y && y < 5 && 0 <= z && z < 5;
}

struct Loc {
    int x, y, z;
};

int bfs(){
    if(mat[0][0][0] == 0 || mat[4][4][4] == 0) return -1;

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            fill(dist[i][j], dist[i][j] + 5, -1);

    queue<Loc> q;

    dist[0][0][0] = 0;
    q.push({0, 0, 0});
    while(!q.empty()){
        auto [x, y, z] = q.front(); q.pop();

        if(x == 4 && y == 4 && z == 4) break;

        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(!in_range(nx, ny, nz) || mat[nx][ny][nz] == 0 || dist[nx][ny][nz] >= 0) continue; 
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }

    return dist[4][4][4];
}

//시계 방향으로 회전
void rotate(int z){
    vector<vector<int>> tmp(5, vector<int>(5));

    for(int r = 0; r < 5; r++)
        for(int c = 0; c < 5; c++)
            tmp[4 - c][r] = mat[z][r][c];

    for(int r = 0; r < 5; r++)
        for(int c = 0; c < 5; c++)
            mat[z][r][c] = tmp[r][c];
}

void dfs(int idx){
    if(idx == 5){
        int result = bfs();

        if(result != -1)
            answer = min(answer, result);

        return;
    }

    for(int i = 0; i < 4; i++){
        dfs(idx + 1);
        rotate(idx);
    }
}

void solve() {
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                cin >> input[i][j][k];

    vector<int> order = {0, 1, 2, 3, 4};
    do {
        //판 순서 재배치
        for(int i = 0; i < 5; i++){
            for(int r = 0; r < 5; r++)
                for(int c = 0; c < 5; c++)
                    mat[i][r][c] = input[order[i]][r][c];
        }

        dfs(0);

        //초기화
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                fill(mat[i][j], mat[i][j] + 5, 0);

    } while(next_permutation(order.begin(), order.end()));

    if(answer == 1e9) answer = -1;
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