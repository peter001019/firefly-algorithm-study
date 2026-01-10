#include<iostream>
#include <queue>

using namespace std;

/*
클릭한 주변에 8개의 칸에 숫자 표시, 만약 0이라면 주변 숫자가 연쇄적으로 됨

지뢰가 있는 곳을 클릭하면 안됨.
최소 클릭 횟수 -> 그룹들을 나누어야 함.

숫자를 모두 표시하고.
BFS로 집단이 몇개 나오는가?
*/

int n;
string mat[305];
int cnt[305][305]; //-1이면 지뢰, 나머지는 지뢰 개수

//동남서북 오위 오아 왼아 왼위
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int visited[305][305];

bool in_range(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void bfs(int r, int c){
    queue<pair<int, int>> q;

    visited[r][c] = 1;
    if(cnt[r][c] == 0) q.push({r, c});

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!in_range(nx, ny) || visited[nx][ny] || mat[nx][ny] == '*') continue;
            visited[nx][ny] = 1;
            if(cnt[nx][ny] == 0) q.push({nx, ny}); //지뢰가 없을 때만 확장
        }
    }
}

//영역 세기
int sol(){
    int ans = 0;

    for(int i = 0; i < n; i++) fill(visited[i], visited[i] + n, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == '*' || visited[i][j] || cnt[i][j] != 0) continue;
            bfs(i, j);
            ans++;
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(mat[i][j] != '*' && !visited[i][j]) ans++;

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << cnt[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> mat[i];

        //숫자 세기
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != '*') continue;

                if(i > 0){
                    if(j > 0) cnt[i - 1][j - 1]++;
                    cnt[i - 1][j]++;
                    if(j < n - 1) cnt[i - 1][j + 1]++;
                }

                if(j > 0) cnt[i][j - 1]++;
                if(j < n - 1) cnt[i][j + 1]++;

                if(i < n - 1){
                    if(j > 0) cnt[i + 1][j - 1]++;
                    cnt[i + 1][j]++;
                    if(j < n - 1) cnt[i + 1][j + 1]++;
                }
            }
        }

        //지뢰는 -1로 표기
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] == '*') cnt[i][j] = -1;

        int result = sol();
        cout << '#' << test_case << ' ' << result << '\n';

        //초기화
        for(int i = 0; i < n; i++){
            fill(cnt[i], cnt[i] + n, 0);
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}