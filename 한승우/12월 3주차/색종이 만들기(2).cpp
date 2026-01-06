#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
재귀

정의 : 잘라진 부분이 하얀색인지 파란색인지 판별한다.

base condition -> n이 1이면 색깔을 반환
각 4개가 모두 색이 같다면 해당 색깔 추가
*/

int n;
int mat[150][150];
int ans[2]; //w, b

int sol(int len, int r, int c){
    if(len == 1){
        return mat[r][c];
    }

    int half = len / 2;
    int one = sol(half, r, c);
    int two = sol(half, r, c + half);
    int three = sol(half, r + half, c);
    int four = sol(half, r + half, c + half);

    if(one != -1 && one == two && two == three && three == four){
        return mat[r][c];
    } else {
        if(one != -1) ans[one]++;
        if(two != -1) ans[two]++;
        if(three != -1) ans[three]++;
        if(four != -1) ans[four]++;
        return -1;
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    int result = sol(n, 0, 0);
    if(result != -1) ans[result]++;

    for(int i = 0; i < 2; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}