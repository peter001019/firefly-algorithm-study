#include <bits/stdc++.h>
using namespace std;

int visited[52][52];
int arr[52][52];
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

void bfs(int y, int x, int w, int h)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    while (!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                continue;
            if (visited[ny][nx])
                continue;
            if (arr[ny][nx])
            {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
    return;
}

int main()
{
    while (true)
    {
        fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);

        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0)
        {
            break;
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> arr[i][j];
            }
        }

        int total = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (visited[i][j] == 0 && arr[i][j])
                {
                    total++;
                    bfs(i, j, w, h);
                }
            }
        }
        cout << total << '\n';
    }

    return 0;
}