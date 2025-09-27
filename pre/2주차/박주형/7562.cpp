#include <bits/stdc++.h>
using namespace std;

int visited[302][302];
const int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int l, int y, int x, int ey, int ex)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 0;

    while (!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= l || nx < 0 || nx >= l)
                continue;
            if (visited[ny][nx] != -1)
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            if (ny == ey && nx == ex)
            {
                cout << visited[ny][nx] << '\n';
                return;
            }
            q.push({ny, nx});
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        fill(&visited[0][0], &visited[0][0] + 302 * 302, -1);

        int l;
        cin >> l;
        int sy, sx;
        cin >> sy >> sx;
        int ey, ex;
        cin >> ey >> ex;

        if (sy == ey && sx == ex)
        {
            cout << 0 << '\n';
        }
        else
        {
            bfs(l, sy, sx, ey, ex);
        }
    }

    return 0;
}
