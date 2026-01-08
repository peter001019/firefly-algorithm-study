#include<iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int board[15][15];
int times[15][15];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, - 1 };
int n;
int start_x, start_y, arrive_x, arrive_y;

void debug() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<< board[i][j]<<' ';
		}
		cout << '\n';
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int answer = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				times[i][j] = -1;
			}
		}
		cin>> start_x>> start_y>> arrive_x>>arrive_y;
		queue <pair<int, int>>Q;
		Q.push({ start_x, start_y });
		times[start_x][start_y] = 0;
		

		while (!Q.empty()) {
			pair<int, int> cursor = Q.front();
			Q.pop();
			
			if (cursor.X == arrive_x && cursor.Y == arrive_y) {
				answer = times[cursor.X][cursor.Y];
				break;
			}

			/*if (board[cursor.X][cursor.Y] == 2) {
				time[cursor.X][cursor.Y] += 2;
			}*/

			for (int dir = 0; dir < 4; dir++) {
				int nx = dx[dir] + cursor.X;
				int ny = dy[dir] + cursor.Y;

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
					continue;
				}
				if (board[nx][ny] == 1) {
					continue;
				}

				int wtime = 0;
				if (board[nx][ny] == 2){
					int curtime = times[cursor.X][cursor.Y];
					if (curtime % 3 == 0) {
						wtime = 2;
					}
					else if (curtime % 3 == 1) {
						wtime = 1;
					}
					else {
						wtime = 0;
					}
				}
				int next = times[cursor.X][cursor.Y] + wtime + 1;
				if (times[nx][ny] == -1 || times[nx][ny] > next) {
					times[nx][ny] = next;
					Q.push({ nx, ny });
				}				
			}
		}
		cout << '#' << test_case << ' ' << answer << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
