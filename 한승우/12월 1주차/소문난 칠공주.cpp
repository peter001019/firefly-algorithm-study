#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
25C7 * 25

뽑는건 알겠는데, 인접한 요소인지는 어떻게 확인하지?
*/

int answer;
string mat[7];
string tmp[7];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in_range(int x, int y){
    return 0 <= x && x < 5 && 0 <= y && y < 5;
}

void solve() {
    vector<int> mask(25);
    fill(mask.end() - 7, mask.end(), 1);
    do{
        for(int i = 0; i < 5; i++) tmp[i] = ".....";

        int sx = -1, sy = -1;
        int scnt = 0;

        for(int i = 0; i < 25; i++){
            int r = i / 5, c = i % 5;
            if(mask[i]) {
                if(sx == -1){
                    sx = r;
                    sy = c;
                }
                tmp[r][c] = mat[r][c];
                if(tmp[r][c] == 'S') scnt++;
            }
        }

        if(scnt < 4) continue;

        //bfs
        queue<pair<int, int>> q;
        vector<vector<int>> visited(5, vector<int>(5));
        int cnt = 1;
        visited[sx][sy] = 1;
        q.push({sx, sy});

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(!in_range(nx, ny) || tmp[nx][ny] == '.' || visited[nx][ny]) continue;
                cnt++;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }

        if(cnt == 7) answer++;

    }while(next_permutation(mask.begin(), mask.end()));

    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 5; i++)
        cin >> mat[i];

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}