#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<vector<char>> mapV;
vector<vector<bool>> visited;
stack<pair<int, int>> s;

int answer = 0;
int answerRG = 0;

void dfs(int cx, int cy, int N, bool rg)
{
    visited[cx][cy] = true;
    char currentC = mapV[cx][cy];

    for (int i = 0; i < 4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        // 이미 방문한 칸이면 패스
        if (visited[nx][ny])
            continue;

        if (rg == true)
        {
            if ((currentC == 'R' || currentC == 'G') && (mapV[nx][ny] == 'R' || mapV[nx][ny] == 'G'))
            {
                dfs(nx, ny, N, rg);
            }
            else if (mapV[nx][ny] == currentC)
            {
                dfs(nx, ny, N, rg);
            }
            else
            {
                s.push({nx, ny});
            }
        }
        else
        {
            if (mapV[nx][ny] == currentC)
            {
                dfs(nx, ny, N, rg);
            }
            else
            {
                s.push({nx, ny});
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    mapV.assign(N, vector<char>(N));
    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> mapV[i][j];

    s.push({0, 0});

    while (!s.empty())
    {
        auto [cx, cy] = s.top();
        s.pop();

        if (!visited[cx][cy])
        {
            answer++;
            dfs(cx, cy, N, false);
        }
    }

    s.push({0, 0});

    visited.assign(N, vector<bool>(N, false));

    while (!s.empty())
    {
        auto [cx, cy] = s.top();
        s.pop();

        if (!visited[cx][cy])
        {
            answerRG++;
            dfs(cx, cy, N, true);
        }
    }

    cout << answer << " " << answerRG << endl;
    return 0;
}
