#include<iostream>

using namespace std;
int board[15][15];
int n,m;

int calPlus(int i, int j)
{
	int sum = 0;
	//4방향 합 구하기
	for (int k=1;k<m;k++)
	{
		if ((i-k)>=0) // 위
		{
			sum = sum + board[i-k][j];
		}

		if ((i+k)<n) // 아래
		{
			sum = sum + board[i+k][j];
		}

		if ((j-k)>=0) // 왼
		{
			sum = sum + board[i][j-k];
		}

		if ((j+k)<n) // 우
		{
			sum = sum + board[i][j+k];
		}

	}
	return sum+board[i][j];

}

int calMul(int i, int j)
{
	int sum = 0;
	//4방향 합 구하기
	for (int k=1;k<m;k++) // 왼오 --
	{
		if ((i-k)>=0 && (j-k)>=0)
		{
			sum = sum + board[i-k][j-k];
		}

		if ((i-k)>=0 && (j+k)<n) // 우오 -+
		{
			sum = sum + board[i-k][j+k];
		}

		if ((i+k)<n && (j-k)>=0) // 왼아 +-
		{
			sum = sum + board[i+k][j-k];
		}

		if ((i+k)<n && (j+k)<n) // 우아 ++
		{
			sum = sum + board[i+k][j+k];
		}

	}
	return sum+board[i][j];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n>>m;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				cin>>board[i][j];
			}
		}
		int maxN = 0;

		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				maxN = max(maxN, calPlus(i,j));
				maxN = max(maxN, calMul(i,j));
			}
		}
		cout<<'#'<<test_case<<' '<<maxN<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
