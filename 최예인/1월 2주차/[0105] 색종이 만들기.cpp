#include <iostream>

using namespace std;

int white = 0;
int blue = 0;
int board[128][128];

void cut(int x, int y, int n)
{
    int color = board[x][y];
    int half = n/2;
    for (int i=x;i<x+n;i++)
    {
        for (int j=y;j<y+n;j++)
        {
            if (color != board[i][j])
            {
                cut(x, y, half);
                cut(x,y+half,half);
                cut(x+half, y, half);
                cut(x+half, y+half, half);
                return;
            }
        }
    }
    if (color==0)
    {
        white ++;
    }else
    {
        blue ++;
    }


}

int main()
{
    int N;
    cin >> N;

    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }

    cut(0, 0, N);
    cout<<white<<'\n'<<blue;

}
