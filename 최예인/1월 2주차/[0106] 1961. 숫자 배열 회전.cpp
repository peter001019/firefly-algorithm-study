#include<iostream>

using namespace std;
int board[7][7];
int board2[7][7];
int board3[7][7];
int board4[7][7];
int n;

void turn90()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board2[j][n-i-1] = board[i][j];
		}

	}
}

void turn180()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board3[j][n-i-1] = board2[i][j];
		}

	}
}

void turn270()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board4[j][n-i-1] = board3[i][j];
		}

	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				cin>>board[i][j];
			}
		}

		cout<<'#'<<test_case<<'\n';
		turn90();
		turn180();
		turn270();

		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				cout<<board2[i][j];
			}
			cout<<' ';
			for (int j=0;j<n;j++)
			{
				cout<<board3[i][j];
			}
			cout<<' ';
			for (int j=0;j<n;j++)
			{
				cout<<board4[i][j];
			}
			cout<<'\n';
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
