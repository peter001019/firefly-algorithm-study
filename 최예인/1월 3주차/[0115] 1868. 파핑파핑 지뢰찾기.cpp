#include<iostream>
#include <string>
#include <queue>
 
#define X first
#define Y second
 
using namespace std;
 
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int da[4] = { 1, 0, -1, 0 };
int db[4] = { 0, 1, 0, -1 };
int vis[300][300];
string board[300];
int status[300][300];
 
int n;
 
bool checkBoundry(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }
    return true;
}
 
void fillNum() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') {
                int count = 0;
                for (int dir = 0; dir < 8; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (!checkBoundry(nx, ny)) {
                        continue;
                    }
                    if (board[nx][ny] == '*') {
                        count++;
                    }
                }
                status[i][j] = count;
            }
        }
    }
}
 
void debugStatus() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << status[i][j] << ' ';
        }
        cout << '\n';
    }
}
 
void debugVis() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
}
 
int dfsZero() {
    queue<pair<int, int>> Q;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (status[i][j] == 0&&vis[i][j]==-1) {
                Q.push({ i, j });
                vis[i][j] = count;
 
                while (!Q.empty()) {
                    pair<int, int> cursor = Q.front();
                    Q.pop();
 
                    for (int dir = 0; dir < 8; dir++) {
                        int nx = dx[dir] + cursor.X;
                        int ny = dy[dir] + cursor.Y;
 
                        if (!checkBoundry(nx, ny)) {
                            continue;
                        }
                        if (vis[nx][ny] != -1) {
                            continue;
                        }
                        if (status[nx][ny] == 0) {
                            Q.push({ nx, ny });
                        }
                        vis[nx][ny] = count;
                    }
                }
                count++;
            }
             
        }
    }
    return count;
 
}
 
int remain() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == -1 && board[i][j]=='.') {
                count++;
            }
        }
    }
    return count;
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin >> T;
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int sum = 0;
        cin >> n;
 
        // 입력
        for (int i = 0; i < n; i++) {
            cin >> board[i]; 
            for (int j = 0; j < n; j++) {
                status[i][j] = -1;
                vis[i][j] = -1;
            }
        }
 
        //debugStatus();
        //cout << '\n';
        // 칸에 모두 숫자 채우기
        fillNum();
        //cout << '\n';
        //debugStatus();
        //cout << '\n';
        //debugVis();
        sum+=dfsZero();
        //cout << '\n';
        //debugVis();
        sum+= remain();
         
        cout << '#' << test_case << ' ' << sum << '\n';
    }
    return 0;
}
