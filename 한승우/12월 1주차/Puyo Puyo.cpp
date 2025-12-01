#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;

/*
1. 뿌요들을 터뜨린다.(BFS, 개수를 세고, 조건에 맞다면 삭제)
2. 중력에 의해 뿌요들을 내린다.
*/

int n = 12, m = 6;
string mat[15];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in_range(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool bomb(pair<int, int> st){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<pair<int, int>> locs;

    visited[st.X][st.Y] = 1;
    q.push(st);
    locs.push_back(st);
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!in_range(nx, ny) || visited[nx][ny]) continue;
            if(mat[nx][ny] != mat[x][y]) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
            locs.push_back({nx, ny});
        }
    }

    if(locs.size() >= 4){
        for(const auto l: locs) mat[l.X][l.Y] = '.';
        return 1;
    }

    return 0;
}

void solve() {
    int answer = 0;

    for(int i = n - 1; i >= 0; i--)
        cin >> mat[i];
    
    while(1){
        //터뜨리기
        bool is_bombed = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == '.') continue;
                if(bomb({i, j})) is_bombed = 1;
            }
        }
        if(!is_bombed) break;

        //중력 처리
        vector<string> tmp(n, "......");
        for(int c = 0; c < m; c++){
            int idx = 0;
            for(int r = 0; r < n; r++){
                if(mat[r][c] == '.') continue;
                tmp[idx++][c] = mat[r][c];
            }
        }

        for(int r = 0; r < n; r++)
            for(int c = 0; c < m; c++)
                mat[r][c] = tmp[r][c];

        answer++;          
    }

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