#include<iostream>
#include <string>
#include <queue>

#define X first
#define Y second

using namespace std;

string board[100];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int vis[100][100];

bool checkBoundry(int i, int j)
{
	if (i<0 || i>=n || j<0 || j>=n)
	{
		return true;
	}
	return false;
}

int origin()
{
	queue<pair<int, int>>Q;
	int count = 1;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (vis[i][j]==-1)
			{
				Q.push({i,j});
				vis[i][j] = count;
				while (!Q.empty())
				{
					pair<int, int> cursor = Q.front();
					Q.pop();

					for (int dir = 0;dir<4;dir++)
					{
						int nx = cursor.X + dx[dir];
						int ny = cursor.Y + dy[dir];

						if (checkBoundry(nx, ny))
						{
							continue;
						}
						if (board[nx][ny]!=board[cursor.X][cursor.Y]||vis[nx][ny]!=-1)
						{
							continue;
						}
						vis[nx][ny] = count;
						Q.push({nx, ny});
					}
				}
				count++;
			}

		}

	}
	return count;
}

void change()
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (board[i][j]=='G')
			{
				board[i][j] = 'R';
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>board[i];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			vis[i][j] = -1;
		}
	}

	//일반 사람
	cout<<origin()-1<<' ';
	change();
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			vis[i][j] = -1;
		}
	}
	cout<<origin()-1;


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

